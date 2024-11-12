class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> res;

        sort(items.begin(), items.end());
        int maxBeauty = items[0][1];

        for(int i=1;i<items.size();i++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        for(int query: queries) {
            int lo = 0, hi = items.size()-1;
            int index = -1;

            while(lo <= hi) {
                int mid = (lo+hi)/2;

                if(items[mid][0] <= query) {
                    index = mid;
                    lo = mid+1;
                } else {
                    hi = mid - 1;
                }
            }
            
            res.push_back(index != -1 ? items[index][1] : 0);
        }

        return res;
    }
};