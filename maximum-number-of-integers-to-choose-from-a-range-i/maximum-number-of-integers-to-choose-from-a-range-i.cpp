class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool> nums(1e4+2, 0);
        int res = 0;
        int sum = 0;
        int num = 1;

        for(int b: banned)
            nums[b] = 1;
        
        while(num <= n) {
            if(nums[num]) {
                num++;
                continue;
            }

            // cout<<num<<" ";
            if(sum + num <= maxSum) {
                sum += num;
                num++;
                res++;
            } else {
                break;
            }
        }

        return res;
    }
};