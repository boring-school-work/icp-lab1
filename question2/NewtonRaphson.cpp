#include <iostream>
using namespace std;

/**
 * A class for calculating the square root of a number using the Newton-Raphson
 * method.
 */
class SquareRootCalculator {
public:
  double calculateSquareRoot(double number);
};

/**
 * Calculates the square root of a number using the Newton-Raphson method.
 *
 * @param number The number whose square root is to be calculated
 * @return The square root of the number
 */
double SquareRootCalculator::calculateSquareRoot(double number) {

  if (number < 0) {
    cout << "Error: cannot calculate square root of negative number" << endl;
    exit(1);
  }

  double cur_guess = number / 2; // take initial guess as half of number
  double prev_guess = 0;

  while (abs(cur_guess - prev_guess) > 1e-6) {
    prev_guess = cur_guess;
    cur_guess = 0.5 * (cur_guess + number / cur_guess);
  }

  return cur_guess;
}

int main() {
  SquareRootCalculator calculator;
  double number;

  cout << "Enter a number: ";
  cin >> number;

  double ans = calculator.calculateSquareRoot(number);
  printf("Square root of %.2f is %.4f\n", number, ans);
}
