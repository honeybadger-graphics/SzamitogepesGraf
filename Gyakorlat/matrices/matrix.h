#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Initializes egysegmatrix.
 */
void init_identity_matrix(float matrix[3][3]);
/**
 * Calc mulitply by skalar.
 */
void calc_multbyskalar_matrix(float matrix[3][3], float skalar);
/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);
/**
 * mulitply matrices.
 */
void calc_multiply_matrices(const float a[3][3], const float b[3][3], float c[3][3]);
/**
 * scale matrix.
 */
void scale_matrix( float matrix[3][3], int x , int y);
void rotate_matrix( float matrix[3][3], double x);

#endif // MATRIX_H

