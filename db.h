#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include <sds.h>
#include <sb.h>

sqlite3 *db;
sds db_result;
char *err_msg = 0;
db_result.s = sdsnew("rekt");

sds mystring = sdsnew("Hello World!");
printf("%s\n", mystring);
sdsfree(mystring);

int db_callback(void *a, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
//        db_result.s = sdscatprintf(db_result.s,"%s",argv[i]);
        printf("%s", db_result.s);
    }
    return 0;
}

sds db_query(sds q) {
    sqlite3_open(":memory:", &db);
    sqlite3_exec(db, q, db_callback, 0, &err_msg);
    sqlite3_close(db);
    return db_result;
}