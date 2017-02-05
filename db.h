#define _GNU_SOURCE
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

sqlite3 *db;
char *err_msg = 0;

struct monsters_t {
    char *name;
    int life;
    int xpos;
    int ypos;
};

int db_callback(void *a, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i]);
    }
    return 0;
}

void db_query(char *q) {
    sqlite3_open(":memory:", &db);
    sqlite3_exec(db, q, db_callback, 0, &err_msg);
    sqlite3_close(db);
}

char * db_insert_monsters(struct monsters_t a[]){
    char *x = "";
    for (int i = 0; i < 5; i++) {
        char *z;
        asprintf(&z,"INSERT INTO monsters VALUES(%s, %d, %d, %d);",a[i].name,a[i].life,a[i].xpos,a[i].ypos);
        asprintf(&x,"%s%s\n",x,z);
    }
    char *insert_row = sqlite3_mprintf("%s",x);
    return insert_row;
}

char * db_queue_two(char *a, char *b){
    char *z;
    asprintf(&z,"%s%s",a,b);
    char *db_queue = sqlite3_mprintf("%s",z);
    return db_queue;
}

char * db_queue_three(char *a, char *b, char *c){
    char *z;
    asprintf(&z,"%s%s%s",a,b,c);
    char *db_queue = sqlite3_mprintf("%s",z);
    return db_queue;
}

char * db_create_table(char *a, char *b, char *c, char *d, char *e){
    char *z;
    asprintf(&z,"CREATE TABLE %s(%s TEXT, %s INT, %s INT, %s INT);",a,b,c,d,e);
    char *create_table = sqlite3_mprintf("%s",z);
    return create_table;
}

char * db_insert_row(char *a, char *b, int c, int d, int e){
    char *z;
    asprintf(&z,"INSERT INTO %s VALUES(%s, %d, %d, %d);",a,b,c,d,e);
    char *insert_row = sqlite3_mprintf("%s",z);
    return insert_row;
}

char * db_select_table(char *a){
    char *z;
    asprintf(&z,"SELECT * FROM %s;",a);
    char *select_table = sqlite3_mprintf("%s",z);
    return select_table;
}