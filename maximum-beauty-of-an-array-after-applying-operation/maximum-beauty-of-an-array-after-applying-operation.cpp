class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        int l=0;

        for(int r=0;r<n;r++) {
            while(nums[r]-nums[l] > 2*k)
                l++;
            
            res = max(res, r-l+1);
        }

        return res;
    }
};