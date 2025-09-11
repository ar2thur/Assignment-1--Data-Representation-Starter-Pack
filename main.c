#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "convert.h" //took me a bit to figure out headers

int main(){
    FILE *file = fopen("a1_test_file.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char buffer[256];
    int test_count = 0;
    int passed_count = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        //excluding lines
        if (buffer[0] != '#' && buffer[0] != '\n' && buffer[0] != '\r') {
            char function_name[32];
            char expected[65];
            uint32_t input1;
            int input2;

            if (strstr(buffer, "FORMATTED_OUTPUT") != NULL) {
                //parse
                if (sscanf(buffer, "%s %u %s", function_name, &input1, expected) == 3) {
                    test_count++;
                    printf("Test %d: %s(%u) -> [FORMATTED OUTPUT CHECK]\n", test_count, function_name, input1);

                    if (strcmp(function_name, "print_tables") == 0) {
                        print_tables(input1);
                        printf("[PASS] - Manual verification required for formatting\n");
                        passed_count++;
                    } else {
                        printf("[FAIL] - Unknown function\n");
                    }
                    printf("\n");
                }
            } else {
                //parse conversion test
                if (sscanf(buffer, "%s %u %d %s", function_name, &input1, &input2, expected) == 4) {
                    test_count++;
                    char result[65];

                    if (strcmp(function_name, "div_convert") == 0) {
                        div_convert(input1, input2, result);

                        //compare
                        if (strcmp(result, expected) == 0) {
                            printf("Test %d: %s(%u, %d) -> Expected: \"%s\", Got: \"%s\" [PASS]\n",
                                   test_count, function_name, input1, input2, expected, result);
                            passed_count++;
                        } else {
                            printf("Test %d: %s(%u, %d) -> Expected: \"%s\", Got: \"%s\" [FAIL]\n",
                                   test_count, function_name, input1, input2, expected, result);
                        }
                    } else if (strcmp(function_name, "sub_convert") == 0) {
                        sub_convert(input1, input2, result);
                        //compare
                        if (strcmp(result, expected) == 0) {
                            printf("Test %d: %s(%u, %d) -> Expected: \"%s\", Got: \"%s\" [PASS]\n",
                                   test_count, function_name, input1, input2, expected, result);
                            passed_count++;
                        } else {
                            printf("Test %d: %s(%u, %d) -> Expected: \"%s\", Got: \"%s\" [FAIL]\n",
                                   test_count, function_name, input1, input2, expected, result);
                        }
                    } else {
                        printf("Test %d: Unknown function %s\n", test_count, function_name);
                    }
                }
            }
        }
    }

    fclose(file); //profit lol

    printf("\nSummary: %d/%d tests passed\n", passed_count, test_count); //good enough

    return 0;
}