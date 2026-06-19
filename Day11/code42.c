#include <stdio.h>

int findMax(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    printf("Maximum: %d\n", findMax(45, 82));
    return 0;
}
