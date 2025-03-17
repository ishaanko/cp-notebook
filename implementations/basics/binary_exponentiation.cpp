#include <iostream>

/**
 * Binary exponentiation algorithm to calculate x^n % mod efficiently
 * Time complexity: O(log n)
 *
 * @param x base
 * @param n exponent
 * @return x^n % mod
 */
int power(int x, long long n) {
  const int mod = 1000000007; // 10^9 + 7

  // Initialize result to 1 (mod)
  int result = 1 % mod;

  // Keep updating x to x^2, x^4, x^8, ... (mod)
  // and multiply to result when corresponding bit in n is set
  while (n > 0) {
    // If current bit in n is set, multiply result with current x
    if (n % 2 == 1) {
      result = (1LL * result * x) % mod;
    }

    // Square the value of x for next iteration
    x = (1LL * x * x) % mod;

    // Move to next bit in n
    n /= 2;
  }

  return result;
}

int main() {
  // Optimize input/output operations
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  // Example: calculate 2^1000000000 % (10^9+7)
  std::cout << power(2, 1000000000) << '\n';

  return 0;
}