#include <iostream>

/**
 * Prefix Sum Implementation
 *
 * Problem Description:
 * - Precompute cumulative sums to efficiently answer range sum queries
 * - Process multiple queries of the form "sum of elements from index l to r"
 *
 * Algorithm:
 * - Build a prefix sum array where pref_sum[i] = sum of elements from 1 to i
 * - Answer range queries in O(1) using the formula: sum(l,r) = pref_sum[r] -
 * pref_sum[l-1]
 * - Time Complexity: O(n) for preprocessing, O(1) per query
 * - Space Complexity: O(n) for storing the prefix sums
 *
 * Features:
 * - Efficient for multiple range sum queries
 * - Handles large arrays with long long data type
 * - 1-indexed for simplicity
 */

const int N = 2e5 + 9;
long long pref_sum[N];
int a[N];

int32_t main() {
  // Optimize input/output operations
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  // Read array size and number of queries
  int n, q;
  std::cin >> n >> q;

  // Read array elements (1-indexed)
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  // Build prefix sum array
  for (int i = 1; i <= n; i++) {
    pref_sum[i] = pref_sum[i - 1] + a[i];
  }

  // Process queries
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    // Calculate sum of elements from index l to r
    std::cout << pref_sum[r] - pref_sum[l - 1] << '\n';
  }

  return 0;
}