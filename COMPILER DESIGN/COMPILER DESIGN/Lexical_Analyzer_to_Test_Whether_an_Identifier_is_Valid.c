#include <stdio.h>
#include <ctype.h>

int is_valid_identifier(const char *input) {
    int i = 0;

    // Check the first character
    if (!(isalpha(input[i]) || input[i] == '_')) {
        return 0;
    }
    i++;

    // Check subsequent characters
    while (input[i] != '\0') {
        if (!(isalnum(input[i]) || input[i] == '_')) {
            return 0;
        }
        i++;
    }

    return 1;
}

int main() {
    const char *identifiers[] = {"validIdentifier", "2invalid", "_alsoValid123", "invalid-char!"};
    int num_identifiers = sizeof(identifiers) / sizeof(identifiers[0]);

    for (int i = 0; i < num_identifiers; i++) {
        if (is_valid_identifier(identifiers[i])) {
            printf("'%s' is a valid identifier.\n", identifiers[i]);
        } else {
            printf("'%s' is not a valid identifier.\n", identifiers[i]);
        }
    }

    return 0;
}
