class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maxBit) {
        int xorValue = 0;
        int maxValue = (1<<maxBit)-1;
        int last = nums.size()-1;
        vector<int> res;

        for(int &num: nums)
            xorValue ^= num;
        
        for(int &num: nums) {
            int xorOpp = xorValue ^ maxValue;
            res.push_back(xorOpp);
            xorValue ^= nums[last--];
        }

        return res;
    }
};