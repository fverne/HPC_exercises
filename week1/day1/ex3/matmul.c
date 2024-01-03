void
matmul(int m, int n, int l, double **A, double **B, double **C) {
    
    int i, j, k, sum;

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++) {
            C[i][j] = 0;
            for(k = 0; k < l; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }    
}
