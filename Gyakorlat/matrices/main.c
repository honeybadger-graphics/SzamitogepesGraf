#include "matrix.h" /*TODO: - testmatrix átírás - printf normálissá tétele*/

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
	printf("A matrix skalar szorzas utan :\n");
	print_matrix(a);
	printf("----------------------------\n");
	printf("TESTA :\n");
	print_matrix(testa);
	printf("TESTB :\n");
	print_matrix(testb);
	calc_multiply_matrices(testa, testb, testc);
	
	printf("TESTC :\n");
	print_matrix(testc);
	
	
	
	
	

	return 0;
}

