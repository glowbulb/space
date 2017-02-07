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

void monsters_print(struct monsters_t *a, int b){
    for (int i = 0; i < b; i++) {
        printf("%s %d %d %d\n", a[i].name, a[i].life, a[i].xpos, a[i].ypos);
    }
}

void monster_print(struct monsters_t a){
    printf("%s %d %d %d\n", a.name, a.life, a.xpos, a.ypos);
}

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

struct monsters_t * db_select_monsters(char *a){
    char *s;
    asprintf(&s, "select rowid from monsters order by rowid desc limit 1;");
    sqlite3_stmt *r;
    sqlite3_stmt *v;
    char *z;
    static struct monsters_t b[2];
    sqlite3_open("sqlite.db", &db);
    sqlite3_prepare_v2(db, s, -1, &v, 0);
    sqlite3_step(v);
    printf("%d", sqlite3_column_int(r,0));
    sqlite3_finalize(v);
    sqlite3_prepare_v2(db, a, -1, &r, 0);
    for (int i = 0; i < 2; i++) {
        sqlite3_step(r);
        asprintf(&z, "%s", sqlite3_column_text(r, 0));
        b[i].name = z;
        b[i].life = sqlite3_column_int(r,1);
        b[i].xpos = sqlite3_column_int(r,2);
        b[i].ypos = sqlite3_column_int(r,3);
        z = 0;
    }
    sqlite3_finalize(r);
    sqlite3_close(db);
    return b;
}

char * db_insert_monsters(struct monsters_t a[], int b){
    char *x = "";
    for (int i = 0; i < b; i++) {
        char *z;
        asprintf(&z,"INSERT INTO monsters VALUES('%s', %d, %d, %d);", a[i].name, a[i].life, a[i].xpos, a[i].ypos);
        asprintf(&x,"%s%s", x, z);
        free(z);
    }
    return x;
}

char * db_create_monsters(){
    char *z;
    asprintf(&z,"CREATE TABLE monsters(name TEXT, life INT, xpos INT, ypos INT);");
    return z;
}

char * db_queue_two(char *a, char *b){
    char *z;
    asprintf(&z,"%s%s",a,b);
    return z;
}

char * db_queue_three(char *a, char *b, char *c){
    char *z;
    asprintf(&z,"%s%s%s",a,b,c);
    return z;
}

char * db_create_table(char *a, char *b, char *c, char *d, char *e){
    char *z;
    asprintf(&z,"CREATE TABLE %s(%s TEXT, %s INT, %s INT, %s INT);", a, b, c, d, e);
    return z;
}

char * db_insert_row(char *a, char *b, int c, int d, int e){
    char *z;
    asprintf(&z,"INSERT INTO %s VALUES(%s, %d, %d, %d);", a, b, c, d, e);
    return z;
}

char * db_select_table(char *a){
    char *z;
    asprintf(&z,"SELECT * FROM %s;", a);
    return z;
}