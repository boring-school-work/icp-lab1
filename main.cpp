#include <iostream>
using namespace std;


/* A class that performs multiplication of two complex numbers */
class ComplexNumber {
  public:
    ComplexNumber(double real, double imaginary);
    void display();
    ComplexNumber multiply(ComplexNumber& num);
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
  cout << real << " + " << imaginary << "i" << endl;
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
  /* (real + img) * (real + img) = (real * real) + (real * img) + (img * real)  + (img * img * (-1))*/
  
  // group the real number outputs
  double realResult = (this->getReal() * num.getReal()) - (this->getImaginary() * num.getImaginary());

  // group the imaginary number outputs
  double imaginaryResult = (this->getReal() * num.getImaginary()) + (this->getImaginary() * num.getReal());
  
  return ComplexNumber(realResult, imaginaryResult);
}

int main() {
  ComplexNumber num1(2, 3);
  ComplexNumber num2(4, 5);
  ComplexNumber num3 = num1.multiply(num2);

  cout << "Complex number 1: ";
  num1.display();
  cout << "Complex number 2: ";
  num2.display();

  cout << "The result after multiplication: ";
  num3.display();
}
