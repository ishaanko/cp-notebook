#include <iostream>
#include <vector>

/**
 * Binary Search Implementation
 *
 * Problem Description:
 * - Search for a target value in a sorted array
 * - Process multiple queries efficiently
 * - Return whether the target exists in the array
 *
 * Algorithm:
 * - Repeatedly divide the search space in half
 * - Compare the middle element with the target value
 * - Time Complexity: O(log n) per query
 * - Space Complexity: O(n) for storing the array
 *
 * Features:
 * - Efficient for searching in sorted arrays
 * - Much faster than linear search (O(log n) vs O(n))
 * - Works only on sorted data
 */

int32_t main() {
  // Optimize input/output operations
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  // Read array size and number of queries
  int n, q;
  std::cin >> n >> q;

  // Read array elements (1-indexed for simplicity)
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  // Note: array must be sorted for binary search to work

  // Process queries
  while (q--) {
    // Read target value to search for
    int target;
    std::cin >> target;

    // Binary search implementation
    int left = 1, right = n;
    bool found = false;

    while (left <= right) {
      // Calculate middle index (avoiding overflow)
      int mid = left + (right - left) / 2;

      // Found the target
      if (a[mid] == target) {
        found = true;
        break;
      }
      // Target is in the right half
      else if (a[mid] < target) {
        left = mid + 1;
      }
      // Target is in the left half
      else {
        right = mid - 1;
      }
    }

    // Output result
    if (found) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }

  return 0;
}