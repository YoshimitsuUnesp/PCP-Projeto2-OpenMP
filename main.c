#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
#include <omp.h>  
  
double f(double x, double y) {  
    return sin(x * x + y * y);  
}  
  
double trapezoidal_integration(int nx, int ny, int num_threads) {  
    double a_x = 0.0, b_x = 1.5;  
    double a_y = 0.0, b_y = 1.5;  
    double dx = (b_x - a_x) / nx;  
    double dy = (b_y - a_y) / ny;  
    double integral = 0.0;  
  
    #pragma omp parallel for reduction(+:integral) num_threads(num_threads)  
    for (int i = 0; i < nx; i++) {  
        double x = a_x + i * dx;  
        for (int j = 0; j < ny; j++) {  
            double y = a_y + j * dy;  
            integral += f(x, y);  
        }  
    }  
  
    integral *= dx * dy;  
    return integral;  
}  
  
int main() {  
    int intervals_x[] = {1000, 10000, 100000};  
    int intervals_y[] = {1000, 10000, 100000};  
    int threads[] = {1, 2, 4, 8};  
  
    // Open file for writing results  
    FILE *file = fopen("results.txt", "w");  
    if (file == NULL) {  
        printf("Error opening file!\n");  
        return 1;  
    }  
  
    for (int t = 0; t < 4; t++) {  
        for (int i = 0; i < 3; i++) {  
            for (int j = 0; j < 3; j++) {  
                int nx = intervals_x[i];  
                int ny = intervals_y[j];  
                int num_threads = threads[t];  
  
                double start_time = omp_get_wtime();  
                double result = trapezoidal_integration(nx, ny, num_threads);  
                double end_time = omp_get_wtime();  
  
                double execution_time = end_time - start_time;  
  
                printf("Threads: %d, Intervals: %dx%d, Result: %f, Time: %f seconds\n",  
                       num_threads, nx, ny, result, execution_time);  
                  
                fprintf(file, "Threads: %d, Intervals: %dx%d, Result: %f, Time: %f seconds\n",  
                        num_threads, nx, ny, result, execution_time);  
            }  
        }  
    }  
  
    fclose(file);  
  
    return 0;  
}  