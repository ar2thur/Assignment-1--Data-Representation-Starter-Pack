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
    }

    int i;
    for (i = 0; i < pos; i++) {
        out[i] = temp[pos - 1 - i];
    }
    out[i] = '\0';

    
}





int main(){

    uint32_t n = 156;
    int base = 8;
    char out[256];

    div_convertr(n,base,out);

    printf("String: %s\n", out);

    return 0;
}