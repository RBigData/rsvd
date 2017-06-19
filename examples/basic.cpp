#include "../src/rsvd.h"

int main()
{
  Rsvd rsvd(3);
  const int m = 10;
  const int n = 3;
  
  arma::mat x(m, n);
  x.randn();
  
  rsvd.rsvd(1234, 1, true, false, x);
  
  rsvd.D.print();
  putchar('\n');
  rsvd.U.print();
  putchar('\n');
  rsvd.Vt.print();
  
  return 0;
}
