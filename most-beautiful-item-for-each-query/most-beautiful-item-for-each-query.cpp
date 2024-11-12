class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        unordered_map<int,int> mp;
        vector<int> res;

        for(vector<int> &item: items) {
            int price = item[0];
            int beauty = item[1];

            mp[price] = max(mp[price], beauty);
        }

        vector<vector<int>> uniqItems;

        for(auto it: mp)
            uniqItems.push_back({ it.first, it.second });
        
        sort(uniqItems.begin(), uniqItems.end());
        int maxBeauty = uniqItems[0][1];

        for(int i=1;i<uniqItems.size();i++) {
            maxBeauty = max(maxBeauty, uniqItems[i][1]);
            uniqItems[i][1] = maxBeauty;
        }

        for(int query: queries) {
            int lo = 0, hi = uniqItems.size()-1;
            int index = -1;

            while(lo <= hi) {
                int mid = (lo+hi)/2;

                if(uniqItems[mid][0] <= query) {
                    index = mid;
                    lo = mid+1;
                } else {
                    hi = mid - 1;
                }
            }
            
            res.push_back(index != -1 ? uniqItems[index][1] : 0);
        }

        return res;
    }
};