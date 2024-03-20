#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char op[10]; 
    char arg1[10]; 
    char arg2[10];  
} Triple;

Triple triples[100]; 
int tripleIndex = 0; 
void generateTriple(char op[], char arg1[], char arg2[]) {
    strcpy(triples[tripleIndex].op, op);
    strcpy(triples[tripleIndex].arg1, arg1);
    strcpy(triples[tripleIndex].arg2, arg2);
    tripleIndex++;
}

int main() {
    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char d[] = "d";
    
    char t1[] = "t1";
    char t2[] = "t2";
    char t3[] = "t3";
    
    generateTriple("*", c, d);
    generateTriple("+", b, t1);
    generateTriple("=", t1, a);
    printf("Triples:\n");
    for (int i = 0; i < tripleIndex; i++) {
        printf("(%s, %s, %s)\n", triples[i].op, triples[i].arg1, triples[i].arg2);
    }
    
    return 0;
}
