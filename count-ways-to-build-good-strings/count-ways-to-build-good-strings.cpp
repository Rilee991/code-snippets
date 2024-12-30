class Solution {
    int M = 1e9+7;
    vector<int> dp;
public:
    int dfs(int low, int high, int zero, int one, int len) {
        if(len > high)
            return 0;
        
        if(dp[len] != -1)
            return dp[len];
        
        int zCount = dfs(low, high, zero, one, len+zero)%M;
        int oCount = dfs(low, high, zero, one, len+one)%M;

        if(len >= low)
            zCount++;
        
        return dp[len] = (zCount%M + oCount)%M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high+1, 0);

        for(int i=high;i>=0;i--) {
            int zCount = i+zero > high ? 0 : dp[i+zero]%M;
            int oCount = i+one > high ? 0 : dp[i+one]%M;

            if(i >= low)
                zCount++;
            
            dp[i] = (zCount%M + oCount)%M;
        }

        return dp[0];
    }
};