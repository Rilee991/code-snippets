class Solution {
public:
    char getChar(char ch, int offset) {
        if(offset == 0)
            return ch;

        if(offset > 0) {
            int dist = 'z' - ch;

            if(offset <= dist)
                return ch + offset;

            offset -= (dist + 1);

            return 'a' + offset;
        } else {
            int dist = (ch - 'a');

            if(abs(offset) <= dist)
                return ch + offset;

            offset += (dist + 1);

            return 'z' + offset;
        }
    }

    string shiftingLetters(string &str, vector<vector<int>>& shifts) {
        // 0 1 2
        // 0 1 0 1 -2
        vector<int> pref(str.size()+1, 0);
        string res = "";

        for(vector<int> shift: shifts) {
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];

            if(dir == 0) {
                pref[start] -= 1;
                pref[end+1] += 1;
            } else {
                pref[start] += 1;
                pref[end+1] -= 1;
            }
        }

        for(int i=0;i<pref.size()-1;i++) {
            pref[i] = (pref[i] + (i-1 >= 0 ? pref[i-1] : 0))%26;

            res += getChar(str[i], pref[i]);
            // cout<<i<<" "<<pref[i]<<" "<<res[i]<<"\n";
        }
        
        return res;
    }
};