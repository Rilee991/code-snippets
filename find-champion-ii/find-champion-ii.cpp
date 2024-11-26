class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> ind(n, 0);
        int res = -1;

        for(vector<int> edge: edges) {
            int u = edge[0], v = edge[1];

            ind[v]++;
        }

        for(int i=0;i<n;i++) {
            if(ind[i] == 0) {
                if(res == -1)
                    res = i;
                else
                    return -1;
            }
        }

        return res;
    }
};