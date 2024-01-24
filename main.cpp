#include <iostream>
#include <cmath>
using namespace std;


/* A class for complex numbers that allows addition, multiplication,
 * subtraction and division operations. */
class ComplexNumber {
  public:
    ComplexNumber(double real, double imaginary);
    void display();
    ComplexNumber multiply(ComplexNumber& num);
    ComplexNumber addition(ComplexNumber& num);
    ComplexNumber subtraction(ComplexNumber& num);
    ComplexNumber division(ComplexNumber& num);
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
    printf("%.2f + %.2fi\n", real, imaginary);
  } else {
    printf("%.2f - %.2fi\n", real, imaginary);
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
  /* (real + img) * (real + img) = (real * real) + (real * img) + 
   *                                (img * real)  + (img * img * (-1)) */
  
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

ComplexNumber ComplexNumber::subtraction(ComplexNumber& num) {
  // operation to consider
  /* (real + img) - (real + img) = (real - real) + (img - img) */
  double realResult = this->getReal() - num.getReal();
  double ImaginaryResult = this->getImaginary() - num.getImaginary();

  return ComplexNumber(realResult, ImaginaryResult);
}

ComplexNumber ComplexNumber::division(ComplexNumber& num) {
  // operation to consider
  /* (real1 + img1) / (real2 + img2) = 
   * [ (real1 * real2) + (img1 * img2) / (real2 * real2) + (img2 * img2) ] +
   * [ (img1 * real2) - (real1 * img2) / (real2 * real2) + (img2 * img2) ] */

  // real number part -> [ (real1 * real2) + (img1 * img2) / (real2 * real2) + (img2 * img2) ]
  // imaginary part -> [ (img1 * real2) - (real1 * img2) / (real2 * real2) + (img2 * img2) ]
  
  double denominator = pow(num.getReal(), 2) + pow(num.getImaginary(), 2);
  double realResult = ((this->getReal() * num.getReal()) + (this->getImaginary() * num.getImaginary())) / denominator;
  double ImaginaryResult = ((this->getImaginary() * num.getReal()) - (this->getReal() * num.getImaginary())) / denominator;

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
  cout << "The result after addition: ";
  num4.display();

  ComplexNumber num5 = num1.subtraction(num2);
  cout << "The result after subtraction: ";
  num5.display();

  ComplexNumber num6 = num1.division(num2);
  cout << "The result after division: ";
  num6.display();

}
