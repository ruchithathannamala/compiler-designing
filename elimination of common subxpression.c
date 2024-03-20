#include <stdio.h>

int main() {
    int a = 5, b = 10, c = 15, d = 20;
    int x, y, z;
    x = a + b * c;
    y = a + b * c;
    z = c + d / a;
    int temp = a + b * c;
    x = temp;
    y = temp;
    z = c + d / a;

    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("z: %d\n", z);

    return 0;
}
