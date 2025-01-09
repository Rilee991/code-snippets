class Solution {
public:
    bool isPref(string &word, string &pref) {
        if(word.size() < pref.size())
            return false;
        
        for(int i=0;i<pref.size();i++)
            if(pref[i] != word[i])
                return false;
            
        return true;
    }

    int prefixCount(vector<string>& words, string pref) {
        int res = 0;

        for(string word: words) {
            if(isPref(word, pref))
                res++;
        }

        return res;
    }
};