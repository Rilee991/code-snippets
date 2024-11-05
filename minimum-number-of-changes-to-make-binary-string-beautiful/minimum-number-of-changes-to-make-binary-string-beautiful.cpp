class Solution {
public:
    int minChanges(string s) {
        // 100101010111101010111000
        // 
        int res = 0;

        for(int i=1;i<s.size();i+=2) {
            if(s[i] != s[i-1]) {
                res++;
            }
        }

        return res;
    }
};