class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() < 3)
            return s;
        
        int n = s.size();
        string res = s.substr(0,2);
        
        for(int i=2;i<n;i++) {
            if(s[i] != res[res.size()-1] || s[i] != res[res.size()-2])
                res += s[i];
        }

        return res;
    }
};