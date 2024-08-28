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

matrix_t *make_matrix(const size_t rows, const size_t cols)
{
    matrix_t *matrix = (matrix_t *)calloc(1, sizeof(matrix_t));
    if (matrix == NULL)
        return NULL;
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

void print_matrix(const matrix_t *mp)
{
    if (mp->data != NULL)
    {
        for (size_t i = 0; i < mp->size_i; i ++)
        {
            for (size_t j = 0; j < mp->size_j; j++)
                printf("%lf ", mp->data[i][j]);
            printf("\n");
        }
        printf("\n");
    }
}

matrix_t *sum_matrix(const matrix_t *mp1, const matrix_t *mp2)
{
    if ((mp1 != NULL) && (mp1->data != NULL) && (mp2 != NULL) && (mp2->data != NULL))
    {
        matrix_t *mp = make_matrix(mp1->size_i, mp1->size_j);
        for (size_t i = 0; i < mp1->size_i; i++)
        {
            for (size_t j = 0; j < mp1->size_j; j++)
                mp->data[i][j] = mp1->data[i][j] + mp2->data[i][j];
        }
        return mp;
    }
    return NULL;
}

void fill_matrix(matrix_t * const mp, const TYPE val)
{
    if ((mp != NULL) && (mp->data != NULL))
    {
        for (size_t i = 0; i < mp->size_i; i++)
            for (size_t j = 0; j < mp->size_j; j++)
                mp->data[i][j] = val;
    }
}

bool is_diagonal(const matrix_t *mp)
{
    if ((mp != NULL) && (mp->data != NULL))
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
    return false;
}

bool double_compare(const double x, const double y)
{
    assert(isfinite(x));
    assert(isfinite(y));
    return (fabs(x - y) < EPSILON);
}

void diagonal_fill_matrix(matrix_t * const mp, const TYPE val)
{
    if ((mp != NULL) && (mp->data != NULL))
    {
        for (size_t i = 0; i < mp->size_i; i++)
            for (size_t j = 0; j < mp->size_j; j++)
                if (i == j)
                    mp->data[i][j] = val;
                else
                    mp->data[i][j] = 0;
    }
}

void scan_matrix(matrix_t * const mp)
{
    if (mp != NULL)
    {
        for (size_t i = 0; i < mp->size_i; i++)
            for (size_t j = 0; j < mp->size_j; j++)
                scanf("%lf", &mp->data[i][j]);
    }
}

matrix_t *transpose_matrix(const matrix_t *mp)

{
    matrix_t *mp_new = make_matrix(mp->size_j, mp->size_i);
    for (size_t i = 0; i < mp_new->size_i; i++)
        for (size_t j = 0; j < mp_new->size_j; j++)
            mp_new->data[i][j] = mp->data[j][i];
    return mp_new;
}

matrix_t *multiply_matrix(const matrix_t *mp1, const matrix_t *mp2)
{
    if ((mp1 != NULL) && (mp1->data != NULL) && (mp2 != NULL) && (mp2->data != NULL)
        && (mp1->size_i == mp2->size_j) && (mp1->size_j == mp2->size_i))
    {
        matrix_t *mp = make_matrix(mp1->size_i, mp2->size_j);
        if (mp == NULL)
            return NULL;
        for (size_t i = 0; i < mp->size_i; i++)
        {
            for (size_t j = 0; j < mp->size_j; j++)
            {
                TYPE sum = 0;
                for (size_t pos = 0; pos < mp1->size_j; pos++)
                    sum += mp1->data[i][pos] * mp2->data[pos][j];
                mp->data[i][j] = sum;
            }
        }
        return mp;
    }
    return NULL;
}
