class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<tuple<int,int>> pq;

        for(int i=0;i<nums.size();i++)
            pq.push({ -nums[i], -i });
        
        while(k--) {
            int num = get<0>(pq.top());
            int idx = get<1>(pq.top());

            pq.pop();

            pq.push({ num*multiplier, idx });
        }

        while(!pq.empty()) {
            int num = -get<0>(pq.top());
            int idx = -get<1>(pq.top());

            nums[idx] = num;
            pq.pop();
        }

        return nums;
    }
};