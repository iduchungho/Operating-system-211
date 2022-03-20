#include "readline.h"

int read_line(char* str){
    int f = 1;
    int size = 0;
    while(str[size] != '\0') size++;

    for(int i = 0 ; i < size ; i++)
    {
        if(str[i] < 48 || str[i] > 57)
            f = 0;
    }

    return f;
}