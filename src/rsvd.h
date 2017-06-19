#ifndef RSVD_H_
#define RSVD_H_


#define ARMA_DONT_USE_WRAPPER
#include <armadillo>

class Rsvd
{
  public:
    Rsvd(int q)
    {
      q_ = q;
    };
    
    int rsvd(const int seed, const int k, const bool retu, const bool retvt, arma::mat &X);
    
    int q_;
    arma::vec D;
    arma::mat U;
    arma::mat Vt;
};


#endif
