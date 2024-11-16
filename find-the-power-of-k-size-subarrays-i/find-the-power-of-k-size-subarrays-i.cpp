class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;

        for(int i=0;i<=(nums.size()-k);i++) {
            int prev = nums[i];
            int power = nums[i];

            for(int j=i+1;j<i+k;j++) {
                if(nums[j]-prev != 1) {
                    power = -1;
                    break;
                }
                power = max(power, nums[j]);
                prev = nums[j];
            }

            res.push_back(power);
        }

        return res;
    }
};