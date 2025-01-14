class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> freq(51, 0);
        vector<int> res(A.size(), 0);
        int common = 0;
        // 

        for(int i=0;i<A.size();i++) {
            freq[A[i]]++;
            if(freq[A[i]] == 2) common++;

            freq[B[i]]++;
            if(freq[B[i]] == 2) common++;

            res[i] = common;
        }
        // 0 1 2 3 4
        // 0 2 2 2 0
        // 0 2 0 0

        return res;
    }
};