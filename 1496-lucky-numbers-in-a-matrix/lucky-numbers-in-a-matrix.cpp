class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int rminMax=INT_MIN;
        for(int i=0;i<m;i++){
            int rMin=INT_MAX;
            for(int j=0;j<n;j++){
                rMin=min(rMin,matrix[i][j]);
            }
            rminMax=max(rminMax,rMin);
        }
        int cmaxMin=INT_MAX;
        for(int i=0;i<n;i++){
            int cMax=INT_MIN;
            for(int j=0;j<m;j++){
                cMax=max(cMax,matrix[j][i]);
            }
            cmaxMin=min(cmaxMin,cMax);
        }
        if(rminMax==cmaxMin){
            return {rminMax};
        }
        return {};
    }
};