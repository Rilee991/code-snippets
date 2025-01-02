class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // 1 0 1 1 1
        // 0 1 1 2 3 4
        vector<int> pref(words.size()+1, 0);
        vector<int> res;

        for(int i=0;i<words.size();i++) {
            int len = words[i].size();
            pref[i+1] = pref[i] + (isVowel(words[i][0]) && isVowel(words[i][len-1]));
        }

        for(vector<int> query: queries) {
            int start = query[0];
            int end = query[1];

            res.push_back(pref[end+1]-pref[start]);
        }

        return res;
    }
};