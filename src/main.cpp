#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include "matrix.h"

int main()
{
    matrix_t *mp1 = make_matrix(2, 3);
    fill_matrix(mp1, 1);
    print_matrix(mp1);

    matrix_t *mp2 = transpose_matrix(mp1);
    print_matrix(mp2);

    delete_matrix(mp1);

    return 0;
}

