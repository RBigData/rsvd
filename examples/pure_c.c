// Author: Drew Schmidt


#include "../src/rsvd.h"

#include <stdlib.h>
#include <stdio.h>

static void printmat(cmat_r X)
{
  const len_t m = X->nrows;
  const len_t n = X->ncols;
  
  if (m == 0 || n == 0)
  {
    printf("[matrix size: 0x0]\n\n");
    return;
  }
  
  
  for (len_t i=0; i<m; i++)
  {
    for (len_t j=0; j<n; j++)
      printf("%9.4f ", (X->data)[i + m*j]);
    
    putchar('\n');
  }
  
  putchar('\n');
}

static void printvec(cvec_r X)
{
  const len_t n = X->len;
  
  for (len_t i=0; i<n; i++)
    printf("%9.4f\n", X->data[i]);
  
  putchar('\n');
}



static inline double runif()
{
  return rand() / (((double)RAND_MAX) + 1.0);
}

static void fillmat(const int seed, mat_r X)
{
  const len_t m = X->nrows;
  const len_t n = X->ncols;
  
  srand(seed);
  
  for (len_t j=0; j<n; j++)
  {
    for (len_t i=0; i<m; i++)
      X->data[i + m*j] = runif();
  }
}



int main()
{
  const len_t m = 10;
  const len_t n = 3;
  
  rsvdparam_t p;
  dmatrix_t X;
  svd_t svd;
  
  //set up p
  p.retu = true;
  p.retv = false;
  p.k = 1;
  p.seed = 1234;
  p.q = 3;
  
  // set up X
  X.nrows = m;
  X.ncols = n;
  X.data = malloc(m*n * sizeof(double));
  fillmat(p.seed, &X);
  
  C_rsvd(&p, &X, &svd);
  
  printvec(svd.D);
  printmat(svd.U);
  printmat(svd.V);
  
  free(X.data);
  C_free_svd(&svd);
  
  return 0;
}
