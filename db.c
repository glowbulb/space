#define _GNU_SOURCE
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"

struct monsters_t monsters[5] = {
    {"dragon",10,5,5},
    {"fairy",5,10,10},
    {"turtle",2,20,20},
    {"mushroom",1,25,25},
    {"skelly",7,15,15}
};

int main(int argc, char **argv) {


//    struct monsters_t *e = malloc(sizeof(int));
//    e = (realloc(e - 8, ((i + 1) * sizeof(struct monsters_t)) + 8) + 8);

//    e = realloc(e, (5 * sizeof(struct monsters_t)) + 8);
//    memcpy(e + 8, &monsters, 5 * sizeof(struct monsters_t));
//    store_length(e + 8, 5);
//    int rekt = get_length(e + 8);
//    printf("%d", rekt);


//    db_query(db_queue_three(db_create_monsters(), db_insert_monsters(monsters, 5), db_select_table("monsters")));

    struct monsters_t *result = db_select_monsters(db_select_table("monsters"));

    monsters_print(result);
    
    return 0;
}