class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        unordered_map<int,bool> mp;
        // int spaceIdx = 0;

        for(int sp: spaces)
            mp[sp] = 1;

        // sort(spaces.begin(), spaces.end());

        for(int i=0;i<s.size();i++) {
            if(mp[i]) {
                res += ' ';
                // spaceIdx++;
            }

            res += s[i];
        }

        return res;
    }
};