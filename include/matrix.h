#ifndef MATRIX_H__
#define MATRIX_H__

typedef struct Matrix matrix_t;

typedef double TYPE;

const double EPSILON = 0.000000000000001;

const int MATRIX_FAILURE_BOOL = -1;

enum MATRIX_VALIDATION
{
    MATRIX_INVALID = -1,
    MATRIX_VALID = 0,
};

matrix_t *make_matrix(const size_t rows, const size_t cols);

int delete_matrix(matrix_t *mp);

int print_matrix(const matrix_t *mp);

matrix_t *sum_matrix(const matrix_t *mp1, const matrix_t *mp2);

int fill_matrix(matrix_t *const mp, const TYPE val);

bool is_diagonal(const matrix_t *mp);

int diagonal_fill_matrix(matrix_t *const mp, const TYPE val);

bool double_compare(const double x, const double y);

int scan_matrix(matrix_t *const mp);

matrix_t *transpose_matrix(const matrix_t *mp);

matrix_t *multiply_matrix(const matrix_t *mp1, const matrix_t *mp2);

MATRIX_VALIDATION is_matrix_valid(const matrix_t *const mp);

#endif // MATRIX_H__
