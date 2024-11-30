class Solution {
public:
    void dfs(map<int,vector<int>> &adj, map<int,pair<int,int>> &degrees, int node, stack<int> &path) {
        while(degrees[node].second > 0) {
            degrees[node].second -= 1;
            dfs(adj, degrees, adj[node][degrees[node].second], path);
        } 
        // else {
            // cout<<"Node: "<<node<<"\n";
            path.push(node);
        // }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int,vector<int>> adj;
        map<int,pair<int,int>> degrees;
        stack<int> path;
        vector<vector<int>> res;
        int start;

        for(vector<int> &pair: pairs) {
            int u = pair[0];
            int v = pair[1];

            adj[u].push_back(v);
            degrees[u].second++;
            degrees[v].first++;
            start = u;
        }

        for(auto it: degrees) {
            if(it.second.second-it.second.first == 1)
                start = it.first;
        }

        dfs(adj, degrees, start, path);

        while(!path.empty()) {
            int u = path.top();
            path.pop();

            if(path.empty())
                break;

            int v = path.top();
            res.push_back({ u, v });
        }

        return res;
    }
};