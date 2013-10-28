#include <iostream>
using namespace std;

double function (double a, double b, double c, double x){
     double y;
     y = a*x*x*x + b*x + c;
     return y;
}

double function_derivative (double a, double b, double x){
     double y_deriv;
     y_deriv = 3*a*x*x + b;
     return y_deriv;
}

int main (){
     double a, b, c, denominator, newtonX;
     double tolerance = 0.00000001;
     double x0 = 0;

     bool foundSolution = false;

     cout << "For equation:" << endl
          << "ax^3 + bx + c = 0" << endl
          << "Please enter following values:" << endl
          << "a: ";
     cin >> a;
     cout << "b: ";
     cin >> b;
     cout << "c: ";
     cin >> c;

     do{
     denominator = function_derivative (a, b, x0);
     newtonX = x0 - function(a, b, c, x0)/denominator;
          if (fabs(newtonX - x0) < tolerance){
               cout << "The one real root is: " << newtonX << endl;
               foundSolution = true;
          }
     x0 = newtonX;
     } while (foundSolution == false);
     cin >> a;
     system("PAUSE");
     return 0;
}