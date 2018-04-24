#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double u_tnext(double u_tx, double dt, double dx, double u_xant, double D,double u_xnext){
  double u = u_tx + D*(dt/(dx*dx))*(u_xnext - u_tx*2 + u_xant);
  return u;
}

int main(){
  double dx = 0.01;
  double dt = 0.00001;
  double L = 2;
  double T = 2;
  double sigma = 0.1;
  double pi =3.1415926;
  double D = 1;
  
  int n_x = L/dx + 1;
  int n_t = T/dt;

  double *u = new double [n_x];
  double *u_anterior = new double [n_x];
  double *u_inicial = new double [n_x];
  double *x = new double[n_x];

  for(int i = 0; i < n_x; i++){
    double x_i = i*dx;
    x[i] = x_i;
    if((i == 0)||(i == n_x - 1)){
      u_anterior[i] = 0;
      u_inicial[i] = 0;
    }
    else{
      u_anterior[i] = exp(-(x_i - 1)*(x_i-1)/(2*sigma*sigma));
      u_inicial[i] = u_anterior[i];
    }
  }

  while(u_anterior[n_x/2] > 0.5){
    for(int i = 0; i < n_x; i++){
      if((i == 0)||(i == n_x - 1)){
	u[i] = 0;
      }
      else{
	u[i] = u_tnext(u_anterior[i],dt,dx,u_anterior[i-1],D,u_anterior[i+1]);
      }
    }

    for(int i = 0; i < n_x; i++){
      u_anterior[i] = u[i];
    }
  }

  for(int i = 0; i < n_x; i++){
    cout << x[i] << " " << u[i] << " " << u_inicial[i] <<endl;
  }

  return 0;
}
