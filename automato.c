#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 8

int caracterEspecial(char c) {
    return c == '@' || c == '*' || c == '_' || c == '-' || c == '#';
}

void error(int erro) {
    switch (erro)
    {
    case 1: 
        printf("Erro! Identificador inválido, caracteres acima do limite\n");
        break;
    case 2: 
        printf("Erro! Identificador inválido, primeiro caracter nao e maiusculo\n");
        break;
    case 3: 
        printf("Erro! Identificador inválido, segundo caracter nao e um algarismo\n");
        break;
    case 4: 
        printf("Erro! Identificador inválido, caracter nao aceito\n");
        break; 
    default:
        printf("Erro! Identificador inválido.\n");
        break;
    }

    exit(1);
}

void checandoIdentificador(char* identificador) {
    int length = strlen(identificador);

    if (length > MAX_LENGTH) {
        error(1);
    }

    if (!isupper(identificador[0])) {
        error(2);
    }

    if (!isdigit(identificador[1])) {
        error(3);
    }

    for (int i = 2; i < length; i++) {
        if (!isalnum(identificador[i]) && !caracterEspecial(identificador[i])) {
            error(4);
        }
    }
}

int main() {
    char identificador[MAX_LENGTH + 1];

    printf("Digite o identificador: ");
    scanf("%s", identificador);

    checandoIdentificador(identificador);

    printf("Identificador válido.\n");

    return 0;
}