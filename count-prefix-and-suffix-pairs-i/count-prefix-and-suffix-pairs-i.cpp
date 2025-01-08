class Solution {
public:
    bool isPrefOrSuff(string &str, string &word) {
        if(str.size() > word.size())
            return false;
        
        for(int i=0;i<str.size();i++)
            if(str[i] != word[i])
                return false;
        
        for(int i=str.size()-1,j=word.size()-1;i>=0;i--,j--)
            if(str[i] != word[j])
                return false;
        
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;

        for(int i=0;i<words.size();i++) {
            for(int j=i+1;j<words.size();j++) {
                if(isPrefOrSuff(words[i], words[j]))
                    res++;
            }
        }

        return res;
    }
};