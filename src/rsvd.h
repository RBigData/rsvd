// Author: Drew Schmidt

#ifndef RSVD_H_
#define RSVD_H_


#define ARMA_DONT_USE_WRAPPER
#include <armadillo>

class RSVD
{
  public:
    RSVD();
    RSVD(int seed);
    RSVD(int seed, int q);
    int get_seed() const;
    int get_q() const;
    void set_seed(const int seed);
    void set_q(const int q);
    int rsvd(const int k, const bool retu, const bool retvt, arma::mat &X);
    
    arma::vec D;
    arma::mat U;
    arma::mat Vt;
    
  private:
    int initial_seed();
    int default_q();
    int q_;
    int seed_;
};


#endif
