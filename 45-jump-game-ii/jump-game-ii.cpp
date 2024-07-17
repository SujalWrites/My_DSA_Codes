class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            
            // If we have come to the end of the current jump range
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;

                // If the current end is already at or beyond the last index, we're done
                if (currentEnd >= n - 1) break;
            }
        }

        // If we cannot reach the end
        // if (currentEnd < n - 1) return -1;

        return jumps;
    }
};
