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

void stat(const double a[],int N,double b[]){
    double sum = 0, sd = 0, har = 0, geo = 1, max = a[0], min = a[0];
    for(int i = 0; i < N; i++) {
        sum += a[i];
    }
    
    b[0] = sum / N;
    
    for(int i = 0; i < N; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        
        if (a[i] < min) {
            min = a[i];
        }
        
        sd += pow((a[i] - b[0]), 2);
        har += 1 / a[i];
        geo *= a[i];
    }
    
    b[1] = sqrt(sd / N);
    b[2] = pow(geo, (1.0 / double(N))); 
    b[3] = N / har; 
    b[4] = max;
    b[5] = min;
}