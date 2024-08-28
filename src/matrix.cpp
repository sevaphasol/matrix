#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include "matrix.h"

int make_matrix(Matrix *matrix)
{
    // matrix->mp = (TYPE *)calloc(matrix->sizeX * matrix->sizeY, matrix->type_size);
    // if (matrix->mp != NULL)
    //     return 0;
    // return -1;
    matrix->mp = (TYPE *)calloc(matrix->size_i, matrix->type_size);
    if (matrix->mp != NULL)
        for (size_t i = 0; i < matrix->size_i; i++)
        {
            matrix->mp[i] = (TYPE *)calloc(matrix->size_j, matrix->type_size);
            if (matrix->mp[i] != NULL)
                return 0;
            return -1;
        }
    else
        return -1;
}

void delete_matrix(Matrix *matrix)
{
    assert(matrix->mp != NULL);
    free(matrix->mp);
    matrix->mp = NULL;
}

void print_matrix(Matrix *matrix)
{
    assert(matrix->mp != NULL);
    for (size_t i = 0; i < matrix->size_i; i++)
    {
        for (size_t j = 0; j < matrix->size_j; j++)
            printf("[%d][%d] = %lf ", i, j, (TYPE)matrix->mp[i*matrix->size_i + j]);
        printf("\n");
    }
    printf("\n");
}

void sum_matrix(Matrix *matrix1, Matrix *matrix2)
{
    for (size_t i = 0; i < matrix1->size_i; i++)
    {
        for (size_t j = 0; j < matrix1->size_j; j++)
            *(matrix1->mp + i*matrix1->size_i + j) = *(matrix1->mp + i*matrix1->size_i + j) + *(matrix2->mp + i*matrix2->size_i + j);
    }
}

void scan_matrix(Matrix *matrix)
{
    for (size_t i = 0; i < matrix->sizeX * matrix->sizeY; i++)
    {
        scanf("%lf", matrix->mp + i);
    }
}

void fill_matrix(Matrix *matrix, TYPE data[][3])
{
    for (size_t i = 0; i < matrix->size_i; i++)
    {
        for (size_t j = 0; j < matrix->size_j; j++)
            matrix->mp[i*matrix->size_i + j] = data[i][j];
    }
}
