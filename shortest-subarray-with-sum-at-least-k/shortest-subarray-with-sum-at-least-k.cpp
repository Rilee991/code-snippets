class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int res = INT_MAX;
        long curr = 0;
        deque<pair<long,int>> q;

        for(int r=0;r<nums.size();r++) {
            curr += (long)nums[r];

            if(curr >= k)
                res = min(res, r+1);
            
            while(!q.empty() && (curr - q.front().first) >= k) {
                auto fr = q.front();
                q.pop_front();
                res = min(res, r-fr.second);
            }

            while(!q.empty() && (q.back().first >= curr))
                q.pop_back();

            q.push_back({ curr, r });
        }

        return res == INT_MAX ? -1 : res;
    }
};