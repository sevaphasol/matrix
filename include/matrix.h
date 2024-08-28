#ifndef MATRIX_H__
#define MATRIX_H__

typedef struct Matrix matrix_t;

#define TYPE double
#define EPSILON 0.000000000000001

struct Matrix *make_matrix(size_t rows, size_t cols);

void delete_matrix(matrix_t *mp);

void print_matrix(matrix_t *mp);

struct Matrix *sum_matrix(matrix_t *mp1, matrix_t *mp2);

void fill_matrix(matrix_t *mp, TYPE val);

bool is_diagonal(matrix_t *mp);

void diagonal_fill_matrix(matrix_t *mp, TYPE val);

bool double_compare(const double x, const double y);

// void scan_matrix(Matrix *matrix);

#endif // MATRIX_H__
