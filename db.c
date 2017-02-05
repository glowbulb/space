#define _GNU_SOURCE
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"
#include "ltb.h"

struct monsters_t monsters[5] = {
    {"dragon",10,5,5},
    {"fairy",5,10,10},
    {"turtle",2,20,20},
    {"mushroom",1,25,25},
    {"skelly",7,15,15}
};

int main(int argc, char **argv) {

//    ltb_foreach(struct enemy_t *v, enemies) { printf("%s\n", v[0].name); }
    
    
    // db_query(db_queue_three(
    //     db_create_table("monsters","name","life","xpos","ypos"),
    //     db_insert_row("monsters","'dragon'",10,5,5),
    //     db_select_table("monsters")));

    db_query(db_insert_monsters(monsters));

    
    return 0;

}