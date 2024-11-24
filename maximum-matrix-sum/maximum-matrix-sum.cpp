class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int minEle = INT_MAX;
        bool oddNegInts = false;
        // int zeroes = 0;

        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                if(matrix[i][j] <= 0) {
                    oddNegInts = !oddNegInts;
                }

                minEle = min(minEle, abs(matrix[i][j]));
                res += abs(matrix[i][j]);
            }
        }

        if(!oddNegInts)
            return res;
        
        return res - 2 * minEle;
    }
};