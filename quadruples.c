#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char op[10]; 
    char arg1[10];
    char arg2[10]; 
    char result[10];
} Quadruple;

Quadruple quadruples[100]; 
int quadIndex = 0;

void generateQuadruple(char op[], char arg1[], char arg2[], char result[]) {
    strcpy(quadruples[quadIndex].op, op);
    strcpy(quadruples[quadIndex].arg1, arg1);
    strcpy(quadruples[quadIndex].arg2, arg2);
    strcpy(quadruples[quadIndex].result, result);
    quadIndex++;
}

int main() {
    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    
    char t1[] = "t1";
    char t2[] = "t2";
    char t3[] = "t3";
    
    generateQuadruple("*", c, d, t1);
    generateQuadruple("+", b, t1, t2);
    generateQuadruple("=", t2, "", a);
    printf("Quadruples:\n");
    for (int i = 0; i < quadIndex; i++) {
        printf("%s, %s, %s, %s\n", quadruples[i].op, quadruples[i].arg1, quadruples[i].arg2, quadruples[i].result);
    }
    
    return 0;
}
