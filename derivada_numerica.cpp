#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

// function declaration
void explore_errors_derivatives(void); // compute and print errors
double f(double x); // function to be derived
double deriv_forward(double x, double h); //numeric derivate with forward derivate methot
double deriv_central(double x, double h); //numeric derivate with central derivate methot
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
    const double D_EXACT = deriv_exact(X); // point which numeric derivates will be computed
    double h = 0.1;
     for(int n = 1; n <= 10; n++) {

    h=pow(0.1,n);                 // h iteration from h=0.1 to h= 0.0000000001 (log scale)

    //begin data export of:    h   ---  percentage error of forward derivate ----  percentage error of central derivate 

    fout << h << "\t" << fabs((D_EXACT-deriv_forward(X,h))/(D_EXACT)) <<"\t"<< fabs((D_EXACT-deriv_central(X,h))/(D_EXACT)) << "\n";
    
    //end data export

  }
    fout.close();
}

 double f(double x)
{
  double y;
    y=sin(x)*4*x + 7 ;                               //this is f(x): Initial funcion which will be derivarted 

  return y;
}

     double deriv_forward(double x, double h)        //num. derivate of f(x) by forward derivate methot
{
  double y;
      y=(f(x + h)-f(x)) / h;

  return y;
}

double deriv_central(double x, double h)
{
  double y;
      y=(f(x + (h/2))-f(x - (h/2))) / h;             //num. derivate of f(x) by central derivate methot

  return y;
}

double deriv_exact(double x)
{
  double y;
    y = 4*(sin(x) + x*cos(x));                       // Exact derivate of funcion f(x)

  return y;
}