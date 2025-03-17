#include <iostream>

/**
 * Binary Exponentiation Implementation
 *
 * Problem Description:
 * - Efficiently calculate x^n % mod for very large values of n
 * - Naive approach (x*x*...*x n times) would be too slow for large n
 *
 * Algorithm:
 * - Uses divide-and-conquer approach by converting exponentiation to binary
 * - Represents n in binary and only multiplies necessary powers
 * - Time Complexity: O(log n) where n is the exponent
 * - Space Complexity: O(1)
 *
 * Features:
 * - Prevents integer overflow by using modular arithmetic
 * - Handles very large exponents efficiently
 * - Common technique in cryptography and competitive programming
 */

int power(int x, long long n) {
  const int mod = 1000000007; // 10^9 + 7

  // Initialize result to 1 (mod)
  int result = 1 % mod;

  // Keep updating x to x^2, x^4, x^8, ... (mod)
  // and multiply to result when corresponding bit in n is set
  while (n > 0) {
    // If current bit in n is set, multiply result with current x
    // This is equivalent to checking if n is odd
    if (n % 2 == 1) {
      result = (1LL * result * x) %
               mod; // 1LL ensures 64-bit multiplication to prevent overflow
    }

    // Square the value of x for next iteration
    // This prepares the next power of x: x → x², x² → x⁴, x⁴ → x⁸, etc.
    x = (1LL * x * x) % mod;

    // Move to next bit in n by dividing by 2
    // This is equivalent to right-shifting n by 1 bit
    n /= 2;
  }

  return result;
}

int32_t main() {
  // Optimize input/output operations
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  // Example: calculate 2^1000000000 % (10^9+7)
  // This would be impossible with naive O(n) approach
  std::cout << power(2, 1000000000) << '\n';

  return 0;
}