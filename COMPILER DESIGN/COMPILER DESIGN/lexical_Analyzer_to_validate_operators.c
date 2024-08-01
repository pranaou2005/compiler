#include <stdio.h>
#include <ctype.h>

void validate_operators(const char *input) {
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            printf("Found operator: %c\n", input[i]);
        }
        i++;
    }
}

int main() {
    const char *input_string = "a + b - c * d / e";
    validate_operators(input_string);
    return 0;
}
