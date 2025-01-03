class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long sum = (long)accumulate(nums.begin(), nums.end(), 0l);
        long res = 0;
        long curr = 0;

        for(int i=0;i<nums.size()-1;i++) {
            curr += (long)nums[i];

            if(curr >= sum - curr)
                res++;
        }

        return (int)res;
    }
};