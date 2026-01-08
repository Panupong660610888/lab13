#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    
    double sum_am = 0;
    double sum_sd = 0;
    double sum_gm = 0;
    double sum_hm = 0;
    double max = A[0];
    double min = A[0];
    
    for (int i = 0; i < N; i++){
        sum_am += A[i];
    }
    
     B[0] = sum_am/N;
     
     for (int j = 0; j < N; j++){
         sum_sd += pow(A[j]-B[0],2);
         sum_gm += log(A[j]);
         sum_hm += 1/A[j];
         if (A[j] > max) max = A[j];
         if (A[j] < min) min = A[j];
     }
     
     B[1] = sqrt(sum_sd/N);
     B[2] = exp(sum_gm/N);
     B[3] = N/sum_hm;
     B[4] = max;
     B[5] = min;
     
}