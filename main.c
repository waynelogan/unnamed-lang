// following the tutorial: https://youtu.be/-4RmhDy0A2s?list=PLRnI_2_ZWhtA_ZAzEa8uJF8wgGF0HjjEz
#include <stdio.h>
#include <stdlib.h>

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
    char current_char = fgetc(file);
    while(current_char != EOF) {
        printf("%c", current_char);
        current_char = fgetc(file);
    }
}

int main() {
    FILE *file;
    file = fopen("test.unn", "r");
    lexer(file);
}