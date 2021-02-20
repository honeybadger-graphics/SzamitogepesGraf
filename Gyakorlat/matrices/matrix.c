#include "matrix.h"

#include <stdio.h>

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}
void calc_multbyskalar_matrix(float matrix[3][3], float skalar)
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = matrix[i][j] * skalar;
        }
    }
}

void init_identity_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
			if (i==j) 
			{
				matrix[i][j] = 1.0;
				}
			else
			{
            matrix[i][j] = 0.0;
			}
        }
    }
}

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
void calc_multiply_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;
	int l;
	int sum = 0;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
			for (l = 0; l < 3; ++l) { 
			sum = sum + a[i][l]*b[l][j];
			}
			c[i][j] = sum;
			sum = 0;
        }
    }
}
