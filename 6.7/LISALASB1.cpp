#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include "home.h"
#include <fstream>



#define NO_OF_LINES 24


int main(int argc, char const* argv[])
{

    FILE* output;

    FILE* input = fopen("home.csv", "r");
    if (input == NULL)
    {
        printf("error: file read");
        return 1;
    }
   
    home** db = nullptr;
    memory(db, NO_OF_LINES);
    open(input, db);

    for (int i = 0; i < NO_OF_LINES; i++) {

        db[i]->print();

    }



    printf("\nenter id: ");
    char str[10] = {};
    char ad[10] = {};
    char tele[10] = {};
    int ar=0;
    int rom=0 ;
    int cst=0 ;
    scanf("%s", str);

    find_id(str, db, NO_OF_LINES);

    printf("\nenter id to change: ");
    scanf("%s", str);
    printf("\nenter adress to change: ");
    scanf("%s", ad);
    printf("\nenter telephone to change: ");
    scanf("%s", tele);
    printf("\nenter area to change: ");
    scanf("%d", &ar);
    printf("\nenter rooms to change: ");
    scanf("%d", &rom);
    printf("\nenter cost to change: ");
    scanf("%d", &cst);

   
    redact(str, db, NO_OF_LINES, ad, tele, ar, rom,cst);
    printf("After redact");
    for (int i = 0; i < NO_OF_LINES; i++) {

        db[i]->print();

    }
    printf("\n");
    sort( db, NO_OF_LINES);
    printf("\n");

    printf("After sort");
    for (int i = 0; i < NO_OF_LINES; i++) {

        db[i]->print();

    }

    printf("\nenter id to delete AREA: ");
    scanf("%s", str);


    del(str, db, NO_OF_LINES);


    printf("After deleting AREA");
    for (int i = 0; i < NO_OF_LINES; i++) {

        db[i]->print();

    }

    home* db2[NO_OF_LINES+1] = {};

    printf("\nenter adress to add: ");
    scanf("%s", ad);
    printf("\nenter telephone to add: ");
    scanf("%s", tele);
    printf("\nenter area to add: ");
    scanf("%d", &ar);
    printf("\nenter rooms to add: ");
    scanf("%d", &rom);
    printf("\nenter cost to add: ");
    scanf("%d", &cst);



    add(str, db, db2, NO_OF_LINES + 1, ad, tele, ar, rom, cst);


    for (int i = 0; i < NO_OF_LINES+1; i++) {

        db2[i]->print();

    }
   // output = fopen("home2.csv", "w");
   // tofile(output, db, NO_OF_LINES+1);
    std::ofstream out;          // поток для записи
    out.open("home2.csv");
    int i = 0;
   out << "ID,Adress,phone,area,rooms,cost" << std::endl;
   while (i!=NO_OF_LINES+1)
    {
       out << db2[i]->id << "," << db2[i]->adress << "," << db2[i]->telephone << "," << db2[i]->area << "," << db2[i]->rooms << "," << db2[i]->cost ;
     
       out << std::endl;
       
       
        i++;
    }
   out.close();
    clean_up(db, NO_OF_LINES);

    fclose(input);

    return 0;
}