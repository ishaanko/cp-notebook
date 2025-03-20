#include <iostream>
#include <vector>

/**
 * Binomial Coefficients Implementation
 *
 * Problem Description:
 * - Efficiently calculate nCr (binomial coefficients) for large values
 * - Handle modular arithmetic to prevent overflow
 *
 * Algorithm:
 * - Precompute factorials and their modular inverses
 * - Use the formula nCr = n! / ((n-r)! * r!)
 * - Time Complexity: O(N) for precomputation, O(1) for each query
 * - Space Complexity: O(N) for storing precomputed values
 *
 * Features:
 * - Handles large inputs using modular arithmetic
 * - Uses Fermat's Little Theorem for calculating modular inverses
 * - Efficient for multiple queries
 */

const int N = 1e6 + 9, mod = 1e9 + 7;

int f[N], inv[N], finv[N];

// Precompute factorial, modular inverse, and inverse factorial values
void precompute() {
  // Initialize base cases
  f[0] = 1;

  // Compute factorials: f[i] = i!
  for (int i = 1; i < N; i++) {
    f[i] = (1LL * i * f[i - 1]) % mod;
  }

  // Compute modular inverses using extended Euclidean algorithm
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    // inv[i] is the modular multiplicative inverse of i
    inv[i] = (-(1LL * mod / i) * inv[mod % i]) % mod;
    inv[i] = (inv[i] + mod) % mod; // Ensure result is positive
  }

  // Compute inverse factorials: finv[i] = (i!)^(-1)
  finv[0] = 1;
  for (int i = 1; i < N; i++) {
    finv[i] = (1LL * inv[i] * finv[i - 1]) % mod;
  }
}

// Calculate nCr = n! / (r! * (n-r)!)
int ncr(int n, int r) {
  // Handle edge cases
  if (n < r || n < 0 || r < 0)
    return 0;

  // Calculate using precomputed values
  return (1LL * f[n] * finv[n - r] % mod * finv[r] % mod);
}

int32_t main() {
  // Optimize input/output operations
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  // Precompute required values
  precompute();

  // Process queries
  int q;
  std::cin >> q;

  while (q--) {
    int n, r;
    std::cin >> n >> r;
    std::cout << ncr(n, r) << '\n';
  }

  return 0;
}