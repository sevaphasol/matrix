#ifndef MATRIX_H__
#define MATRIX_H__

typedef struct Matrix matrix_t;

#define TYPE double
#define EPSILON 0.000000000000001
#define MP_FAILURE -1

struct Matrix *make_matrix(const size_t rows, const size_t cols);

int delete_matrix(matrix_t *mp);

int print_matrix(const matrix_t *mp);

matrix_t *sum_matrix(const matrix_t *mp1, const matrix_t *mp2);

int fill_matrix(matrix_t * const mp, const TYPE val);

bool is_diagonal(const matrix_t *mp);

int diagonal_fill_matrix(matrix_t * const mp, const TYPE val);

bool double_compare(const double x, const double y);

int scan_matrix(matrix_t * const mp);

matrix_t *transpose_matrix(const matrix_t *mp);

matrix_t *multiply_matrix(const matrix_t *mp1, const matrix_t *mp2);

#endif // MATRIX_H__
