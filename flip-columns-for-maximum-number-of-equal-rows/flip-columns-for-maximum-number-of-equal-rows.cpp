class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_map<string,int> freq;
        int res = 0;

        for(int i=0;i<n;i++) {
            string key = "";
            for(int j=0;j<m;j++) {
                key += to_string((matrix[i][0] == 0) ? matrix[i][j] : !matrix[i][j]);
            }

            freq[key]++;
            res = max(res, freq[key]);
        }

        return res;
    }
};