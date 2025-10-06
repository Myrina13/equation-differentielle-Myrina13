#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Resolution y'(x)+y(x)=0 y(0)=1 intervalle [0,10]
//VA TE FAIRE POUSSIERER PAR UNE SUPERNOVAE

//Appel des fonctions
double Euler(double a, double b, double y0, double n,double h,double k);
double Heun(double a, double b, double y0, double n,double h,double k);
double RK4(double a, double b, double y0, double n,double h,double k);

//Fonctions prinicpales aplications des methodes de resolution equadiff
int main(){
	double a=0,b=10;
	int n=1000;
	double h=(b-a)/n;
	double ytheo=exp(-10);
	double ye=1;
	double yh=1;
	double yrk4=1;

	FILE *fichier;
	fichier=fopen("equadiff.txt","w");
	FILE *erreur;
	erreur=fopen("erreurequadiff.txt","w");
	
	for (int k=1;k<=n;k++){
		ye=Euler(a, b, ye, n, h, k);
		yh=Heun(a, b, yh, n, h, k);
		yrk4=RK4(a, b, yrk4, n, h, k);
		fprintf(fichier,"%.20lf %.20lf %.20lf %.20lf \n",ye,yh,yrk4,exp(-(a + k * h)));
		fprintf(erreur,"%.20lf %.20lf %.20lf \n",fabs(ytheo-ye),fabs(ytheo-yh),fabs(ytheo-yrk4));
	}
	
	printf("theorie : %.20lf \n",ytheo);
	printf("valeur y avec euler : %.20lf \n",ye);
	printf("valeur y avec heun : %.20lf \n",yh);
	printf("valeur y avec rk4 : %.20lf \n",yrk4);
	
	fclose(fichier);
	fclose(erreur);
}

//Definition de la fonction de depart (equation a resoudre)
double f(double x,double y){
	return -y;
}

//Methode Euler
double Euler(double a, double b, double y0, double n,double h,double k){
	double y=y0;
	double x=a;
	double k1;
	k1 = h * f(x,y);
	y = y + k1;
	x= x + k*h;
	
	return y;
}

//Methode Heun (RK2)
double Heun(double a, double b, double y0, double n,double h,double k){
	double y=y0;
	double x=a;
	double k1;
	double k2;
	k1 = h * f(x,y);
	k2 = h * f(x + k*h,y + k1);
	y= y + (k1 + k2)/2;
	x= x + k*h;
		
	return y;
}

//Methode RK4
double RK4(double a, double b, double y0, double n,double h,double k){
	double y=y0;
	double x=a;
	double k1;
	double k2;
	double k3;
	double k4;
	k1 = h * f(x,y);
	k2 = h * f(x + k*h/2,y + k1/2);
	k3 = h * f(x + k*h/2,y + k2/2);
	k4 = h * f(x + k*h,y + k3);
	y= y + (k1 + 2 * k2 + 2 * k3 + k4)/6;
	x= x + k*h;
	
	return y;
}


















