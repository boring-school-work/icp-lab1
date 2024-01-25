#ifndef _COMPLEXNUMBER_H_
#define _COMPLEXNUMBER_H_

/* A class for complex numbers that allows addition, multiplication,
 * subtraction and division operations. */
class ComplexNumber {
public:
  /**
   * Constructor for the class ComplexNumber
   *
   * @param real The real part of the complex number
   * @param imag The imaginary part of the complex number
   */
  ComplexNumber(double real, double imag);

  void display();

  ComplexNumber operator+(const ComplexNumber &other) {
    return ComplexNumber(real + other.real, imag + other.imag);
  }

private:
  double real; // real part of the complex number
  double imag; // imaginary part of the complex number
};

#endif
