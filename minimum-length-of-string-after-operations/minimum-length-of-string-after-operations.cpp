class Solution {
public:
    int minimumLength(string s) {
        // 1 - 0
        // 2 - 0
        // 3 - 2
        // 4 - 2
        // 5 - 4
        // 6 - 4
        // 7 - 6
        // 8 - 6
        vector<int> freq(26, 0);
        int res = 0;

        for(char ch: s) {
            freq[ch-'a']++;
            // cout<<ch<<"->"<<freq[ch-'a']<<"\n";
        }

        for(int i=0;i<26;i++) {
            int mul = max(0, (int)(ceil(freq[i]/2.0) - 1));
            res += (freq[i] - mul*2);
        }

        return res;
    }
};