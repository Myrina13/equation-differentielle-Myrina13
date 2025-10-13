#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "dvector.h"
//Resolution y''+w0²y=0 avec y(0)=1 et y'(0)=0

double Eulery(double x, double y, double yprime, double h);
double Euleryprime(double x, double y, double yprime, double h);
double RK4y(double x, double y, double yprime, double h);
double RK4yprime(double x, double y, double yprime, double h, double k);
double Heuny(double x, double y, double yprime, double h);
double Heunyprime(double x, double y, double yprime, double h, double k);

int main (){
	double ye=1, yrk4=1, yheun=1, yeprime=0, yrk4prime=0, yheunprime=0;
	double n=1000;
	double a=0, b=1;//b=4 * M_PI
	double h=(b-a)/n;
	double x=a;
	FILE *fichier;
	fichier=fopen("equadiffordre2.txt","w");
	
	for (int k=1;k<=n;k++){
		ye=Eulery(x, ye, yeprime,h);
		yeprime=Euleryprime(x, ye, yeprime, h);
		yrk4=RK4y(x, yrk4, yrk4prime, h);
		yrk4prime=RK4yprime(x, yrk4, yrk4prime, h, k);
		yheun=Heuny(x, yrk4, yrk4prime, h);
		yheunprime=Heunyprime(x, yrk4, yrk4prime, h, k);
		fprintf(fichier,"%lf %lf %lf %lf %lf %lf %lf %lf \n", x, ye, yeprime, cos(x), yrk4, yrk4prime, yheun, yheunprime);
		x= a + k*h; //ou x=x+h
	}
	fclose(fichier);
}

double f(double x,double y,double yprime){
	double w0=1; //pulsation d'oscillations
	double epsilon=1;
	return -pow(w0,2) * y;
	//return -2 * w0 * epsilon * yprime -pow(w0,2) * y;
}

double Eulery(double x, double y, double yprime, double h){
	y = y + h * yprime;
	return y;
	
}
double Euleryprime(double x, double y, double yprime, double h){
	yprime = yprime + h * f(x,y,yprime);
	return yprime;
	
}

double RK4y(double x, double y, double yprime, double h){
	y= y + h * yprime;
	return y;
}

double RK4yprime(double x, double y, double yprime, double h, double k){
	double k1;
	double k2;
	double k3;
	double k4;
	k1 = h * f(x,y,yprime);
	k2 = h * f(x + k*h/2,y + k1/2,yprime + k1/2);
	k3 = h * f(x + k*h/2,y + k2/2,yprime + k2/2);
	k4 = h * f(x + k*h,y + k3,yprime + k3);
	yprime = yprime + (k1 + 2 * k2 + 2 * k3 + k4)/6;
	return yprime;
}

double Heuny(double x, double y, double yprime, double h){
	y = y + h * yprime;
	return y;
}

double Heunyprime(double x, double y, double yprime, double h, double k){
	double k1;
	double k2;
	k1 = h * f(x,y,yprime);
	k2 = h * f(x + k*h,y + k1,yprime + k1);
	y= y + (k1 + k2)/2;
	return yprime;

}


//Y[0]=y et Y[1]=yprime
//double Eulervecteur(double x, double y, double yprime, double h, double n){
//	dvector Y(2),F(2);
//	F[1]=h * Y[1]; // Y[1]=f1(x,y,yprime)
//	F[2]=h * f(x,y,yprime);
//	Y[0] = Y[0] + F[1];
//	Y[1] = Y[1] + F[2];
//	
//	return Y[0];
//}
