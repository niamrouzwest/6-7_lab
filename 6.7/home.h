#ifndef __HOME_H__
#define __HOME_H__

#include <string>

struct home
{
    char * id {nullptr};
    std::string adress{""};
    std::string telephone{""};
    int area{0};
    int rooms{0};
	int cost{0};

    void print();
    //struct home* ptr;
};
void memory(home**& dest, const int no_of_lines);
void open(FILE * input, home ** dest);
void find_id(char * str, home ** dest, size_t len);
void redact(char* str, home** dest, size_t len, std::string ad, std::string tele, int ar, int rom, int cst);
void sort( home** dest, size_t len);
void tofile(FILE* output, home ** dest, size_t len);
void del(char* str, home** dest, size_t len);
void add( char* str,home** dest, home** dest2, size_t len, std::string ad, std::string tele, int ar, int rom, int cst);

void clean_up(home ** dest, size_t len);

#endif
