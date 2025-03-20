#include <iostream>

/**
 * 2D Prefix Sum Implementation
 *
 * Problem Description:
 * - Precompute 2D cumulative sums to efficiently answer submatrix sum queries
 * - Process multiple queries of the form "sum of elements in submatrix from
 *   (x1,y1) to (x2,y2)"
 *
 * Algorithm:
 * - Build a 2D prefix sum array where pref[i][j] = sum of elements in submatrix
 *   from (1,1) to (i,j)
 * - Answer submatrix sum queries in O(1) using inclusion-exclusion principle
 * - Time Complexity: O(n*m) for preprocessing, O(1) per query
 * - Space Complexity: O(n*m) for storing the 2D prefix sums
 *
 * Features:
 * - Efficient for multiple submatrix sum queries
 * - 1-indexed for simplicity
 * - Reduces quadratic time queries to constant time
 */

const int N = 1005;
int a[N][N], pref[N][N];

int32_t main() {
  // Optimize input/output operations
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  // Read matrix dimensions
  int n, m;
  std::cin >> n >> m;

  // Read matrix elements (1-indexed)
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }

  // Build 2D prefix sum array
  // pref[i][j] = sum of all elements in the submatrix from (1,1) to (i,j)
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] =
          pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
    }
  }

  // Process queries
  int q;
  std::cin >> q;
  while (q--) {
    // Read submatrix coordinates (x1,y1) to (x2,y2)
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    // Calculate sum of elements in the submatrix using inclusion-exclusion
    // Instead of O(n²) nested loops, we get O(1) time complexity
    int sum = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] +
              pref[x1 - 1][y1 - 1];

    std::cout << sum << '\n';
  }

  return 0;
}