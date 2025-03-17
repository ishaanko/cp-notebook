#include <algorithm>
#include <climits>
#include <iostream>

/**
 * Problem: Contest Problem Selection
 *
 * This program solves a problem about selecting contest problems.
 *
 * Problem Description:
 * - Given n problems with difficulties c[i]
 * - Need to select a subset of problems such that:
 *   1. At least 2 problems are selected
 *   2. Total difficulty is between l and r
 *   3. Difference between max and min difficulty is at least x
 *
 * Algorithm:
 * - Uses bitmasks to generate all 2^n possible subsets of problems
 * - For each subset, checks if it satisfies all conditions
 * - Time Complexity: O(2^n * n) where n is the number of problems
 * - Space Complexity: O(n)
 */
int main() {
  // Input parameters
  int n, l, r, x;
  std::cin >> n >> l >> r >> x;

  // Array to store difficulties of each problem
  int difficulties[n];
  for (int i = 0; i < n; i++) {
    std::cin >> difficulties[i];
  }

  // Count valid subsets
  int validSubsets = 0;

  // Generate all possible subsets using bitmasks
  for (int mask = 0; mask < (1 << n); mask++) {
    // Variables to track subset properties
    int selectedProblems = 0;
    int totalDifficulty = 0;
    int minDifficulty = INT_MAX;
    int maxDifficulty = 0;

    // Check each bit in the mask
    for (int i = 0; i < n; i++) {
      // If ith bit is set, include the ith problem
      if ((mask >> i) & 1) {
        selectedProblems++;
        totalDifficulty += difficulties[i];
        minDifficulty = std::min(minDifficulty, difficulties[i]);
        maxDifficulty = std::max(maxDifficulty, difficulties[i]);
      }
    }

    // Check if the subset satisfies all conditions
    if (selectedProblems >= 2 && totalDifficulty >= l && totalDifficulty <= r &&
        (maxDifficulty - minDifficulty) >= x) {
      validSubsets++;
    }
  }

  // Output the result
  std::cout << validSubsets << '\n';

  return 0;
}