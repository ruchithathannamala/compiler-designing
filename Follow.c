#include <ctype.h>
#include <stdio.h>
#include <string.h>
void follow_first_function(char, int, int);
void follow(char c);
void findfirst(char, int, int);
int count, n = 0;
char first_set_Arr[10][100];
char follow_set_Arr[10][100];
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
first_set_Arr[k][kay] = '!';
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
findfirst(c, 0, 0);
ptr += 1;
done[ptr] = c;
first_set_Arr[point1][point2++] = c;
for (i = 0 + jm; i < n; i++) {
int lark = 0, chk = 0;
for (lark = 0; lark < point2; lark++) {
if (first[i] == first_set_Arr[point1][lark]) {
chk = 1;
break;
}
}
if (chk == 0) {
first_set_Arr[point1][point2++] = first[i];
}
}
jm = n;
point1++;
}
char donee[count];
ptr = -1;
for (k = 0; k < count; k++) {
for (kay = 0; kay < 100; kay++) {
follow_set_Arr[k][kay] = '!';
}
}
point1 = 0;
int land = 0;
for (e = 0; e < count; e++) {
ck = production_rules_arr[e][0];
point2 = 0;
xxx = 0;
for (kay = 0; kay <= ptr; kay++)
if (ck == donee[kay])
xxx = 1;
if (xxx == 1)
continue;
land += 1;
follow(ck);
ptr += 1;
donee[ptr] = ck;
printf(" Follow(%c) = { ", ck);
follow_set_Arr[point1][point2++] = ck;
for (i = 0 + km; i < m; i++) {
int lark = 0, chk = 0;
for (lark = 0; lark < point2; lark++) {
if (f[i] == follow_set_Arr[point1][lark]) {
chk = 1;
break;
}
}
if (chk == 0) {
printf("%c, ", f[i]);
follow_set_Arr[point1][point2++] = f[i];
}
}
printf(" }\n\n");
km = m;
point1++;
}
}
void follow(char c)
{
int i, j;
if (production_rules_arr[0][0] == c) {
f[m++] = '$';
}
for (i = 0; i < 10; i++) {
for (j = 2; j < 10; j++) {
if (production_rules_arr[i][j] == c) {
if (production_rules_arr[i][j + 1] != '\0') {
follow_first_function(production_rules_arr[i][j + 1], i,
(j + 2));
}
if (production_rules_arr[i][j + 1] == '\0'
&& c != production_rules_arr[i][0]) {
follow(production_rules_arr[i][0]);
}
}
}
}
}
void findfirst(char c, int q1, int q2)
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
findfirst(production_rules_arr[q1][q2], q1,
(q2 + 1));
}
else
first[n++] = '#';
}
else if (!isupper(production_rules_arr[j][2])) {
first[n++] = production_rules_arr[j][2];
}
else {
findfirst(production_rules_arr[j][2], j, 3);
}
}
}
}
void follow_first_function(char c, int c1, int c2)
{
int k;
if (!(isupper(c)))
f[m++] = c;
else {
int i = 0, j = 1;
for (i = 0; i < count; i++) {
if (first_set_Arr[i][0] == c)
break;
}
while (first_set_Arr[i][j] != '!') {
if (first_set_Arr[i][j] != '#') {
f[m++] = first_set_Arr[i][j];
}
else {
if (production_rules_arr[c1][c2] == '\0') {
follow(production_rules_arr[c1][0]);
}
else {
follow_first_function(production_rules_arr[c1][c2], c1,
c2 + 1);
}
}
j++;
}
}
}
