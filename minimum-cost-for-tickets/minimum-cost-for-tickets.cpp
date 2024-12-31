class Solution {
public:
    int dfs(vector<int>& days, vector<int>& costs, int n) {
        if(n <= 0)
            return 0;

        int sIdx = lower_bound(days.begin(), days.end(), days[n-1]-7) - days.begin();
        int tIdx = lower_bound(days.begin(), days.end(), days[n-1]-30) - days.begin();

        if(days[n-1] - days[sIdx] < 7)
            sIdx--;
        if(days[n-1] - days[tIdx] < 30)
            tIdx--;
        
        cout<<"n:"<<n<<"\n";
        cout<<"sIdx:"<<sIdx<<", tIdx:"<<tIdx<<"\n";

        int oneDay = costs[0] + dfs(days, costs, n-1);
        int sevenDay = costs[1] + dfs(days, costs, sIdx+1);
        int thirtyDay = costs[2] + dfs(days, costs, tIdx+1);
        cout<<"oneDay:"<<oneDay<<", sevenDay:"<<sevenDay<<", thirtyDay:"<<thirtyDay<<"\n";

        return min(oneDay, min(sevenDay, thirtyDay));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return dfs(days, costs, days.size());
    }
};