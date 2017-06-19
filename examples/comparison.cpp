#include "../src/rsvd.h"

int main()
{
  const int m = 10;
  const int n = 3;
  
  arma::mat x(m, n);
  x.randn();
  
  RSVD rsvd(1234);
  rsvd.rsvd(3, true, true, x);
  arma::mat x_rc = rsvd.U * diagmat(rsvd.D) * rsvd.Vt.t();
  abs(x-x_rc).print();
  
  return 0;
}
