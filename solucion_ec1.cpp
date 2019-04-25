#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

void solucion_euler(float x1, float x2, float dx, float w, string nombreArc);
void solucion_rompekukas(float x1, float x2, float dx, float w, string nombreArc);
void solucion_rompekukasp(float x1, float x2, float dx, float w, string nombreArc);
void solucion_salt_rana(float x1, float x2, float dx, float w, string nombreArc);

int main(){
    float w=1;
    float dx=0.5;

    solucion_euler(0.0, 30.0/w, dx/w, w, "euler_0o5_ec1.dat");
    solucion_rompekukasp(0.0, 30.0/w, dx/w, w, "rompeku_0o5_ec1.dat");
    solucion_salt_rana(0.0, 30.0/w, dx/w, w, "rana_0o5_ec1.dat");
    
    return 0;
}

void solucion_euler(float x1, float x2, float dx, float w, string nombreArc){
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
    outfile.close();
}

void solucion_rompekukasp(float x1, float x2, float dx, float w, string nombreArc){
    float x=x1,y_n=1.0,yp_n=0;
    float y_n1,yp_n1;
    float f,f0,f1,f2,f3;
    float k,k0,k1,k2,k3;
    ofstream outfile;
    outfile.open(nombreArc);

    while(x<=x2){
        f0=-pow(w,2)*y_n;
        f1=-pow(w,2)*(y_n+dx*f0/2);
        f2=-pow(w,2)*(y_n+dx*f1/2);
        f3=-pow(w,2)*(y_n+dx*f2/2);
        f=(f0+2*f1+2*f2+f3)/6;
        k0=yp_n-pow(w,2)*y_n*dx;
        k1=yp_n-pow(w,2)*(y_n+dx*f0/2)*dx;
        k2=yp_n-pow(w,2)*(y_n+dx*f1/2)*dx;
        k3=yp_n-pow(w,2)*(y_n+dx*f2/2)*dx;
        k=(k0+2*k1+2*k2+k3)/6;
        yp_n1=yp_n+f*dx;
        y_n1=y_n+k*dx;
        outfile << x << " " << y_n << " " << yp_n <<endl;
        y_n=y_n1,yp_n=yp_n1,x+=dx;
    }
    outfile.close();
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
    outfile.close();
}
void solucion_rompekukasa(float x1, float x2, float dx, float w, string nombreArc){
    float x=x1,y_n=1.0,yp_n=0;
    float y_n1,yp_n1,y_n0o5;
    float f,f0,f1,f2,f3;
    ofstream outfile;
    outfile.open(nombreArc);

    while(x<=x2){
        
        y_n0o5=y_n+yp_n*dx*0.5;
        f0=-pow(w,2)*y_n0o5;
        f1=-pow(w,2)*(y_n0o5+dx*f0/2);
        f2=-pow(w,2)*(y_n0o5+dx*f1/2);
        f3=-pow(w,2)*(y_n0o5+dx*f2/2);
        f=(f0+2*f1+2*f2+f3)/6;
        yp_n1=yp_n+f*dx;
        y_n1=y_n0o5+yp_n*dx*0.5;
        outfile << x << " " << y_n << " " << yp_n <<endl;
        y_n=y_n1,yp_n=yp_n1,x+=dx;
    }
    outfile.close();
}

void solucion_salt_rana(float x1, float x2, float dx, float w, string nombreArc){
    float x=x1,y_n=1.0,yp_n=0;
    float y_n1,yp_n0o5,yp_n1;
    ofstream outfile;
    outfile.open(nombreArc);

    while(x<=x2){
        yp_n0o5=yp_n-pow(w,2)*y_n*dx*0.5;
        y_n1=y_n+yp_n0o5*dx;
        yp_n1=yp_n0o5-pow(w,2)*y_n1*dx*0.5;
        outfile << x << " " << y_n << " " << yp_n <<endl;
        y_n=y_n1,yp_n=yp_n1,x+=dx;
    }
    outfile.close();
}
