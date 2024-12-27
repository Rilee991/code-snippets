class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = INT_MIN;
        int maxVal = values[0]-1;

        for(int i=1;i<values.size();i++) {
            res = max(res, values[i]+maxVal);
            maxVal = max(maxVal, values[i])-1;
        }

        return res;
    }
};