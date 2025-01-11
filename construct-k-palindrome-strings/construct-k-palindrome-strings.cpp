class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)    return false;
        if(s.size() == k)   return true;
        // a - 2, n - 2, b - 1, e - 2, l - 2

        vector<int> freq(26, 0);
        int odd = 0;

        for(char ch: s)
            freq[ch-'a']++;

        for(int f: freq)
            if(f&1) odd++;
        
        if(odd > k) return false;

        return true;
        // 1, ab, aa
        // 2, aaa, aab, abc
        // 
    }
};