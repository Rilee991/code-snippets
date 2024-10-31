class Solution {
    vector<vector<long long>> dp;
public:
    long long dfs(vector<int>& robot, int n, vector<int>& factories, int m) {
        if(n == 0)
            return 0;
        if(m == 0)
            return 1e13;

        if(dp[n][m] != -1)
            return dp[n][m];
        
        long long place = dfs(robot, n-1, factories, m-1) + abs(robot[n-1]-factories[m-1]);
        long long noPlace = dfs(robot, n, factories, m-1);

        return dp[n][m] = min(place, noPlace);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> factories;

        for(vector<int> &fact: factory) {
            int pos = fact[0];
            int lim = fact[1];

            while(lim--) {
                factories.push_back(pos);
            }
        }

        sort(robot.begin(), robot.end());
        sort(factories.begin(), factories.end());

        dp.resize(robot.size()+1, vector<long long>(factories.size()+1, -1));

        return dfs(robot, robot.size(), factories, factories.size());
    }
};