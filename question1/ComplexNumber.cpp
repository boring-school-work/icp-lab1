#include "ComplexNumber.h"
#include <iostream>
using namespace std;

ComplexNumber::ComplexNumber(double real, double imag) {
  this->real = real;
  this->imag = imag;
}

void ComplexNumber::display() {
  if (imag > 0) {
    printf("%.2f + %.2fi\n", real, imag);
  } else {
    printf("%.2f - %.2fi\n", real, imag * -1);
  }
}

int main() {
  double real, imag;

  cout << "Enter the real and imaginary parts of Complex Number 1: ";
  cin >> real >> imag;
  ComplexNumber num1(real, imag);

  cout << "Enter the real and imaginary parts of Complex Number 2: ";
  cin >> real >> imag;
  ComplexNumber num2(real, imag);

  cout << endl;

  cout << "Complex number 1: ";
  num1.display();
  cout << "Complex number 2: ";
  num2.display();

  cout << endl;

  ComplexNumber num3 = num1 + num2;
  cout << "Value after addition: ";
  num3.display();
}
