#include <ctype.h>
#include <stdio.h>
#include <string.h>
void first_set_function(char, int, int);
int count, n = 0;
char first_set_arr[10][100];
int m = 0;
char production_rules_arr[10][10];
char f[10], first[10];
int k;
char ck;
int e;
int main(int argc, char** argv)
{
int jm = 0;
int km = 0;
int i, choice;
char c, ch;
count = 8;
strcpy(production_rules_arr[0], "A=BxC");
strcpy(production_rules_arr[1], "A=Dy");
strcpy(production_rules_arr[2], "B=q");
strcpy(production_rules_arr[3], "B=#");
strcpy(production_rules_arr[4], "C=p");
strcpy(production_rules_arr[5], "C=#");
strcpy(production_rules_arr[6], "D=oy");
strcpy(production_rules_arr[7], "D=CB");
int kay;
char done[count];
int ptr = -1;
for (k = 0; k < count; k++) {
for (kay = 0; kay < 100; kay++) {
first_set_arr[k][kay] = '!';
}
}
int point1 = 0, point2, xxx;
for (k = 0; k < count; k++) {
c = production_rules_arr[k][0];
point2 = 0;
xxx = 0;
for (kay = 0; kay <= ptr; kay++)
if (c == done[kay])
xxx = 1;
if (xxx == 1)
continue;
first_set_function(c, 0, 0);
ptr += 1;
done[ptr] = c;
printf("\n First(%c) = { ", c);
first_set_arr[point1][point2++] = c;
for (i = 0 + jm; i < n; i++) {
int lark = 0, chk = 0;
for (lark = 0; lark < point2; lark++) {
if (first[i] == first_set_arr[point1][lark]) {
chk = 1;
break;
}
}
if (chk == 0) {
printf("%c, ", first[i]);
first_set_arr[point1][point2++] = first[i];
}
}
printf("}\n");
jm = n;
point1++;
}
}
void first_set_function(char c, int q1, int q2)
{
int j;
if (!(isupper(c))) {
first[n++] = c;
}
for (j = 0; j < count; j++) {
if (production_rules_arr[j][0] == c) {
if (production_rules_arr[j][2] == '#') {
if (production_rules_arr[q1][q2] == '\0')
first[n++] = '#';
else if (production_rules_arr[q1][q2] != '\0'
&& (q1 != 0 || q2 != 0)) {
first_set_function(production_rules_arr[q1][q2], q1,
(q2 + 1));
}
else
first[n++] = '#';
}
else if (!isupper(production_rules_arr[j][2])) {
first[n++] = production_rules_arr[j][2];
}
else {
first_set_function(production_rules_arr[j][2], j, 3);
}
}
}
}
