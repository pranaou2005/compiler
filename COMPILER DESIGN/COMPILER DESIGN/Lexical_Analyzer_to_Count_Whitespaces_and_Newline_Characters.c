#include <stdio.h>

void count_whitespace_newlines(const char *input) {
    int i = 0, whitespace_count = 0, newline_count = 0;
    
    while (input[i] != '\0') {
        if (input[i] == ' ' || input[i] == '\t') {
            whitespace_count++;
        } else if (input[i] == '\n') {
            newline_count++;
        }
        i++;
    }
    
    printf("Number of whitespace characters: %d\n", whitespace_count);
    printf("Number of newline characters: %d\n", newline_count);
}

int main() {
    const char *input_string = "This is a test.\nCount whitespaces and newlines.\n";
    count_whitespace_newlines(input_string);
    return 0;
}
