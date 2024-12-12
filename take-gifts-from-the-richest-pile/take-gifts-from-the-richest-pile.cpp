class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0;
        priority_queue<int> pq;

        for(int gift: gifts) {
            pq.push(gift);
        }

        while(k > 0) {
            int sq = sqrt(pq.top());
            pq.pop();
            pq.push(sq);
            k--;
        }

        while(!pq.empty()) {
            sum += (long long)(pq.top());
            pq.pop();
        }
        // 100 64 25 9 4
        // 64 25 10 9 4
        // 25 10 9 8 4
        // 10 9 8 5 4
        // 3 9 8 5 4
        // 10 + 8 + 5 + 3 + 4

        return sum;
    }
};