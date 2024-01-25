#include "ComplexNumber.h"
#include <cmath>
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

double ComplexNumber::getReal() { return real; }

double ComplexNumber::getImag() { return imag; }

ComplexNumber ComplexNumber::multiply(ComplexNumber &num) {
  /* Complex number rules */
  /* real * real = real */
  /* img * real = img */
  /* real * img = img */
  /* img * img = real * (-1) */

  // operation to consider
  /* (real + img) * (real + img) = (real * real) + (real * img) +
   *                                (img * real)  + (img * img * (-1)) */

  // group the real number outputs
  double realResult = (real * num.real) - (imag * num.imag);

  // group the imaginary number outputs
  double imaginaryResult = (real * num.imag) + (imag * num.real);

  return ComplexNumber(realResult, imaginaryResult);
}

ComplexNumber ComplexNumber::addition(ComplexNumber &num) {
  // operation to consider
  /* (real + img) + (real + img) = (real + real) + (img + img) */
  double realResult = real + num.real;
  double ImaginaryResult = imag + num.imag;

  return ComplexNumber(realResult, ImaginaryResult);
}

ComplexNumber ComplexNumber::subtraction(ComplexNumber &num) {
  // operation to consider
  /* (real + img) - (real + img) = (real - real) + (img - img) */
  double realResult = real - num.real;
  double ImaginaryResult = imag - num.imag;

  return ComplexNumber(realResult, ImaginaryResult);
}

ComplexNumber ComplexNumber::division(ComplexNumber &num) {
  // operation to consider
  /* (real1 + img1) / (real2 + img2) =
   * [ (real1 * real2) + (img1 * img2) / (real2 * real2) + (img2 * img2) ] +
   * [ (img1 * real2) - (real1 * img2) / (real2 * real2) + (img2 * img2) ] */

  // real number part -> [ (real1 * real2) + (img1 * img2) / (real2 * real2) +
  // (img2 * img2) ] imaginary part -> [ (img1 * real2) - (real1 * img2) /
  // (real2 * real2) + (img2 * img2) ]

  double denominator = pow(num.real, 2) + pow(num.imag, 2);
  double realResult = ((real * num.real) + (imag * num.imag)) / denominator;
  double ImaginaryResult =
      ((imag * num.real) - (real * num.imag)) / denominator;

  return ComplexNumber(realResult, ImaginaryResult);
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

  ComplexNumber num3 = num1.multiply(num2);
  cout << "The result after multiplication: ";
  num3.display();

  ComplexNumber num4 = num1.addition(num2);
  cout << "The result after addition: ";
  num4.display();

  ComplexNumber num5 = num1.subtraction(num2);
  cout << "The result after subtraction: ";
  num5.display();

  ComplexNumber num6 = num1.division(num2);
  cout << "The result after division: ";
  num6.display();
}
