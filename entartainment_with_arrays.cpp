#include "entartainment_with_arrays.h"

#include <stdio.h>

int left_triangle_index_element(int i, int j) {
    return ((i * (i + 1) / 2) + j);
}

void left_triangle_output(int strok, int *data) {
    for (int y = 0; y < strok; ++y) {
        for (int x = 0; x < y + 1; ++x) {
            printf("%d ", data[left_triangle_index_element(y, x)]);
        }

        printf("\n");
    }

    printf("\n");
}

void left_triangle_set(int i, int j, int *data, int elem) {
    data[left_triangle_index_element(i, j)] = elem;
}

int left_triangle_sum(int strok, int *data) {
    int sum = 0;

    for (int y = 0; y < strok; ++y) {
        for (int x = 0; x < y + 1; ++x) {
            sum += data[left_triangle_index_element(y, x)];
        }
    }

    return sum;
}




int right_triangle_index_element(int i, int j, int strok) {
    return ((strok * (strok + 1) / 2 - i * (i + 1) / 2) + j);
}

void right_triangle_output(int strok, int *data) {
    for (int y = strok; y > 0; --y) {
        printf("%*s", (strok + (strok - 1)) - (y + (y - 1)), "");

        for (int x = 0; x < y; ++x) {
            printf("%d ", data[right_triangle_index_element(y, x, strok)]);
        }

        printf("\n");
    }

    printf("\n");
}

void right_triangle_set(int i, int j, int *data, int elem, int strok) {
    data[right_triangle_index_element(strok - i, j, strok)] = elem;
}

int right_triangle_sum(int strok, int *data) {
    int sum = 0;

    for (int y = strok; y > 0; --y) {
        for (int x = 0; x < y; ++x) {
            sum += data[right_triangle_index_element(y, x, strok)];
        }
    }

    return sum;
}
