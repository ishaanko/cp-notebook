#include <iostream>
#include <vector>

/**
 * Merge Sort Implementation
 *
 * Problem Description:
 * - Sort an array of integers in ascending order using the merge sort algorithm
 * - Implementation uses recursion and the divide-and-conquer paradigm
 *
 * Algorithm:
 * - Divide the array into two halves
 * - Recursively sort each half
 * - Merge the sorted halves to produce a sorted array
 * - Time Complexity: O(n log n) where n is the number of elements
 * - Space Complexity: O(n) for the temporary arrays during merging
 *
 * Features:
 * - Stable sorting algorithm (maintains relative order of equal elements)
 * - Efficient for large datasets
 * - Predictable performance regardless of input data characteristics
 */

// Merge two sorted arrays into a single sorted array
std::vector<int> merge(std::vector<int> &l, std::vector<int> &r) {
  int n = l.size(), m = r.size();
  std::vector<int> ans;
  int i = 0, j = 0;

  // Compare elements from both arrays and take the smaller one
  while (i < n && j < m) {
    if (l[i] < r[j])
      ans.push_back(l[i++]);
    else
      ans.push_back(r[j++]);
  }

  // Add remaining elements from left array (if any)
  while (i < n)
    ans.push_back(l[i++]);

  // Add remaining elements from right array (if any)
  while (j < m)
    ans.push_back(r[j++]);

  return ans;
}

std::vector<int> array; // Global array to store input

// Recursive merge sort function
std::vector<int> merge_sort(int l, int r) {
  // Base case: single element is already sorted
  if (l == r) {
    std::vector<int> single;
    single.push_back(array[l]);
    return single;
  }

  // Divide array into two halves
  int mid = (l + r) >> 1; // Equivalent to (l + r) / 2

  // Recursively sort both halves
  std::vector<int> left = merge_sort(l, mid);
  std::vector<int> right = merge_sort(mid + 1, r);

  // Merge the sorted halves
  return merge(left, right);
}

int32_t main() {
  // Optimize input/output operations
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  // Read array size
  int n;
  std::cin >> n;

  // Initialize and read array elements
  array.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> array[i];
  }

  // Sort the array using merge sort
  std::vector<int> ans = merge_sort(0, n - 1);

  // Print the sorted array
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << ' ';
  }

  return 0;
}