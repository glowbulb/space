#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

typedef struct db_string_t {
    char s[999];
    int l[1];
} db_string_t;

sqlite3 *db;
db_string_t db_result;
char *err_msg = 0;

db_string_t db_append_char_array_f(db_string_t a, db_string_t b) {
    char y[99];
    strcpy(y, a.s);
    strcat(y, b.s);
    db_string_t n = { .l = { 999 } };
    for( int i = 0; i < 20; i = i + 1 ){
        n.s[i] = y[i];
    }
    return n;
}

int db_callback(void *a, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        db_string_t n = { .s = { argv[i] } };
        db_result = db_append_char_array_f(db_result, n);
        printf("%s", db_result.s);
    }
    return 0;
}

db_string_t db_query(char *q) {
    sqlite3_open(":memory:", &db);
    sqlite3_exec(db, q, db_callback, 0, &err_msg);
    sqlite3_close(db);
    return db_result;
}

void db_print_string_f(db_string_t a){
    printf("%s", a.s);
}