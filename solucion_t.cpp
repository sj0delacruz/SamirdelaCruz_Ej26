#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

void solucion_explic(float x1, float x2, float dx, float w, string nombreArc);
void solucion_rompekukas(float x1, float x2, float dx, float w, string nombreArc);

int main(){
    int j=0;
    float w=1;

    solucion_explic(0.0, 30.0/w, 0.1/w, w, "euler_01.dat");
    solucion_rompekukas(0.0, 30.0/w, 0.1/w, w, "rompeku_01.dat");
    solucion_explic(0.0, 30.0/w, 0.01/w, w, "euler_001.dat");
    solucion_rompekukas(0.0, 30.0/w, 0.01/w, w, "rompeku_001.dat");
    solucion_explic(0.0, 30.0/w, 0.001/w, w, "euler_0001.dat");
    solucion_rompekukas(0.0, 30.0/w, 0.001/w, w, "rompeku_0001.dat");
    return 0;
}

void solucion_explic(float x1, float x2, float dx, float w, string nombreArc){
    float x=x1,y_n=1.0,yp_n=0;
    float y_n1,yp_n1;
    ofstream outfile;
    outfile.open(nombreArc);

    while(x<=x2){
        yp_n1=yp_n-pow(w,2)*y_n*dx;
        y_n1=y_n+yp_n*dx;
        outfile << x << " " << y_n << " " << yp_n <<endl;
        y_n=y_n1,yp_n=yp_n1,x+=dx;
    }
}

void solucion_rompekukas(float x1, float x2, float dx, float w, string nombreArc){
    float x=x1,y_n=1.0,yp_n=0;
    float y_n1,yp_n1;
    float f,f0,f1,f2,f3;
    ofstream outfile;
    outfile.open(nombreArc);

    while(x<=x2){
        f0=-pow(w,2)*y_n;
        f1=-pow(w,2)*(y_n+dx*f0/2);
        f2=-pow(w,2)*(y_n+dx*f1/2);
        f3=-pow(w,2)*(y_n+dx*f2/2);
        f=(f0+2*f1+2*f2+f3)/6;
        yp_n1=yp_n+f*dx;
        y_n1=y_n+yp_n*dx;
        outfile << x << " " << y_n << " " << yp_n <<endl;
        y_n=y_n1,yp_n=yp_n1,x+=dx;
    }
}