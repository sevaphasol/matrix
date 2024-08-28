#ifndef MATRIX_H__
#define MATRIX_H__

typedef struct Matrix matrix_t;

#define TYPE double
#define EPSILON 0.000000000000001

struct Matrix *make_matrix(const size_t rows, const size_t cols);

void delete_matrix(matrix_t *mp);

void print_matrix(const matrix_t *mp);

matrix_t *sum_matrix(const matrix_t *mp1, const matrix_t *mp2);

void fill_matrix(matrix_t * const mp, const TYPE val);

bool is_diagonal(const matrix_t *mp);

void diagonal_fill_matrix(matrix_t * const mp, const TYPE val);

bool double_compare(const double x, const double y);

void scan_matrix(matrix_t * const mp);

matrix_t *transpose_matrix(const matrix_t *mp);

#endif // MATRIX_H__
