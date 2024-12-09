class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> maxLen(n, 1);
        vector<bool> res;

        for(int i=1;i<n;i++) {
            maxLen[i] += ((nums[i]&1) == (nums[i-1]&1) ? 0 : maxLen[i-1]);
        }
        // 4 3 1 6
        // 1 2 1 2

        for(vector<int> &query: queries) {
            int s = query[0], e = query[1];

            if((e-s+1) <= maxLen[e])
                res.push_back(true);
            else
                res.push_back(false);
        }

        return res;
    }
};