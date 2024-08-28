#ifndef MATRIX_H__
#define MATRIX_H__

#define TYPE double

typedef struct Matrix
{
    TYPE *mp[];
    size_t size_i;
    size_t size_j;
    size_t type_size = sizeof(TYPE);
 } Matrix;

int make_matrix(Matrix *matrix);

void delete_matrix(Matrix *matrix);

void print_matrix(Matrix *matrix);

void sum_matrix(Matrix *matrix1, Matrix *matrix2);

void scan_matrix(Matrix *matrix);

void fill_matrix(Matrix *matrix, TYPE data[][3]);

#endif // MATRIX_H__
