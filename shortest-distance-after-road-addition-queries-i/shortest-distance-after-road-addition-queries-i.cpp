class Solution {
public:
    int bfs(vector<vector<int>> adj, int src, int dest) {
        queue<pair<int,int>> q;
        vector<int> vis(adj.size(), 0);

        q.push({ src, 0 });
        vis[src] = 1;

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            int node = p.first;
            int dist = p.second;

            if(node == dest)
                return dist;
            
            for(int nbr: adj[node]) {
                if(vis[nbr] == 0) {
                    vis[nbr] = 1;
                    q.push({ nbr, dist + 1 });
                }
            }
        }

        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> res;

        for(int i=0;i<n;i++) {
            if(i != n-1)
                adj[i].push_back(i+1);
        }

        for(vector<int> &query: queries) {
            int u = query[0];
            int v = query[1];

            adj[u].push_back(v);
            int minDist = bfs(adj, 0, n-1);
            res.push_back(minDist);
        }

        return res;
    }
};