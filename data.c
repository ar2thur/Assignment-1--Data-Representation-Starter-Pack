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

void sub_convert(uint32_t n, int base, char *out) {
    int pos = 0;

    if (n == 0) {
        out[0] = '0'; //0 case
        out[1] = '\0';
        return;
    }

    //highest power (had to work backwords because of errors)
    uint32_t temp = n;
    int max_power = 0;
    while (temp >= base) {
        temp /= base;
        max_power++;
    }
    for (int power = max_power; power >= 0; power--) { //lesson learned, FOR LOOPS ARE SO MUCH BETTER
        uint32_t base_power = 1;

        for (int i = 0; i < power; i++) {
            base_power *= base;
        }

        uint32_t digit = 0;
        while (n >= base_power) {
            n -= base_power;
            digit++;
        }

        out[pos++] = '0' + digit;
    }

    out[pos] = '\0';
}



int main(){

    uint32_t n = 156;
    int base = 8;
    char out[256];

    div_convertr(n, base, out);

    printf("String: %s\n", out);

    sub_convert(n,base,out);

    printf("String: %s\n", out);

    return 0;
}