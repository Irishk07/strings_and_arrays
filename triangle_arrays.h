#ifndef TRIANGLE_ARRAYS_H_
#define TRIANGLE_ARRAYS_H_

int left_triangle_index_element(int i, int j);

void left_triangle_output(int strok, int *data);

void left_triangle_set(int i, int j, int *data, int elem);

int left_triangle_sum(int strok, int *data);

int right_triangle_index_element(int i, int j, int strok);

void right_triangle_output(int strok, int *data);

void right_triangle_set(int i, int j, int *data, int elem, int strok);

int right_triangle_sum(int strok, int *data);

#endif //TRIANGLE_ARRAYS_H_