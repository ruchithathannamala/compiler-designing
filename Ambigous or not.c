#include <stdio.h>
#include <stdbool.h>
#include <string.h>
char *productions[] = {
    "E->E+T",
    "E->T",
    "T->T*F",
    "T->F",
    "F->(E)",
    "F->id"
};

int numProductions = 6;

bool isAmbiguous(char *input) {
    return true; 
}

int main() {
    char input[100];
    printf("Enter an input string: ");
    scanf("%s", input);

    if (isAmbiguous(input)) {
        printf("The grammar is ambiguous.\n");
    } else {
        printf("The grammar is not ambiguous.\n");
    }

    return 0;
}
