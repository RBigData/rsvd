#include "../src/rsvd.h"

int main()
{
  Rsvd rsvd(3);
  const int m = 10;
  const int n = 3;
  
  arma::mat x(m, n);
  x.randn();
  
  rsvd.rsvd(1234, 3, true, true, x);
  arma::mat x_rc = rsvd.U * diagmat(rsvd.D) * rsvd.Vt.t();
  abs(x-x_rc).print();
  
  return 0;
}
