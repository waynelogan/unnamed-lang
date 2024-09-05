// following the tutorial: https://youtu.be/-4RmhDy0A2s?list=PLRnI_2_ZWhtA_ZAzEa8uJF8wgGF0HjjEz
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREN,
} TypeSeparator;

typedef enum {
    EXIT
} TypeKeyword;

typedef enum {
    INT
} TypeLiteral;

typedef struct {
    TypeKeyword type;
} TokenKeyword;

typedef struct {
    TypeSeparator type;
} TokenSeparator;

typedef struct {
    TypeLiteral type;
    int value;
} TokenLiteral;

 

void lexer(FILE *file) {
    // read next char from a stream
    char current = fgetc(file);
    while(current != EOF) {
        if (current == ';' ) {
            printf("found semicolon\n");
        } else if (current == '(' ) {
            printf("found open paren\n");
        } else if (current == ')') {
            printf("found close paren\n");
        } else if (isdigit(current)) {
            // sub ASCII of 0 (is 48) from ascii of number to get number
            printf("found digit %d\n", current - '0');
        } else if(isalpha(current)) {
            printf("found character %c\n", current);
        }
        current = fgetc(file);
    }
}

int main() {
    // create file stream
    FILE *file;
    file = fopen("test.unn", "r");
    lexer(file);
}