#include <iostream>
using namespace std;

class SquareRootCalculator {
public:
  double calculateSquareRoot(double number);
};

double SquareRootCalculator::calculateSquareRoot(double number) {
  double cur_guess = number / 2; // take initial guess as half of number
  double prev_guess = 0;

  while (abs(cur_guess - prev_guess) > 1e-6 ) {
    prev_guess = cur_guess;
    cur_guess = 0.5 * (cur_guess + number / cur_guess);
  }

  return cur_guess;
}

int main() {
  SquareRootCalculator calculator;
  double number = 26;
  double ans = calculator.calculateSquareRoot(number);
  printf("Square root of %.2f is %.4f\n", number, ans);
}
