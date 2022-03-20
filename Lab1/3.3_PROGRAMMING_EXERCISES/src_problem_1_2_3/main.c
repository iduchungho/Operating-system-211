#include <stdio.h>
#include "factorial.h"
#include "readline.h"

int main(){
    char str[1024];
    scanf("%s",str);
    if(read_line(str))
    {
        int num = 0,
            size = 0;

        while(str[size] != '\0') size++;

        for(int i = 0 ; i < size ; i++)
        {
            num *= 10;
            num += str[i] - '0';
        }
        printf("%d", factorial(num));
        return 0;
    }
    printf("%d", -1);
    return 0;
}