#include <cmath>
#include <iostream>
using namespace std;

/* A class for complex numbers that allows addition, multiplication,
 * subtraction and division operations. */
class ComplexNumber {
public:
  ComplexNumber(double real, double imaginary);
  void display();
  ComplexNumber multiply(ComplexNumber &num);
  ComplexNumber addition(ComplexNumber &num);
  ComplexNumber subtraction(ComplexNumber &num);
  ComplexNumber division(ComplexNumber &num);
  double getReal();
  double getImaginary();

private:
  double real;      // real part of the complex number
  double imaginary; // imaginary part of the complex number
};

/**
 * Constructor for the class ComplexNumber
 *
 * @param real The real part of the complex number
 * @param imaginary The imaginary part of the complex number
 */
ComplexNumber::ComplexNumber(double real, double imaginary) {
  this->real = real;
  this->imaginary = imaginary;
}

/**
 * Displays the complex number in the form of a + bi or a - bi
 */
void ComplexNumber::display() {
  if (imaginary > 0) {
    printf("%.2f + %.2fi\n", real, imaginary);
  } else {
    printf("%.2f - %.2fi\n", real, imaginary * -1);
  }
}

/**
 * Returns the real part of the complex number
 *
 * @return The real part of the complex number
 */
double ComplexNumber::getReal() { return real; }

/**
 * Returns the imaginary part of the complex number
 *
 * @return The imaginary part of the complex number
 */
double ComplexNumber::getImaginary() { return imaginary; }

/**
 * Multiplies the complex number with another complex number
 *
 * @param num The complex number to multiply with
 * @return The result of the multiplication
 */
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
  double realResult = (this->getReal() * num.getReal()) -
                      (this->getImaginary() * num.getImaginary());

  // group the imaginary number outputs
  double imaginaryResult = (this->getReal() * num.getImaginary()) +
                           (this->getImaginary() * num.getReal());

  return ComplexNumber(realResult, imaginaryResult);
}

/**
 * Adds the complex number with another complex number
 *
 * @param num The complex number to add with
 * @return The result of the addition
 */
ComplexNumber ComplexNumber::addition(ComplexNumber &num) {
  // operation to consider
  /* (real + img) + (real + img) = (real + real) + (img + img) */
  double realResult = this->getReal() + num.getReal();
  double ImaginaryResult = this->getImaginary() + num.getImaginary();

  return ComplexNumber(realResult, ImaginaryResult);
}

/**
 * Subtracts the complex number with another complex number
 *
 * @param num The complex number to subtract with
 * @return The result of the subtraction
 */
ComplexNumber ComplexNumber::subtraction(ComplexNumber &num) {
  // operation to consider
  /* (real + img) - (real + img) = (real - real) + (img - img) */
  double realResult = this->getReal() - num.getReal();
  double ImaginaryResult = this->getImaginary() - num.getImaginary();

  return ComplexNumber(realResult, ImaginaryResult);
}

/**
 * Divides the complex number with another complex number
 *
 * @param num The complex number to divide with
 * @return The result of the division
 */
ComplexNumber ComplexNumber::division(ComplexNumber &num) {
  // operation to consider
  /* (real1 + img1) / (real2 + img2) =
   * [ (real1 * real2) + (img1 * img2) / (real2 * real2) + (img2 * img2) ] +
   * [ (img1 * real2) - (real1 * img2) / (real2 * real2) + (img2 * img2) ] */

  // real number part -> [ (real1 * real2) + (img1 * img2) / (real2 * real2) +
  // (img2 * img2) ] imaginary part -> [ (img1 * real2) - (real1 * img2) /
  // (real2 * real2) + (img2 * img2) ]

  double denominator = pow(num.getReal(), 2) + pow(num.getImaginary(), 2);
  double realResult = ((this->getReal() * num.getReal()) +
                       (this->getImaginary() * num.getImaginary())) /
                      denominator;
  double ImaginaryResult = ((this->getImaginary() * num.getReal()) -
                            (this->getReal() * num.getImaginary())) /
                           denominator;

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
