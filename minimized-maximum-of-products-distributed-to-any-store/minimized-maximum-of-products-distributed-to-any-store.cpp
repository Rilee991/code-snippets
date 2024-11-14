class Solution {
public:
    bool isValid(int stores, vector<int> &quantities, int limit) {
        if(limit == 0)
            return false;

        int assigned = 0;

        for(int &quantity: quantities) {
            int shops = (quantity/limit);
            assigned += shops;

            if(quantity%limit != 0)
                assigned++;
        }

        return assigned <= stores;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 0, hi = *max_element(quantities.begin(), quantities.end());
        int res = INT_MAX;

        while(lo <= hi) {
            int mid = (lo+hi)/2;

            if(isValid(n, quantities, mid)) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return res;
    }
};