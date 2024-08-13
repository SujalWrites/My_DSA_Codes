class Solution {
public:
    void find(int idx, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < arr.size(); ++i) {
            if (i > idx && arr[i] == arr[i - 1]) continue; // Skip duplicates
            if (arr[i] > target) break; // Stop if the current element is greater than the remaining target

            ds.push_back(arr[i]);
            find(i + 1, target - arr[i], arr, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& ARR, int B) {
        sort(ARR.begin(), ARR.end());
        vector<vector<int>> ans;
        vector<int> ds;
        find(0, B, ARR, ds, ans);
        return ans;
    }
};