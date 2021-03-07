#include <cstdio>
#include <cstring>
#include <string>
#include "home.h"
#include <fstream>
void home::print()
{
    printf("%s %s %s %d %d %d\n", 
                this->id,
                this->adress.c_str(),
                this->telephone.c_str(),
                this->area,
                this->rooms,
				this->cost);
}
void memory(home **& dest, const int no_of_lines) {
    dest = new home * [no_of_lines];

    for (int i = 0; i < no_of_lines; ++i) {

        dest[i] = new home;

    }

}
void open(FILE * input, home ** dest) 
{
    char buf [100] = {};
    size_t i = 0;
    while (fgets(buf, 100, input))
    {
        const char* delim = ";\"\n";
        char * token = strtok(buf, delim);

        if (!strcmp(token, "id")) continue;
        
        home * tmp = new home;

        while (token)
        {
            if (tmp->id == nullptr) 
            {
                tmp->id = new char [strlen(token) + 1];
                strcpy(tmp->id, token);
            }
            else if (tmp->adress == "")
            {
                tmp->adress = token;
            }
            else if (tmp->telephone == "")
            {
                tmp->telephone = token;
            }
            else if (tmp->area == 0) 
            {
                tmp->area = (int)atol(token);
            }
            else if (tmp->rooms == 0) 
            {
                tmp->rooms = (int)atol(token);
            }
            else if (tmp->cost == 0) 
            {
                tmp->cost = (int)atol(token);
            }
            token = strtok(NULL, delim);
        }
        
        dest[i] = tmp;
        ++i;
    }
}

void add(char* str, home** dest, home** dest2, size_t len, std::string ad, std::string tele, int ar, int rom, int cst) {
    home* tmp = new home;
    
    for (size_t i = 0; i < len-1; i++) {
        dest2[i] = dest[i];
    }
    while (true)
    {
        if (tmp->id == nullptr)
        {
            tmp->id = new char[25+1];
            strcpy(tmp->id, "25" );
        }
       if (tmp->adress == "")
        {
            tmp->adress = ad;
        }
        if (tmp->telephone == "")
        {
            tmp->telephone = tele;
        }
         if (tmp->area == 0)
        {
            tmp->area = ar;
        }
         if (tmp->rooms == 0)
        {
            tmp->rooms = rom;
        }
        if (tmp->cost == 0)
        {
            tmp->cost = cst;
        }
        break; false;
    }

    dest2[len-1] = tmp;
   /* dest2[len-1]->adress = ad;
    dest2[len-1]->telephone = tele;
    dest2[len-1]->area = ar;
    dest2[len-1]->rooms = rom;
    dest2[len-1]->cost = cst;*/
}

void find_id(char * str, home ** dest, size_t len) 
{
    for (size_t i = 0; i < len; i++)
    {
        if (!strcmp(str, dest[i]->id))
        {
            dest[i]->print();
        }
    }
}

void redact (char * str, home ** dest, size_t len, std::string ad, std::string tele, int ar, int rom, int cst) 
{
	 for (size_t i = 0; i < len; i++)
    {
        if (!strcmp(str, dest[i]->id))
        {
            dest[i]->adress=ad;
            dest[i]->telephone=tele;
            dest[i]->area=ar;
            dest[i]->rooms=rom;
            dest[i]->cost=cst;
        }
    }
}

void clean_up(home ** dest, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        delete [] dest[i]->id;
        delete dest[i];
    }
}

void del(char* str, home** dest, size_t len) {
    for (size_t i = 0; i < len; i++)
    {
        if (!strcmp(str, dest[i]->id))
        {
            dest[i]->area = NULL;
          //  delete dest[i]->area;
        }
    }
}
void tofile(FILE* output, home** dest, size_t len)
{
  /*  std::ofstream out;
    out.open("D:\\hello.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        out << "Hello World!" << std::endl;
    }
    */
    int i = 0;
    
    char buf[100] = {};
    
   // strcpy(buf, dest[i]->area());
   // size_t i = 0;
    while (i!=len) {
        
     
        fprintf(output, buf );

        i++;
    }


}
void sort( home** dest, size_t len)
{
    home *tmp;
    int count = 0;
    while (count != len - 1) {
        count = 0;
        for (size_t i = 0; i < len-1 ; i++)
        {
            if (dest[i + 1]->rooms < dest[i]->rooms) {

                tmp = dest[i];
                dest[i] = dest[i + 1];
                dest[i + 1] = tmp;

            }
            else count++;


        }

    }

}
