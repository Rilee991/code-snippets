class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int,int>> st;
        vector<int> marked(nums.size(), 0);
        long long score = 0;

        for(int i=0;i<nums.size();i++) {
            st.insert({ nums[i], i });
        }

        while(!st.empty()) {
            while(!st.empty() && marked[(*st.begin()).second]) {
                st.erase(st.begin());
            }

            if(st.empty())
                break;

            auto numIdxPair = *st.begin();
            st.erase(st.begin());

            int num = numIdxPair.first;
            int idx = numIdxPair.second;

            score += (long long)num;
            marked[idx] = 1;
            if(idx-1 >= 0)  marked[idx-1] = 1;
            if(idx+1 < nums.size()) marked[idx+1] = 1;
        }

        return score;
    }
};