class Solution {
public:
    int getLowerLimit(vector<int> &nums, int limit, int lo, char type) {
        int hi = nums.size() - 1;
        int index = (type == 'L' ? 1e6 : -1);

        while(lo <= hi) {
            int mid = (lo+hi)/2;

            if(nums[mid] > limit) {
                if(type == 'L') index = mid;
                hi = mid - 1;
            } else if(nums[mid] == limit) {
                index = mid;
                if(type == 'L') hi = mid - 1;
                else lo = mid + 1;
            } else {
                if(type != 'L') index = mid;
                lo = mid + 1;
            }
        }

        return index;
    }

    int getUpperLimit(vector<int> &nums, int limit, int lo) {
        int hi = nums.size() - 1;
        int index = -1;

        while(lo <= hi) {
            int mid = (lo+hi)/2;

            if(nums[mid] <= limit) {
                index = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return index;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size();i++) {
            int lowLimit = getLowerLimit(nums, lower - nums[i], i+1, 'L');
            int upLimit = getLowerLimit(nums, upper - nums[i], i+1, 'U');
            // cout<<"num:"<<nums[i]<<", lolim:"<<lowLimit<<", upLim:"<<upLimit<<"\n";

            res += max(0, (upLimit - lowLimit + 1));
        }

        return res;
    }
};