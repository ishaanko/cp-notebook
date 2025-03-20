#include <iostream>

/**
 * Insertion Sort Implementation
 *
 * Problem Description:
 * - Sort an array of integers in ascending order using insertion sort
 * - Elements are processed one at a time, building a sorted output array
 *
 * Algorithm:
 * - Iterate through each element of the array
 * - For each element, insert it into its correct position in the sorted part
 * - Shift elements as needed to make space for the inserted element
 * - Time Complexity: O(n²) where n is the number of elements
 * - Space Complexity: O(n) for storing the array
 *
 * Features:
 * - Simple implementation with minimal memory overhead
 * - Stable sorting algorithm (maintains relative order of equal elements)
 * - Efficient for small or nearly sorted arrays
 * - Performs well on arrays that are already partially sorted
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

  // Insertion sort implementation
  for (int i = 1; i <= n; i++) {
    // Store current element to be inserted
    int current_element = a[i];
    int j = i - 1;

    // Shift elements that are greater than current_element
    // to one position ahead of their current position
    while (j >= 1 && a[j] > current_element) {
      a[j + 1] = a[j];
      j--;
    }

    // Insert the current element into its correct position
    a[j + 1] = current_element;
  }

  // Print the sorted array
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}