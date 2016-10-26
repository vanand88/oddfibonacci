#include <stdio.h>
#include <ctime>


unsigned long long f(unsigned long long n)
{
  if (n == 0)
    return 1;
  if(n == 1)
    return 1;
  if (n % 2 == 0)
      return f(n / 2);
    return f(n / 2) + f((n / 2) - 1);
}

int main()
{
      clock_t begin = clock();

      f(123456789012345678);

      clock_t end = clock();
      double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  printf("\ntime passed - %f sec\n", elapsed_secs);
  return 0;
}
