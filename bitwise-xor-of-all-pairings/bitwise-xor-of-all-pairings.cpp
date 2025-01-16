class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;

        if((nums1.size()&1) && (nums2.size()&1)) {
            for(int i=0;i<nums1.size();i++)
                res = res ^ nums1[i];
            for(int i=0;i<nums2.size();i++)
                res = res ^ nums2[i];
        } else if(nums1.size()&1) {
            for(int i=0;i<nums2.size();i++)
                res = res ^ nums2[i];
        } else if(nums2.size()&1) {
            for(int i=0;i<nums1.size();i++)
                res = res ^ nums1[i];
        }

        return res;
    }
};