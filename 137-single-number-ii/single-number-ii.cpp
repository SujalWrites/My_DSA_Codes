class Solution {
public:
    int singleNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n =arr.size();
        for(int i=1;i<n;i=i+3){
            if(arr[i]!=arr[i-1]){
                return arr[i-1];
            }
        }
        return arr[n-1];
    }
};