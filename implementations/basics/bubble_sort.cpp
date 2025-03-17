#include <algorithm>
#include <iostream>

/**
 * Bubble Sort Implementation
 *
 * Problem Description:
 * - Sort an array of integers in ascending order
 * - Count the number of swaps performed during sorting
 * - Display the first and last elements of the sorted array
 *
 * Algorithm:
 * - In each iteration, compare adjacent elements and swap if they are in wrong
 * order
 * - After each pass, the largest element "bubbles up" to its correct position
 * - Time Complexity: O(n²) where n is the number of elements
 * - Space Complexity: O(n) for storing the array
 *
 * Features:
 * - Simple implementation with minimal memory overhead
 * - Stable sorting algorithm (maintains relative order of equal elements)
 * - Practical for small arrays or nearly sorted arrays
 */
int32_t main() {
  // Optimize input/output operations
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  // Read array size
  int n;
  std::cin >> n;

  // Read array elements (1-indexed for simplicity)
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  // Counter for number of swaps
  int swaps = 0;

  // Bubble sort implementation
  // Requires at most n-1 passes through the array
  for (int step = 1; step <= n - 1; step++) {
    // Compare adjacent elements and swap if needed
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i + 1]) {
        std::swap(a[i], a[i + 1]);
        ++swaps;
      }
    }
  }

  // Output results
  std::cout << "Array is sorted in " << swaps << " swaps.\n";
  std::cout << "First Element: " << a[1] << '\n';
  std::cout << "Last Element: " << a[n] << '\n';

  return 0;
}