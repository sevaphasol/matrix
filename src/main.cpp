#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include "matrix.h"

int main()
{
    Matrix matrix1 = {NULL, 3, 3, sizeof(TYPE)};
    Matrix matrix2 = {NULL, 3, 3, sizeof(TYPE)};

    TYPE data1[][3] = {
                       {1, 1, 1},
                       {1, 1, 1,},
                       {1, 1, 1}
                       };

    TYPE data2[][3] = {
                       {2, 2, 2},
                       {2, 2, 2,},
                       {2, 2, 2}
                       };

    make_matrix(&matrix1);
    make_matrix(&matrix2);

    print_matrix(&matrix1);
    print_matrix(&matrix2);

    fill_matrix(&matrix1, data1);
    fill_matrix(&matrix2, data2);

    sum_matrix(&matrix1, &matrix2);

    print_matrix(&matrix1);

    delete_matrix(&matrix1);
    delete_matrix(&matrix2);
    return 0;
}

