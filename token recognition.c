#include <stdio.h>
#include <ctype.h>
#include <string.h> 
int isKeyword(char *token) {
    char *keywords[] = {"int", "float", "char", "if", "else", "while", "for", "return"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }
    
    return 0; 
}

int main() {
    char code[] = "int a = 10 + 20;";
    char *token = strtok(code, " "); 

    while (token != NULL) {
        if (isalpha(token[0]) || token[0] == '_') {
            if (!isKeyword(token)) {
                printf("Identifier: %s\n", token);
            } else {
                printf("Keyword: %s\n", token);
            }
        } else if (isdigit(token[0])) {
            printf("Constant: %s\n", token);
        } else {
            printf("Operator/Punctuation: %s\n", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}
