#include <stdio.h>
#include <ctime>


long long decr(long long n)
{
  return ~(-n); // is the same as (n-1)
  //return ~(~n + 1); // is the same as (n-1)
}

long long f(long long n)
{
  if (n == 1)
    return 1;
  if (n == 0)
    return 1;
  if (n & 1)
    return f(n >> 1) + f(decr(n >> 1));
  return f(n >> 1);
}

int main()
{
  clock_t begin = clock();

  printf("%lld", f(123456789012345678));

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  printf("\ntime passed - %f sec\n", elapsed_secs);
  return 0;
}
