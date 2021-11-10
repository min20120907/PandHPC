#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// declare the functions below
void alloc_rdn_array(double*, int);
double randfrom(double, double);
void print_array(double*, int);
void ps(int, int);
// The main program
int main(int argc, char **argv) {
	srand(time(NULL));
	size_t n=99999999, NITERS=30;	// to specify the size of n, NITERS
	double *a, *b, *c, *d;
	clock_t before = clock();
	// allocate the spaces for the dynamic arrays
	a = malloc(sizeof(double)*n);
	b = malloc(sizeof(double)*n);
	c = malloc(sizeof(double)*n);
	d = malloc(sizeof(double)*n);
	// assign them with random values
	alloc_rdn_array(a, n);	
	alloc_rdn_array(b, n);	
	alloc_rdn_array(c, n);	
	alloc_rdn_array(d, n);	
	for(size_t j = 0; j < NITERS; j++) {
		for(size_t i = 0; i < n; i++) {
			a[i] = b[i] + c[i] * d[i];
		}
			ps(NITERS, j);
	}
	clock_t duration = clock() - before;
	double msec = duration * 1000/ CLOCKS_PER_SEC;
	// print out the results
//	printf("A arr: ");
//	print_array(a, n);
//	printf("B arr: ");
//	print_array(b, n);
//	printf("C arr: ");
//	print_array(c, n);
//	printf("D arr: ");
//	print_array(d, n);
	printf("\n");
	printf("Total execution time: %lf\n",msec/1000);
	printf("The Calculation Performance: %lf FLOP/S\n", 2*n*NITERS/(msec/1000));

	free(a);
	free(b);
	free(c);
	free(d);
	return 0;
}

void ps(int total, int current){
//      printf("0000000000");
        fflush(stdout);
        int i = 0;
        for(i = 0 ; i < total ; i++){
                printf("\b");
        }
        fflush(stdout);
//      sleep(1);
        for(int i = 0 ; i < total ; i++){
                if(i<current){
                         printf("#");
                }
                else{
                         printf(".");
                }
        }
}

void alloc_rdn_array(double *arr, int n){
	int i;
	for(i=0;i<n;i++){
		arr[i] = randfrom(-RAND_MAX,RAND_MAX);		
	}
}

double randfrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

void print_array(double *arr, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%lf ", arr[i]);		
	}
	printf("\n");
}
