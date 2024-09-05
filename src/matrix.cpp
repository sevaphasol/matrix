#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "matrix.h"

typedef struct Matrix
{
    TYPE **data;
    size_t rows;
    size_t cols;
} matrix_t;

matrix_t *make_matrix(const size_t rows, const size_t cols)
{
    matrix_t *matrix = (matrix_t *)calloc(1, sizeof(matrix_t));

    if (matrix == NULL)
        return NULL;

    matrix->data = NULL;
    matrix->rows = rows;
    matrix->cols = cols;

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
    if (is_matrix_valid(mp) == MATRIX_INVALID)
        return -1;

    for (size_t i = 0; i < mp->rows; i++)
        free(mp->data[i]);

    free(mp->data);
    free(mp);

    return 0;
}

int print_matrix(const matrix_t *mp)
{
    if (is_matrix_valid(mp) == MATRIX_INVALID)
        return -1;

    for (size_t i = 0; i < mp->rows; i++)
    {
        for (size_t j = 0; j < mp->cols; j++)
        {
            printf("%lf ", mp->data[i][j]);
        }
        printf("\n");
    }

    return 0;
}

matrix_t *sum_matrix(const matrix_t *mp1, const matrix_t *mp2) // const mp
{
    if (is_matrix_valid(mp1) == MATRIX_INVALID)
        return NULL;

    if (is_matrix_valid(mp2) == MATRIX_INVALID)
        return NULL;

    matrix_t *mp = make_matrix(mp1->rows, mp1->cols);

    if (is_matrix_valid(mp) == MATRIX_INVALID)
        return NULL;

    for (size_t i = 0; i < mp1->rows; i++)
    {
        for (size_t j = 0; j < mp1->cols; j++)
            mp->data[i][j] = mp1->data[i][j] + mp2->data[i][j];
    }

    return mp;
}

int fill_matrix(matrix_t *const mp, const TYPE val)
{
    if (is_matrix_valid(mp) == MATRIX_INVALID)
        return -1;

    for (size_t i = 0; i < mp->rows; i++)
    {
        for (size_t j = 0; j < mp->cols; j++)
        {
            mp->data[i][j] = val;
        }
    }

    return 0;
}

bool is_diagonal(const matrix_t *const mp)
{
    if (is_matrix_valid(mp) == MATRIX_INVALID)
        return MATRIX_FAILURE_BOOL;

    for (size_t i = 0; i < mp->rows; i++)
    {
        for (size_t j = 0; j < mp->cols; j++)
        {
            if (i != j)
                return double_compare(mp->data[i][j], 0);
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

int diagonal_fill_matrix(matrix_t *const mp, const TYPE val)
{
    if (is_matrix_valid(mp) == MATRIX_INVALID)
        return -1;

    for (size_t i = 0; i < mp->rows; i++)
        for (size_t j = 0; j < mp->cols; j++)
            if (i == j)
                mp->data[i][j] = val;
            else
                mp->data[i][j] = 0;

    return 0;
}

int scan_matrix(matrix_t *const mp)
{
    printf("Enter matrix 3x3: \n");

    if (is_matrix_valid(mp) == MATRIX_INVALID)
        return -1;

    for (size_t i = 0; i < mp->rows; i++)
        for (size_t j = 0; j < mp->cols; j++)
            scanf("%lf", &mp->data[i][j]);

    return 0;
}

matrix_t *transpose_matrix(const matrix_t *mp)
{
    if (is_matrix_valid(mp) == MATRIX_INVALID)
        return NULL;

    matrix_t *mp_new = make_matrix(mp->cols, mp->rows);

    if (is_matrix_valid(mp_new) == MATRIX_INVALID)
        return NULL;

    for (size_t i = 0; i < mp_new->rows; i++)
    {
        for (size_t j = 0; j < mp_new->cols; j++)
        {
            mp_new->data[i][j] = mp->data[j][i];
        }
    }

    return mp_new;
}

matrix_t *multiply_matrix(const matrix_t *mp1, const matrix_t *mp2)
{
    if (is_matrix_valid(mp1) == MATRIX_INVALID)
        return NULL;

    if (is_matrix_valid(mp2) == MATRIX_INVALID)
        return NULL;

    if ((mp1->rows != mp2->cols) || (mp1->cols != mp2->rows))
        return NULL;

    matrix_t *mp = make_matrix(mp1->rows, mp2->cols);

    if (is_matrix_valid(mp) == MATRIX_INVALID)
        return NULL;

    for (size_t i = 0; i < mp->rows; i++)
    {
        for (size_t j = 0; j < mp->cols; j++)
        {
            TYPE sum = 0;
            for (size_t pos = 0; pos < mp1->cols; pos++)
            {
                sum += mp1->data[i][pos] * mp2->data[pos][j];
            }
            mp->data[i][j] = sum;
        }
    }

    return mp;
}

MATRIX_VALIDATION is_matrix_valid(const matrix_t *const mp)
{
    if (mp == NULL)
        return MATRIX_INVALID;

    if (mp->data == NULL)
        return MATRIX_INVALID;

    for (int i = 0; i < mp->rows; i++)
        if (mp->data[i] == NULL)
            return MATRIX_INVALID;

    return MATRIX_VALID;
}
