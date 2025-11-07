//Optimize a matrix multiplication algorithm in c++ using SIMD instructions 
//and cache-aware techniques for large sparse matrices 
#include<immintrin.h>
#include<vector>

void multiplySparse(const std::vector<std::vector<double>>& A, 
                    const std::vector<std::vector<double>& B,
                    std::vector<std::vector<double>>& C) {
    size_t n = A.size(), m = B[0].size(), p = B.size();
    for (size_t i =0; i <n; ++i) {
        for (size_t k =0; k < p; ++k) {
            if (A[i][k] ==0) continue; //skip all zero elements 
            __m256d a = _mm256_set1_pd(A[i][k]);
            for (size_t j = 0; j < m; j+=4) {
                __m256d c = _mm256_laodu_pd(&C [i][j]);
                __m256d b = _mm256_laodu_pd(&B[k][j]);
                c = _mm256_fmadd_pd(a, b, c);
                _mm256_storeu_pd(&C[i][j], c);
            }
        }
    }

}