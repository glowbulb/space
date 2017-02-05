#define _GNU_SOURCE
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

sqlite3 *db;
char *err_msg = 0;

int db_callback(void *a, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i]);
    }
    return 0;
}

void db_query(char *q) {
    sqlite3_open("", &db);
    sqlite3_exec(db, q, db_callback, 0, &err_msg);
    sqlite3_close(db);
}

char * db_create_table(char *a, char *b, char *c, char *d, char *e){
    char *create_table = sqlite3_mprintf("CREATE TABLE %s(%s TEXT, %s INT, %s INT, %s INT);",a,b,c,d,e);
    return create_table;
}

char * db_insert_row(char *a, char *b, int c, int d, int e){
    char *insert_row = sqlite3_mprintf("INSERT INTO %s VALUES(%s, %d, %d, %d);",a,b,c,d,e);
    return insert_row;
}

char * db_select_table(char *a){
    char *select_table = sqlite3_mprintf("SELECT * FROM %s;",a);
    return select_table;
}