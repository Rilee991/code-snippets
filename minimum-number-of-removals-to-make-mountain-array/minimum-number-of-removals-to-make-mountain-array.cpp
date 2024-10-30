class Solution {
public:

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> lds(n, 1);
        int res = INT_MAX;

        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[j] < nums[i])
                    lis[i] = max(lis[i], lis[j] + 1);
            }

            int revI = n-1-i;

            for(int j=n-1;j>revI;j--) {
                if(nums[j] < nums[revI])
                    lds[revI] = max(lds[revI], lds[j] + 1);
            }

            cout<<lis[i]<<" "<<lds[revI]<<"\n";
        }

        for(int i=0;i<n;i++) {
            if(lis[i] != 1 && lds[i] != 1)
                res = min(res, n - (lis[i] + lds[i] - 1));
        }

        return res;
    }
};