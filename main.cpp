#include <iostream>
using namespace std;


/* A class that performs multiplication of two complex numbers */
class ComplexNumber {
  public:
    ComplexNumber(double real, double imaginary);
    void display();
    ComplexNumber multiply(ComplexNumber& num);
    ComplexNumber addition(ComplexNumber& num);
    double getReal();
    double getImaginary();

  private:
    double real;
    double imaginary;
};

ComplexNumber::ComplexNumber(double real, double imaginary) {
  this->real = real;
  this->imaginary = imaginary;
}

void ComplexNumber::display() {
  if (imaginary > 0) {
    cout << real << " + " << imaginary << "i" << endl;
  } else {
    cout << real << " - " << -1 * imaginary << "i" << endl;
  }
}

double ComplexNumber::getReal() {
  return real;
}

double ComplexNumber::getImaginary() {
  return imaginary;
}

ComplexNumber ComplexNumber::multiply(ComplexNumber& num) {
  /* Complex number rules */
  /* real * real = real */
  /* img * real = img */
  /* real * img = img */
  /* img * img = real * (-1) */

  // operation to consider
  /* (real + img) * (real + img) = (real * real) + (real * img) + (img * real)  + (img * img * (-1)) */
  
  // group the real number outputs
  double realResult = (this->getReal() * num.getReal()) - (this->getImaginary() * num.getImaginary());

  // group the imaginary number outputs
  double imaginaryResult = (this->getReal() * num.getImaginary()) + (this->getImaginary() * num.getReal());
  
  return ComplexNumber(realResult, imaginaryResult);
}

ComplexNumber ComplexNumber::addition(ComplexNumber& num) {
  // operation to consider
  /* (real + img) + (real + img) = (real + real) + (img + img) */
  double realResult = this->getReal() + num.getReal();
  double ImaginaryResult = this->getImaginary() + num.getImaginary();

  return ComplexNumber(realResult, ImaginaryResult);
}


int main() {
  ComplexNumber num1(2, 3);
  ComplexNumber num2(4, 5);

  cout << "Complex number 1: ";
  num1.display();
  cout << "Complex number 2: ";
  num2.display();

  ComplexNumber num3 = num1.multiply(num2);
  cout << "The result after multiplication: ";
  num3.display();

  ComplexNumber num4 = num1.addition(num2);
  cout << "The result after multiplication: ";
  num4.display();
}
