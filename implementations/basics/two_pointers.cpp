#include <iostream>
#include <vector>

/**
 * Two Pointers Algorithm - Subarray Sum
 *
 * Problem Description:
 * - Given an array of n positive integers and a target sum s
 * - Count the number of subarrays whose sum does not exceed s
 *
 * Algorithm:
 * - Uses the two-pointer technique to efficiently count valid subarrays
 * - Maintains a sliding window with left (l) and right (r) pointers
 * - For each left pointer position, extends the right pointer as far as
 *   possible while keeping the sum <= s
 * - Time Complexity: O(n) - each element is added and removed at most once
 * - Space Complexity: O(n) - for storing the input array
 *
 * Example application:
 * - Finding subarrays with constraints on their sums
 * - Sliding window problems with cumulative property checks
 */
int main() {
  // Fast input/output
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  // Read array size and target sum
  int n;
  long long s;
  std::cin >> n >> s;

  // Read array elements (1-indexed for simplicity)
  std::vector<int> array(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> array[i];
  }

  // Count valid subarrays
  long long validSubarrays = 0;

  // Initialize right pointer and current sum
  int rightPtr = 1;
  long long currentSum = 0;

  // For each possible left pointer position
  for (int leftPtr = 1; leftPtr <= n; leftPtr++) {
    // Extend the right pointer as far as possible
    while (rightPtr <= n && currentSum + array[rightPtr] <= s) {
      currentSum += array[rightPtr];
      rightPtr++;
    }

    // Count valid subarrays starting at leftPtr
    // rightPtr - 1 is the maximum index i such that sum of array[leftPtr...i]
    // is <= s
    validSubarrays += rightPtr - leftPtr;

    // Remove the leftPtr element as we slide the window
    currentSum -= array[leftPtr];
  }

  // Output the result
  std::cout << validSubarrays << '\n';

  return 0;
}