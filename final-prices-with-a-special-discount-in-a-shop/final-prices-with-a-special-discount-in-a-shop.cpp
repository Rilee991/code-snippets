class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // 8 4 6 2 3
        // 4 2 4 2 3
        // 0 2 4 8

        stack<int> st;
        vector<int> res(prices.size());

        st.push(0);

        for(int i=prices.size()-1;i>=0;i--) {
            while(st.top() > prices[i])
                st.pop();
            
            res[i] = prices[i] - st.top();
            st.push(prices[i]);
        }

        return res;
    }
};