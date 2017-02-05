#define _GNU_SOURCE
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"
#include "ltb.h"

struct enemy_t {
    char *name;
    int life;
    int xpos;
    int ypos;
};

struct enemy_t enemies[5] = {
    {"dragon",10,5,5},
    {"fairy",5,10,10},
    {"turtle",2,20,20},
    {"mushroom",1,25,25},
    {"skelly",7,15,15}
};

int main(int argc, char **argv) {

    ltb_foreach(struct enemy_t *v, enemies) {
        printf("%s\n", v[0].name);
    }

    db_query(db_create_table("enemies","name","life","xpos","ypos"));
    db_query(db_insert_row("enemies","dragon",10,5,5));
    db_query(db_select_table("enemies"));
//    sqlite3_free(query);
    return 0;

}