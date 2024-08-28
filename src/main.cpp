#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include "matrix.h"

int main()
{
    size_t m = 3;
    size_t n = 3;

    matrix_t *mp1 = make_matrix(n, m);
    matrix_t *mp2 = make_matrix(n, m);

    diagonal_fill_matrix(mp1, 1.0);
    fill_matrix(mp2, 1.0);

    matrix_t *mp_sum = sum_matrix(mp1, mp2);

    print_matrix(mp1);

    printf("%d\n\n", is_diagonal(mp1));

    print_matrix(mp2);

    printf("%d\n\n", is_diagonal(mp2));

    print_matrix(mp_sum);

    delete_matrix(mp1);
    delete_matrix(mp2);

    // sum_matrix(mp1, mp2);

    // fill_matrix(mp1, 1.0);

    // print_matrix(mp1);

    return 0;
}

