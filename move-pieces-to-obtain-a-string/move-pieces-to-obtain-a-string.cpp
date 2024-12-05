class Solution {
public:
    bool canChange(string s, string t) {
        int n = s.size();
        int i = 0, j = 0;

        while(i < n && j < n) {
            // LL(1), LR(0), L_(0), RR(1), RL(0), R_(0/1), __(1), _L(0/1), _R(0)
            if(s[i] == t[j]) {
                i++;
                j++;
            } else if((s[i] == 'L' && t[j] == 'R') || (s[i] == 'R' && t[j] == 'L') || (s[i] == 'L' && t[j] == '_') || (s[i] == '_' && t[j] == 'R')) {
                return false;
            } else if(s[i] == '_' && t[j] == 'L') {
                while(i < n && s[i] == '_')
                    i++;
                if(i == n || s[i] == 'R')
                    return false;
                swap(s[i], s[j]);
                i = j;
                i++;
                j++;
            } else {
                i++;
                while(i < n && s[i] != '_') {
                    if(s[i] == 'L')
                        return false;
                    i++;
                }

                if(i == n)
                    return false;
                swap(s[i], s[j]);
                i = j;
                i++;
                j++;
            }
        }

        if(i < n || j < n)
            return false;
        return true;
    }
};