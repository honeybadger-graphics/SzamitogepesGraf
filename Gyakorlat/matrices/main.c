#include "matrix.h" 
// TODO: MORMALIS KOMMENT

int main(int argc, char* argv[])
{
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float testa[3][3] = {
        { 1.0f, 2.0f,  0.0f},
        { 0.0f, 1.0f,  1.0f},
		{ 2.0f, 0.0f,  1.0f}
        
    };
	float testb[3][3] = {
        { 1.0f, 1.0f, 2.0f},  
        { 2.0f, 1.0f, 1.0f},  
        { 1.0f, 2.0f, 1.0f} 
    };
	float b[3][3];
	float c[3][3];
	float x[3][3];
	float y[3][3];
	float W[3][3];
	float testc[3][3];
	float point[1][3] = {
        { 1.0f,2.0f, 1.0f}, 
    };
	float point2[1][3];

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    print_matrix(a);
    print_matrix(b);
    
    add_matrices(a, b, c);

    print_matrix(c);
	
	init_identity_matrix(c);
	printf("C matrix:\n");
	print_matrix(c);
	printf("----------------------------\n");
	printf("A matrix:\n");
	print_matrix(a);
	calc_multbyskalar_matrix(a, 5);
	printf("A matrix 5tel valo skalar szorzas utan :\n");
	print_matrix(a);
	printf("----------------------------\n");
	printf("A matrix:\n");
	print_matrix(testa);
	printf("B matrix:\n");
	print_matrix(testb);
	calc_multiply_matrices(testa, testb, testc);
	printf("AxB matrix :\n");
	print_matrix(testc);
	printf("----------------------------\n");
	printf("Scaled matrix :\n");
	init_identity_matrix(x);
	scale_matrix(x, 2 ,2);
	print_matrix(x);
	printf("----------------------------\n");
	printf("Rotated matrix :\n");
	init_zero_matrix(y);
	rotate_matrix(y,45);
	print_matrix(y);
	printf("----------------------------\n");
	printf("Shifted matrix :\n");
	init_identity_matrix(W);
	shift_matrix( W, 2, 3);
	print_matrix(W);
	printf("----------------------------\n");
	printf("Pont transz matrixal :\n");
	print_point(point);
	transform_point(point, W, point2);
	printf("----------------------------\n");
	print_point(point2);
	

	
	
	
	
	
	
	
	
	

	return 0;
}

