class Solution {
public:
    bool isValid(vector<int> &nums, int maxOps, int maxVal) {
        int ops = 0;

        for(int i=0;i<nums.size();i++) {
            if(nums[i] > maxVal) {
                ops += (ceil(nums[i]/(maxVal*1.0)) - 1);
            }

            if(ops > maxOps)
                return false;
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOps) {
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        int res = hi;

        while(lo <= hi) {
            int mid = (lo+hi)/2;

            if(isValid(nums, maxOps, mid)) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return res;
    }
};