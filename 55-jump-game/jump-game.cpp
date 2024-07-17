class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n=arr.size();
        int maxIndex=0;
        for(int i=0;i<n;i++){
            if(i>maxIndex) return false;
            maxIndex=max(maxIndex,arr[i]+i);
        }
        return true;
    }
};