class Solution {
    vector<map<int,int>> dp;
public:
    int dfs(vector<int> &nums, int n, int target) {
        if(n == 0) {
            return target == 0;
        }

        if(dp[n].find(target) != dp[n].end())
            return dp[n][target];

        int add = dfs(nums, n-1, target-nums[n-1]);
        int sub = dfs(nums, n-1, target+nums[n-1]);

        return dp[n][target] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        dp.resize(nums.size()+1);
        return dfs(nums, nums.size(), target);
    }
};