#include <stdint.h>
#include <stdio.h>
#include <string.h>

void passby(uint32_t *x, uint32_t y){


    *x += 10;
    y += 10;
}


int main(){

    uint32_t x = 10;
    uint32_t y = 20;

    char str[100] = "Hello World";

    strcat(str," Hello World 2");

    printf("\nThis is passby reference: %u\nThis is pass by value %u\n",x,y);

    passby(&x,y);

    printf("\nThis is passby reference: %u\nThis is pass by value %u\n",x,y);
    printf("And this is the string experiment: %s",str);

    return 0;
}