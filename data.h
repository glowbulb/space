#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include "sb.h"
#include "db.h"



enemy_t *enemies = NULL;

enemy_t dragon = { .life { 20 }, .name { 'dragon' }, .xpos { 0 }, .ypos { 0 } };
enemy_t fairie = { .life { 20 }, .name { 'fairie' }, .xpos { 0 }, .ypos { 0 } };
enemy_t mushroom = { .life { 20 }, .name { 'mushroom' }, .xpos { 0 }, .ypos { 0 } };
enemy_t turtle = { .life { 20 }, .name { 'turtle' }, .xpos { 0 }, .ypos { 0 } };
enemy_t goomba = { .life { 20 }, .name { 'goomba' }, .xpos { 0 }, .ypos { 0 } };
enemy_t star = { .life { 20 }, .name { 'star' }, .xpos { 0 }, .ypos { 0 } };
enemy_t moon = { .life { 20 }, .name { 'moon' }, .xpos { 0 }, .ypos { 0 } };
enemy_t skelly = { .life { 20 }, .name { 'skelly' }, .xpos { 0 }, .ypos { 0 } };
enemy_t yomamma = { .life { 20 }, .name { 'yomamma' }, .xpos { 0 }, .ypos { 0 } };

