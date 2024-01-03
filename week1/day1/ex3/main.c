#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "datatools.h"		/* helper functions	        */
#include "matadd.h"		/* my matrix add fucntion	*/
#include "matmul.h"		/* my matrix mul function	*/

#define NREPEAT 100		/* repeat count for the experiment loop */

#define mytimer clock
#define delta_t(a,b) (1e3 * (b - a) / CLOCKS_PER_SEC)


void
printmatrix(int m, int n, double **arr) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
}


int
main(int argc, char *argv[]) {

    int    i, m, n, N = NREPEAT;
    double **A, **B, **C;
    double tcpu1; 

    clock_t t1, t2;

    int l = 5;

    // for (m = 200; m <= 250; m += 100) {
        n = 2;
        m = 3;

        /* Allocate memory */
        // printf("%d, %d, %d", m, l, n);
        A = malloc_2d(m, l);
        B = malloc_2d(l, n);
        C = malloc_2d(m, n);
        if (A == NULL || B == NULL | C == NULL) {
            fprintf(stderr, "Memory allocation error...\n");
            exit(EXIT_FAILURE);
        }

        /* initialize with useful data - last argument is reference */
        init_data(m,n,l,A,B);

        /* timings for matmul */
        t1 = mytimer();
        for (i = 0; i < N; i++)
            matmul(m, n, l, A, B, C);
        t2 = mytimer();
        tcpu1 = delta_t(t1, t2) / N;

        // check_results("main", m, n, C);

        /* Print n and results  */
        // printf("%4d %4d %8.3f\n", m, n, tcpu1);
        printmatrix(m, n, C);


        /* Free memory */
        free_2d(A);
        free_2d(B);
        free_2d(C);
    // }

    return EXIT_SUCCESS;
}
