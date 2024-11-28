class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<tuple<int,int,int>> pq;
        int dx[4] = { 0, 0, 1, -1 };
        int dy[4] = { 1, -1, 0, 0 };

        pq.push({ 0, 0, 0 });
        vis[0][0] = 1;

        while(!pq.empty()) {
            int cost = abs(get<0>(pq.top()));
            int x = get<1>(pq.top());
            int y = get<2>(pq.top());

            pq.pop();

            if(x == n-1 && y == m-1)
                return cost;
            
            for(int i=0;i<4;i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY]) {
                    vis[newX][newY] = 1;
                    pq.push({ -(cost + grid[newX][newY]), newX, newY });
                }
            }
        }

        return -1;
    }
};