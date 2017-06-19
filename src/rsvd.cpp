// Author: Drew Schmidt

#include "rsvd.h"


#define THROW_QR \
  throw std::runtime_error("unable to compute QR");


int RSVD::rsvd(const int k, const bool retu, const bool retvt, arma::mat &X)
{
  bool check;
  const int n = X.n_cols;
  arma::mat Omega;
  arma::mat Q, R;
  arma::vec B_D;
  arma::mat B, B_U, B_Vt;
  
  if (k < 1)
    throw std::invalid_argument("'k' must be positive");
  else if (k > n)
    throw std::invalid_argument("'k' must be less than nrows(X)");
  
  
  // Stage A from the paper
  try
  {
    Omega.set_size(n, 2*k);
  }
  catch(...)
  {
    throw std::runtime_error("unable to allocate nx(2*k) matrix Omega");
  }
  
  arma::arma_rng::set_seed(seed_);
  Omega.randu();
  
  arma::mat Y = X * Omega;
  
  check = qr(Q, R, X);
  
  for (int i=0; i<q_; i++)
  {
    Y = X.t() * Q;
    check = qr(Q, R, Y);
    if (!check)
      THROW_QR;
    
    Y = X * Q;
    check = qr(Q, R, Y);
    if (!check)
      THROW_QR;
  }
  
  
  // Stage B
  B = Q.t() * X;
  check = svd(B_U, B_D, B_Vt, B);
  if (!check)
    throw std::runtime_error("unable to compute SVD");;
  
  
  // Wrangle return
  D = B_D.subvec(0, k-1);
  
  if (retu)
  {
    U = Q * B_U;
    U = U(arma::span::all, arma::span(0, k-1));
  }
  else
    U = arma::mat(0, 0);
  
  if (retvt)
    Vt = B_Vt(arma::span(0, k-1), arma::span::all);
  else
    Vt = arma::mat(0, 0);
  
  
  return 0;
}
