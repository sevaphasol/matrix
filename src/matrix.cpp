#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include "matrix.h"

typedef struct Matrix
{
    TYPE **data;
    size_t size_i;
    size_t size_j;
} matrix_t;

matrix_t *make_matrix(size_t rows, size_t cols)
{
    matrix_t *matrix = (matrix_t *)calloc(1, sizeof(matrix_t));
    *matrix = {NULL, rows, cols};
    matrix->data = (TYPE **)calloc(rows, sizeof(TYPE *));
    if (matrix->data != NULL)
    {
        for (size_t i = 0; i < rows; i++)
        {
            matrix->data[i] = (TYPE *)calloc(cols, sizeof(TYPE));
            if (matrix->data[i] == NULL)
                return NULL;
        }
    }
    else
        return NULL;
    return matrix;
}

void delete_matrix(matrix_t *mp)
{
    for (size_t i = 0; i < mp->size_i; i++)
        free(mp->data[i]);
    free(mp->data);
    free(mp);
}

void print_matrix(matrix_t *mp)
{
    for (size_t i = 0; i < mp->size_i; i ++)
    {
        for (size_t j = 0; j < mp->size_j; j++)
            printf("%lf ", mp->data[i][j]);
        printf("\n");
    }
    printf("\n");
}

struct Matrix *sum_matrix(matrix_t *mp1, matrix_t *mp2)
{
    matrix_t *mp = make_matrix(mp1->size_i, mp1->size_j);
    for (size_t i = 0; i < mp1->size_i; i++)
    {
        for (size_t j = 0; j < mp1->size_j; j++)
            mp->data[i][j] = mp1->data[i][j] + mp2->data[i][j];
    }
    return mp;
}

// // ф-ция проверяющая диагноальная или нет
//
// void scan_matrix(Matrix *matrix)
// {
//     for (size_t i = 0; i < matrix->size_i * matrix->size_j; i++)
//     {
//         scanf("%lf", matrix->mp + i);
//     }
// }
//
// Matrix

void fill_matrix(matrix_t *mp, TYPE val)
{
    for (size_t i = 0; i < mp->size_i; i++)
        for (size_t j = 0; j < mp->size_j; j++)
            mp->data[i][j] = val;
}

bool is_diagonal(matrix_t *mp)
{
    for (size_t i = 0; i < mp->size_i; i++)
    {
        for (size_t j = 0; j < mp->size_j; j++)
            if (double_compare(mp->data[i][j], 0))
            {
                if (i == j)
                    return false;
            }
            else
            {
                if (i != j)
                    return false;
            }
    }
    return true;
}

void diagonal_fill_matrix(matrix_t *mp, TYPE val)
{
    for (size_t i = 0; i < mp->size_i; i++)
        for (size_t j = 0; j < mp->size_j; j++)
            if (i == j)
                mp->data[i][j] = val;
            else
                mp->data[i][j] = 0;
}

bool double_compare(const double x, const double y)
{
    assert(isfinite(x));
    assert(isfinite(y));
    return (fabs(x - y) < EPSILON);
}
