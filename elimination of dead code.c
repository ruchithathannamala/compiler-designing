#include <stdio.h>

int main() {
    int x = 5;
    int y = 10;
    int z;

    if (x > 2) {
        y = y * 2;
    } else {
        y = y / 2;
    }
    if (x < 0) {
        z = x * y;
    }

    printf("y: %d\n", y);

    return 0;
}
