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

int main() {
    TokenLiteral token;
    token.type = INT;
    token.value = 5;
    printf("%d\n", token.value);
}