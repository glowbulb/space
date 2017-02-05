#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include <sds.h>
#include <sb.h>
#include "db.h"

int main(void) {

    char *rekt = "rekt";

    char *sql = sqlite3_mprintf(
        "CREATE TABLE Cars(Id INT, Name TEXT, Price INT);" 
        "INSERT INTO Cars VALUES(1, 'Audi', 52642);" 
        "INSERT INTO Cars VALUES(2, 'Mercedes', 57127);" 
        "INSERT INTO Cars VALUES(3, 'Skoda', 9000);" 
        "INSERT INTO Cars VALUES(4, 'Volvo', 29000);" 
        "INSERT INTO Cars VALUES(5, 'Bentley', 350000);" 
        "INSERT INTO Cars VALUES(6, 'Citroen', 21000);" 
        "INSERT INTO Cars VALUES(7, '%q', 41400);" 
        "INSERT INTO Cars VALUES(8, '%q', 21600);"
        "SELECT * FROM CARS;", rekt, rekt);

    db_query(sql);
    printf("%s", db_result.s);
    return 0;

}