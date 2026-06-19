#include <stdio.h>

long factorial(int n) {
    long fact = 1;
    for (int i = 1; i <= n; i++) fact *= i;
    return fact;
}

int main() {
    printf("Factorial of 5: %ld\n", factorial(5));
    return 0;
}
