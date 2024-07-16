// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         int n=g.size();
//         int m=s.size();
//         sort(g.begin(),g.end());
//         sort(s.begin(),s.end());
//         int l=0;
//         int r=0;
//         while(l<n && r<m){
//             if(g[l]<=s[r]){
//                 r++;
//                 l++;
//             }
//             l++;
//         }
//         return r;
//     }
// };
#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        int contentChildren = 0;
        int childIndex = 0;
        int cookieIndex = 0;
        
        while (childIndex < g.size() && cookieIndex < s.size()) {
            if (s[cookieIndex] >= g[childIndex]) {
                contentChildren++;
                childIndex++;
            }
            cookieIndex++;
        }
        
        return contentChildren;
    }
};
