class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int spaceIdx = 0;

        for(int i=0;i<s.size();i++) {
            if(spaceIdx < spaces.size() && i == spaces[spaceIdx]) {
                res += ' ';
                spaceIdx++;
            }

            res += s[i];
        }

        return res;
    }
};