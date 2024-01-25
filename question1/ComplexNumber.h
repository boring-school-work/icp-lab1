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

  /**
   * Displays the complex number in the form of a + bi or a - bi
   */
  void display();

  /**
   * Multiplies the complex number with another complex number
   *
   * @param num The complex number to multiply with
   * @return The result of the multiplication
   */
  ComplexNumber multiply(ComplexNumber &num);

  /**
   * Adds the complex number with another complex number
   *
   * @param num The complex number to add with
   * @return The result of the addition
   */
  ComplexNumber addition(ComplexNumber &num);

  /**
   * Subtracts the complex number with another complex number
   *
   * @param num The complex number to subtract with
   * @return The result of the subtraction
   */
  ComplexNumber subtraction(ComplexNumber &num);

  /**
   * Divides the complex number with another complex number
   *
   * @param num The complex number to divide with
   * @return The result of the division
   */
  ComplexNumber division(ComplexNumber &num);

  /**
   * Returns the real part of the complex number
   *
   * @return The real part of the complex number
   */
  double getReal();

  /**
   * Returns the imaginary part of the complex number
   *
   * @return The imaginary part of the complex number
   */
  double getImag();

private:
  double real; // real part of the complex number
  double imag; // imaginary part of the complex number
};

#endif
