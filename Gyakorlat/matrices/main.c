#include "matrix.h" 
/*TODO: -Definiáljuk a transform_point függvényt, amelyik egy síkbeli, homogén koordinátákkal adott pontra végzi el a paraméterben kapott mátrix által leírt transzformációt!
		- shift matrix				
						*/

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
	float testc[3][3];

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
	init_identity_matrix(x);
	scale_matrix(x, 10 ,-5);
	print_matrix(x);
	printf("----------------------------\n");
	init_zero_matrix(y);
	rotate_matrix(y,90);
	print_matrix(y);

	
	
	
	
	
	
	
	
	

	return 0;
}

