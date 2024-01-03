#include "cblas.h"		/* cblas */
#include "datatools.h"		/* helper functions	        */

int
main(int argc, char *argv[]) {
    int m = 3;
    int n = 2;
    int k = 5;
    int alpha = 1.0;
    int beta = 0.0;
    double **A, **B, **C;

    A = malloc_2d(m, k);
    B = malloc_2d(k, n);
    C = malloc_2d(m, n);

    init_data(m,n,k,A,B);

    cblas_dgemm(CblasRowMajor, 
    CblasNoTrans,
    CblasNoTrans,
    m, n, k, alpha, *A, k, *B, n, beta, *C, n);

    printmatrix(m, n, C);

    free_2d(A);
    free_2d(B);
    free_2d(C);
}
