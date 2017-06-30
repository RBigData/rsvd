// Author: Drew Schmidt

#ifndef RSVD_H_
#define RSVD_H_


#ifdef __cplusplus

#define ARMA_DONT_USE_WRAPPER
#include <armadillo>
#include <cstdint>

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
    int center(arma::mat &X) const;
    int rsvd(const int k, const bool retu, const bool retv, const arma::mat &X);
    
    arma::vec D;
    arma::mat U;
    arma::mat V;
    
  private:
    int initial_seed();
    int default_q();
    int q_;
    int seed_;
};

extern "C" {



#else
#include <stdbool.h>
#include <stdint.h>
#endif

// typedefs taken unmodified from rsvd C package, copyright Drew Schmidt

typedef int len_t;

// dense matrix
typedef struct dmatrix_t
{
  len_t nrows;
  len_t ncols;
  double *data;
} dmatrix_t;

typedef struct dvector_t
{
  len_t len;
  double *data;
} dvector_t;

typedef dmatrix_t *const restrict mat_r;
typedef const dmatrix_t *const restrict cmat_r;

typedef dvector_t *const restrict vec_r;
typedef const dvector_t *const restrict cvec_r;

typedef struct rsvdparam_t
{
  bool retu;
  bool retv;
  int k;
  int seed;
  uint32_t q;
} rsvdparam_t;

typedef const rsvdparam_t *const restrict csvdp_r;

typedef struct svd_t
{
  dvector_t *restrict D;
  dmatrix_t *restrict U;
  dmatrix_t *restrict V;
  int info;
} svd_t;

#define RSVD_BADMALLOC -1

int C_free_svd(svd_t *const restrict svd);
int C_center(mat_r X);
int C_rsvd(csvdp_r p, cmat_r X, svd_t *const restrict svd);


#ifdef __cplusplus
}
#endif


#endif
