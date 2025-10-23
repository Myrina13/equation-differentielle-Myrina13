#include <stdio.h>
#include <math.h>

#include "dvector.h"


dvector F(dvector y,double t);
dvector Eulerpas(dvector y,double t,double h);
dvector Heunpas(dvector y,double t,double h);
dvector RK4pas(dvector y,double t,double h);



int main(){
    
  dvector ye(2), yh(2), yr(2);
  double t,h=0.001,ex;
  double tmax=10*2.0*M_PI+h;
  FILE *f1,*f2,*f3;
  double omega2=1;
  double alpha=0.5;
  double omegatilde=sqrt(omega2-alpha*alpha/4.0);

  ye[0]=1;
  ye[1]=0;
  yh[0]=1;
  yh[1]=0;
  yr[0]=1;
  yr[1]=0;
  ex=1;
    
  f1=fopen("euler.dat","w");
  f2=fopen("heun.dat","w");
  f3=fopen("rk4.dat","w");
    
  for(t=0;t<tmax;t+=h){
    fprintf(f1,"%16.8lf  %22.12lf  %22.12lf\n",t,ye[0],ex);
    fprintf(f2,"%16.8lf  %22.12lf  %22.12lf\n",t,yh[0],ex);
    fprintf(f3,"%16.8lf  %22.12lf  %22.12lf\n",t,yr[0],ex);
    ye=Eulerpas(ye,t,h);
    yh=Heunpas(yh,t,h);
    yr=RK4pas(yr,t,h);
    ex=cos(omegatilde*(t+h))*exp(-alpha*(t+h)/2.0);
  }
  fprintf(f1,"%16.8lf  %22.12lf  %22.12lf\n",t,ye[0],ex);
  fprintf(f2,"%16.8lf  %22.12lf  %22.12lf\n",t,yh[0],ex);
  fprintf(f3,"%16.8lf  %22.12lf  %22.12lf\n",t,yr[0],ex);
    
    fclose(f1);
    fclose(f2);
    fclose(f3);
    
}



dvector F(dvector y,double t){
  int n=y.size();
  double omega2=1;
  double alpha=0.5;
  dvector r(n);
  r[0]=y[1];
  r[1]=-omega2*y[0]-alpha*y[1];
  
  return r;
}

dvector Eulerpas(dvector y,double t,double h){
    int n=y.size();
    dvector k1(n);
    k1=h*F(y,t);
    return y+k1;
}

dvector Heunpas(dvector y,double t,double h){
    int n=y.size();
    dvector k1(n),k2(n);
    k1=h*F(y,t);
    k2=h*F(y+k1,t+h);
    return y+(k1+k2)/2;
}

dvector RK4pas(dvector y,double t,double h){
  int n=y.size();
  dvector k1(n),k2(n),k3(n),k4(n);
  k1=h*F(y,t);
  k2=h*F(y+k1/2,t+h/2);
  k3=h*F(y+k2/2,t+h/2);
  k4=h*F(y+k3,t+h);
  return y+(k1+2*k2+2*k3+k4)/6;  
}
