#include <stdio.h>
#include <ctime>

unsigned long long f(unsigned long long n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    if (n & 1) // n is odd 2k + 1
        return f(n >> 1) + f((n >> 1) - 1);
    return f(n >> 1); // n is even
}

int main()
{
    clock_t begin = clock(); // fixing time before executuion
    printf("f(123456789012345678) = %lld\n", f(123456789012345678));
    clock_t end = clock(); // fixing time after executuion
    double elapsedTime = double(end - begin) / CLOCKS_PER_SEC;
    printf("Calculation time - %f seconds\n", elapsedTime);
    return 0;
}
