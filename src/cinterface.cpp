#include "rsvd.h"

#include <cstdlib>

extern "C" int C_rsvd(csvdp_r p, cmat_r X, svd_t *const restrict svd)
{
  arma::mat X_arma = arma::mat(X->data, X->nrows, X->ncols, true, false);
  RSVD rsvd(p->seed, p->q);
  rsvd.rsvd(p->k, p->retu, p->retv, X_arma);
  
  
  // TODO check mallocs
  svd->D =(dvector_t *) malloc(sizeof(*svd->D));
  svd->U = (dmatrix_t *) malloc(sizeof(*svd->U));
  svd->V = (dmatrix_t *) malloc(sizeof(*svd->V));
  
  if (rsvd.D.n_elem == 0)
  {
    svd->D->len = 0;
    svd->D->data = NULL;
  }
  else
  {
    svd->D->len = (len_t) rsvd.D.n_elem;
    svd->D->data = (double *) malloc(rsvd.D.n_elem * sizeof(double));
    memcpy(svd->D->data, rsvd.D.memptr(), rsvd.D.n_elem * sizeof(double));
  }
  
  if (rsvd.U.n_rows == 0 || rsvd.U.n_cols == 0)
  {
    svd->U->nrows = 0;
    svd->U->ncols = 0;
    svd->U->data = NULL;
  }
  else
  {
    svd->U->nrows = (len_t) rsvd.U.n_rows;
    svd->U->ncols = (len_t) rsvd.U.n_cols;
    svd->U->data = (double *) malloc(rsvd.U.n_rows*rsvd.U.n_cols * sizeof(double));
    memcpy(svd->U->data, rsvd.U.memptr(), rsvd.U.n_rows*rsvd.U.n_cols * sizeof(double));
  }
  
  if (rsvd.V.n_rows == 0 || rsvd.V.n_cols == 0)
  {
    svd->V->nrows = 0;
    svd->V->ncols = 0;
    svd->V->data = NULL;
  }
  else
  {
    svd->V->nrows = (len_t) rsvd.V.n_rows;
    svd->V->ncols = (len_t) rsvd.V.n_cols;
    svd->V->data = (double *) malloc(rsvd.V.n_rows*rsvd.V.n_cols * sizeof(double));
    memcpy(svd->V->data, rsvd.V.memptr(), rsvd.V.n_rows*rsvd.V.n_cols * sizeof(double));
  }
  
  return 0;
}



#define FREE(ptr) if(ptr!=NULL) free(ptr)

extern "C" int C_free_svd(svd_t *const restrict svd)
{
  FREE(svd->D->data);
  free(svd->D);
  
  FREE(svd->U->data);
  free(svd->U);
  
  FREE(svd->V->data);
  free(svd->V);
  
  return 0;
}
