// Author: Drew Schmidt

#include "rsvd.h"


int RSVD::center(arma::mat &X) const
{
  const arma::uword m = X.n_rows;
  const arma::uword n = X.n_cols;
  
  for (arma::uword j=0; j<n; j++)
  {
    double mean = 0.0;
    for (arma::uword i=0; i<m; i++)
      mean += X(i, j);
    
    mean /= m;
    
    for (arma::uword i=0; i<m; i++)
      X(i, j) -= mean;
  }
  
  return 0;
}
