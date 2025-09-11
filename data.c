#include <stdint.h>
#include <stdio.h>
#include <string.h>

void div_convertr(uint32_t n, int base, char *out) {
    char temp[65];  // Temporary buffer
    int pos = 0;

    // Handle zero case
    if (n == 0) {
        strcpy(out, "0");
        return;
    }

    // Extract digits from right to left
    while (n > 0) {
        int remainder = n % base;
        n = n / base;

        // Convert digit to character
        if (remainder < 10)
            temp[pos++] = '0' + remainder;
        else
            temp[pos++] = 'A' + (remainder - 10);
    } //study more ^

    int i;
    for (i = 0; i < pos; i++) {
        out[i] = temp[pos - 1 - i];
    }
    out[i] = '\0';

    
}

void sub_convert(uint32_t n, int base, char *out){
    char temp[65];
    int pos = 0;
    while(pos <= 3){
        uint32_t newBase = 0;
        uint32_t convert = 0;
        while(base <= n){ //finds the highest power
            base *= base;
            newBase = base;
        }
        if(n <= newBase){
            convert = n;
            pos++;
            break;
        }
        while(n > newBase){
            n -= newBase; //subtracts
            convert++;
        }
        out[pos] = '0' + convert;
        pos++;
    }
    out[pos] = '\0';
}



int main(){

    uint32_t n = 156;
    int base = 8;
    char out[256];

    printf("String: %s\n", out);

    sub_convert(n,base,out);

    printf("String: %s\n", out);

    return 0;
}