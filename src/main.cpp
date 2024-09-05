#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
//     matrix_t *mp1 = make_matrix(5, 2);
//     if (mp1 == NULL)
//         return -1;
//     fill_matrix(mp1, 3.0);
//     print_matrix(mp1);
//
//     matrix_t *mp2 = transpose_matrix(mp1);
//     if (mp2 == NULL)
//         return -1;
//     print_matrix(mp2);
//
//     matrix_t *mp3 = multiply_matrix(mp1, mp2);
//     if (mp3 == NULL)
//         return -1;
//     print_matrix(mp3);


    matrix_t *mp4 = make_matrix(3, 3);

    if (mp4 == NULL)
        return -1;

    scan_matrix(mp4);
    printf("%d\n", is_diagonal(mp4));
    print_matrix(mp4);

    delete_matrix(mp4);

    // delete_matrix(mp1);
    // delete_matrix(mp2);
    // delete_matrix(mp3);

    return 0;
}

