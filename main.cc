#include <stdio.h>
#include <ctime>

unsigned long long f(unsigned long long n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    // if cases of n==0 and n==1 are combined in a single if statement, it runs some ~0.3 seconds faster (the problem states to apply the given formula directly, so I leave it this way)
    if (n & 1) // n is odd 2k + 1
        return f(n >> 1) + f((n >> 1) - 1);
    // - 1 operation takes the most of the time
        //return f(n >> 1) + f(~(-(n >> 1))); // this doesn't help, result is the same 
    // tried also with ONLY bitwise operations (without even unary operator-() ), same result (even a little worse)
    // seams that compiler (with -O3 optimization enabled) does possibly the best
    return f(n >> 1); // n is even
}

int main()
{
    clock_t begin = clock(); // fixing time before executuion
    printf("f(123456789012345678) = %lld\n", f(123456789012345678)); // a call to printf doesn't affect much to the overall performance (~0.1 sec)
    clock_t end = clock(); // fixing time after executuion
    double elapsedTime = double(end - begin) / CLOCKS_PER_SEC;
    printf("Calculation time - %f seconds\n", elapsedTime);
    return 0;
}
