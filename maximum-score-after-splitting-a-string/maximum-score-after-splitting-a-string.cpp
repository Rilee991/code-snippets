class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int leftZeroes = 0;
        int leftOnes = 0;
        int res = 0;

        for(char ch: s)
            ones += (ch == '1');
        
        for(int i=0;i<s.size()-1;i++) {
            char ch = s[i];
            leftZeroes += (ch == '0');
            leftOnes += (ch == '1');

            res = max(res, leftZeroes + ones - leftOnes);
        }

        return res;
    }
};