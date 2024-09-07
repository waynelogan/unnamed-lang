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
    char *value;
} TokenLiteral;

 TokenLiteral *generate_number(char current, FILE *file) {
    TokenLiteral *token = malloc(sizeof(TokenLiteral));
    token->type = INT;
    char *value = malloc(sizeof(char) * 8);
    int value_index = 0;
    while (isdigit(current) && current != EOF) {
        value[value_index] = current;
        value_index++;
        current = fgetc(file);
    }
    token->value = value;
    return (token);
 }

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
            TokenLiteral *test_token = generate_number(current, file);
            printf("TEST TOKEN VALUE: %s\n", test_token->value);
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