#include <vector>
#include <algorithm>
#include <climits>

// Comparator function to sort pairs based on the second element
bool comparator(const std::vector<int>& a, const std::vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs) {
        // Step 1: Sort the pairs using the comparator function
        sort(pairs.begin(), pairs.end(), comparator);

        // Initialize the chain
        int current_end = INT_MIN;
        int longest_chain = 0;

        // Step 2: Iterate through the sorted pairs
        for (const auto& pair : pairs) {
            if (pair[0] > current_end) {
                // Update the end of the last pair in the chain
                current_end = pair[1];
                // Increment the length of the chain
                longest_chain++;
            }
        }

        return longest_chain;
    }
};
