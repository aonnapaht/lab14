#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double a[],int N,double b[]){
    
    double sum = 0;
    for(int i = 0;i < N;i++){
        sum += a[i];     
    }
    b[0] = sum/N;
    
    
    double x = 0;
    for(int i = 0;i < N;i++){
        x += pow(a[i],2);
    }
    b[1] = sqrt((x/N) - pow(b[0],2));
    
    
    double g = 1;
    for(int i = 0;i < N;i++){
        g *= a[i];
    }
    b[2] = pow(g,pow(N,-1));
    
    
    double h = 0;
    for(int i = 0;i < N;i++){
        h += 1/a[i];
    }
    b[3] = N/h;
    
    
    b[4] = a[0] , b[5] = a[0];
    for(int i = 1;i < N;i++){
        if(a[i] > b[4]) b[4] = a[i];
        if(a[i] < b[5]) b[5] = a[i]; 
    }
    
}