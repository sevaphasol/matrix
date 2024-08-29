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
    if (matrix->data == NULL)
    {
        free(matrix);
        return NULL;
    }
    for (size_t i = 0; i < rows; i++)
    {
        matrix->data[i] = (TYPE *)calloc(cols, sizeof(TYPE));
        if (matrix->data[i] == NULL)
        {
            for (size_t j = 0; j < i; j++)
                free(matrix->data[j]);
            free(matrix->data);
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

int delete_matrix(matrix_t *mp) // void -> int
{
    if (mp == NULL)
        return -1;
    for (size_t i = 0; i < mp->size_i; i++)
        free(mp->data[i]);
    free(mp->data);
    free(mp);
    return 0;
}

int print_matrix(const matrix_t *mp)
{
    if (mp == NULL)
        return -1;
    if (mp->data == NULL)
        return -1;
    for (size_t i = 0; i < mp->size_i; i++)
    {
        for (size_t j = 0; j < mp->size_j; j++)
        {
            if (mp->data[i] == NULL)
                return -1;
            printf("%lf ", mp->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

matrix_t *sum_matrix(const matrix_t *mp1, const matrix_t *mp2) // const mp
{
    if ((mp1 == NULL) || (mp1->data == NULL) || (mp2 == NULL) || (mp2->data == NULL))
        return NULL;
    matrix_t *mp = make_matrix(mp1->size_i, mp1->size_j);
    if (mp == NULL)
        return NULL;
    for (size_t i = 0; i < mp1->size_i; i++)
    {
        for (size_t j = 0; j < mp1->size_j; j++)
            mp->data[i][j] = mp1->data[i][j] + mp2->data[i][j];
    }
    return mp;
}

int fill_matrix(matrix_t * const mp, const TYPE val)
{
    if ((mp == NULL) || (mp->data == NULL))
        return -1;
    for (size_t i = 0; i < mp->size_i; i++)
    {
        for (size_t j = 0; j < mp->size_j; j++)
        {
            if (mp->data[i] == NULL)
                return -1;
            mp->data[i][j] = val;
        }
    }
    return 0;
}

bool is_diagonal(const matrix_t * const mp)
{
    if ((mp == NULL) || (mp->data == NULL))
        return MP_FAILURE;
    for (size_t i = 0; i < mp->size_i; i++)
    {
        for (size_t j = 0; j < mp->size_j; j++)
        {
            if (mp->data[i] == NULL)
                return MP_FAILURE;
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
    }
    return true;
}

bool double_compare(const double x, const double y)
{
    assert(isfinite(x));
    assert(isfinite(y));
    return (fabs(x - y) < EPSILON);
}

int diagonal_fill_matrix(matrix_t * const mp, const TYPE val)
{
    if ((mp == NULL) || (mp->data == NULL))
        return -1;
    for (size_t i = 0; i < mp->size_i; i++)
        for (size_t j = 0; j < mp->size_j; j++)
            if (i == j)
                mp->data[i][j] = val;
            else
                mp->data[i][j] = 0;
    return 0;
}

int scan_matrix(matrix_t * const mp)
{
    if (mp == NULL)
        return -1;
    for (size_t i = 0; i < mp->size_i; i++)
        for (size_t j = 0; j < mp->size_j; j++)
            scanf("%lf", &mp->data[i][j]);
    return 0;
}

matrix_t *transpose_matrix(const matrix_t *mp)
{
    matrix_t *mp_new = make_matrix(mp->size_j, mp->size_i);
    if (mp_new == NULL || mp_new->data == NULL)
        return NULL;
    for (size_t i = 0; i < mp_new->size_i; i++)
    {
        for (size_t j = 0; j < mp_new->size_j; j++)
        {
            if (mp_new->data[i] == NULL)
                return NULL;
            mp_new->data[i][j] = mp->data[j][i];
        }
    }
    return mp_new;
}

matrix_t *multiply_matrix(const matrix_t *mp1, const matrix_t *mp2)
{
    if ((mp1 == NULL) || (mp1->data == NULL) || (mp2 == NULL) || (mp2->data == NULL)
        || (mp1->size_i != mp2->size_j) || (mp1->size_j != mp2->size_i))
        return NULL;
    matrix_t *mp = make_matrix(mp1->size_i, mp2->size_j);
    if (mp == NULL || mp->data == NULL)
        return NULL;
    for (size_t i = 0; i < mp->size_i; i++)
    {
        for (size_t j = 0; j < mp->size_j; j++)
        {
            TYPE sum = 0;
            for (size_t pos = 0; pos < mp1->size_j; pos++)
            {
                if (mp1->data[i] == NULL || mp2->data[pos] == NULL)
                    return NULL;
                sum += mp1->data[i][pos] * mp2->data[pos][j];
            }
            if (mp->data[i] == NULL)
                return NULL;
            mp->data[i][j] = sum;
        }
    }
    return mp;
}
