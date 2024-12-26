class Solution {
public:
    int dfs(vector<int> &nums, int n, int target) {
        if(n == 0) {
            return target == 0;
        }

        int add = dfs(nums, n-1, target-nums[n-1]);
        int sub = dfs(nums, n-1, target+nums[n-1]);

        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, nums.size(), target);
    }
};