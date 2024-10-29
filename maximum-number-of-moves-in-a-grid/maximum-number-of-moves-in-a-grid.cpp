class Solution {
public:
    bool isValid(int row, int col, vector<vector<int>>& grid) {
        if(row-1 >= 0 && grid[row-1][col-1] < grid[row][col])
            return true;
        if(row >= 0 && grid[row][col-1] < grid[row][col])
            return true;
        if(row+1 < grid.size() && grid[row+1][col-1] < grid[row][col])
            return true;
        
        return false;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // vector<vector<bool>> ways(n, vector<bool>(m, true));
        int res = 0;

        for(int col=1;col<m;col++) {
            for(int row=0;row<n;row++) {
                if(!isValid(row, col, grid)) {
                    grid[row][col] = INT_MAX;
                } else {
                    res = max(res, col);
                }
            }
        }

        return res;
    }
};