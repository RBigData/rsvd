#include "../src/rsvd.h"

#include <cstdio>
#include <ctime>


int main()
{
  const int m = 20000;
  const int n = 500;
  const int k = 3;
  
  arma::mat x(m, n);
  x.randn();
  
  RSVD rsvd(1234);
  clock_t start = clock();
  rsvd.rsvd(k, true, true, x);
  clock_t end = clock();
  double rsvd_time = (double) (end - start) / CLOCKS_PER_SEC;
  
  printf("Run time: %f\n", rsvd_time);
  
  return 0;
}
