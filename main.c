#include <stdio.h>
#include <time.h>
#include <math.h>

long long k(int max, int number) {
    int _k = floor(max / number);
    return number * (_k * (_k + 1) * 0.5);  
}

int best(int n1, int n2, int maxNumber) {
    maxNumber -= 1;
    return k(maxNumber, n1) + k(maxNumber, n2) - k(maxNumber, n1 * n2);
}

int brute(int n1, int n2, int maxNumber) {
    int total = 0;
    for (int i = 0; i < maxNumber; i++) {
        if (i % n1 == 0 || i % n2 == 0) {
            total += i;
        }
    }
    return total;
}

int main() {
    clock_t start_time, end_time;
    double elapsed_time;

    int max = 1000000;
    int n1 = 3;
    int n2 = 5;


    printf("BRUTE FORCE TIME\n");
    
    start_time = clock();
    
    printf("Sum: %d\n", brute(n1, n2, max));
    
    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    printf("Total Running Time: %lf\n", elapsed_time);
    
    printf("\nBEST ALGORITHM TIME\n");
    
    start_time = clock();
    
    printf("Sum: %d\n", best(n1, n2, max));
    
    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    printf("Total Running Time: %lf\n", elapsed_time);
    

    return 0;
}