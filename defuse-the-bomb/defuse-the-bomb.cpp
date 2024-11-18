class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        int start = k > 0 ? 1 : n - abs(k);
        int end = k > 0 ? k : n - 1;
        int sum = 0;
        int idx = 0;
        vector<int> res(n, 0);

        if(k == 0)  return res;

        for(int i=start;i<=end;i++)
            sum += code[i];
        
        res[idx++] = sum;

        while(idx < n) {
            sum -= code[start];

            start = (start + 1)%n;
            end = (end + 1)%n;

            sum += code[end];
            res[idx++] = sum;
        }

        return res;
    }
};