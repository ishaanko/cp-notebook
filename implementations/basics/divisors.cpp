#include <algorithm>
#include <iostream>
#include <vector>

/**
 * Divisors Calculation Implementation
 *
 * Problem Description:
 * - Find all divisors of a number n
 * - Return the kth divisor when sorted in ascending order
 *
 * Algorithm:
 * - Iterate from 1 to sqrt(n) to find all divisors
 * - For each divisor i, also add n/i as a divisor
 * - Time Complexity: O(sqrt(n) + d log d) where d is the number of divisors
 * - Space Complexity: O(d) for storing the divisors
 *
 * Features:
 * - Efficiently computes all divisors in O(sqrt(n)) time
 * - Handles large inputs with long long data type
 * - Returns sorted list of divisors
 */

// Find all divisors of a number
std::vector<long long> getDivisors(long long n) {
  std::vector<long long> divisors;

  // Find all divisors by checking up to sqrt(n)
  for (int i = 1; 1LL * i * i <= n; i++) {
    if (n % i == 0) {
      // Add the divisor
      divisors.push_back(i);

      // Add the corresponding divisor if different
      if (i != n / i) {
        divisors.push_back(n / i);
      }
    }
  }

  // Sort divisors in ascending order
  std::sort(divisors.begin(), divisors.end());
  return divisors;
}

int32_t main() {
  // Optimize input/output operations
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  // Read input number and k
  long long n, k;
  std::cin >> n >> k;

  // Get all divisors of n
  std::vector<long long> divisors = getDivisors(n);

  // Output the kth divisor or -1 if k is too large
  if (k > divisors.size()) {
    std::cout << -1 << '\n';
  } else {
    std::cout << divisors[k - 1] << '\n';
  }

  return 0;
}