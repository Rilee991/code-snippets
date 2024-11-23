class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> res(m, vector<char>(n, '.'));

        for(int i=0;i<n;i++) {
            deque<pair<int,int>> q;

            for(int j=m-1;j>=0;j--) {
                if(box[i][j] == '.') {
                    q.push_back({ i, j });
                    res[j][n-1-i] = '.';
                } else if(box[i][j] == '*') {
                    res[j][n-1-i] = '*';
                    q.clear();
                } else {
                    if(!q.empty()) {
                        auto p = q.front();
                        q.pop_front();
                        res[p.second][n-1-p.first] = '#';
                        q.push_back({ i, j });
                    } else {
                        res[j][n-1-i] = '#';
                    }
                }
            }
        }

        return res;
    }
};