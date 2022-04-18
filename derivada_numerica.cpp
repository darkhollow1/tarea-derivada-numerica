#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

// function declaration
void explore_errors_derivatives(void); // compute and print errors
double f(double x); // function to be derived
double deriv_forward(double x, double h);
double deriv_central(double x, double h);
double deriv_exact(double x); // exact derivative

int main(int argc, char **argv)
{
  explore_errors_derivatives();
  
  return 0;
}

/// implementations
void explore_errors_derivatives(void)
{
  std::ofstream fout;
  fout.precision(15); fout.setf(std::ios::scientific);
  fout.open("data.txt");
     const double X = 4.321;
   const double D_EXACT = deriv_exact(X);
  double h = 0.1;
     for(int n = 1; n <= 10; n++) {
    h=pow(0.1,n); 

    fout << h << "\t" << fabs((D_EXACT-deriv_forward(X,h))/(D_EXACT)) <<"\t"<< fabs((D_EXACT-deriv_central(X,h))/(D_EXACT)) << "\n";
    // update h
    // h/= 10.0;
  }
    fout.close();
}

 double f(double x)
{
  double y;
    y=sin(x)*4*x + 7 ; //Initial funcion which will be derivarted 

  return y;
}

     double deriv_forward(double x, double h)
{
  double y;
      y=(f(x + h)-f(x)) / h;

  return y;
}

double deriv_central(double x, double h)
{
  double y;
      y=(f(x + (h/2))-f(x - (h/2))) / h;

  return y;
}

double deriv_exact(double x)
{
  double y;
    y = 4*(sin(x) + x*cos(x));

  return y;
}