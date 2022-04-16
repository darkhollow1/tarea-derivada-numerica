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

// implementations
void explore_errors_derivatives(void)
{
  std::ofstream fout;
  fout.precision(15); fout.setf(std::ios::scientific);
fout.open("data.txt");
     const double X = 4.321;
   const double D_EXACT = deriv_exact(X);
 double h = 0.1;
     for(int n = 1; n <= 10; n++) {
    // fill here :  compute and print the percentual differences

    // update h
    h /= 10.0;
  }
    fout.close();
}

 double f(double x)
{
  // fill here
}

     double deriv_forward(double x, double h)
{
  // fill here
}

double deriv_central(double x, double h)
{
  // fill here
}

double deriv_exact(double x)
{
  // fill here
}