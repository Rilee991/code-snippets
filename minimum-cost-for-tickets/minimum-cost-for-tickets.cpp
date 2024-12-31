class Solution {
public:
    int dfs(vector<int>& days, int i, int n, vector<int>& costs, vector<int> &dp) {
        if(i >= n)
            return 0;

        if(dp[i] != -1) return dp[i];

        int c1 = dfs(days, i+1, n, costs, dp) + costs[0];
        int c2Idx = lower_bound(days.begin()+i, days.end(), days[i]+7) - days.begin();
        int c2 = dfs(days, c2Idx, n, costs, dp) + costs[1];
        int c3Idx = lower_bound(days.begin()+i, days.end(), days[i]+30) - days.begin();
        int c3 = dfs(days, c3Idx, n, costs, dp) + costs[2];

        return dp[i] = min(c1, min(c2, c3));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);

        return dfs(days, 0, n, costs, dp);
    }
};