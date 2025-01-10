class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // a1b1c1e1f1k1o2, a1e1l1p2, a2m1n1o1z1, c1d1e3l1o1t1, e1g2l1o2
        // e1, o1
        vector<int> mp2(26, 0);
        vector<string> res;

        for(string &word: words2) {
            vector<int> counter(26, 0);
            for(char ch: word) {
                counter[ch-'a']++;

                if(mp2[ch-'a'] < counter[ch-'a'])
                    mp2[ch-'a'] = counter[ch-'a'];
            }
        }

        for(string &word: words1) {
            vector<int> counter(26, 0);
            for(char ch: word) {
                counter[ch-'a']++;
            }

            bool flag = true;

            for(int i=0;i<26;i++) {
                if(counter[i] < mp2[i]) {
                    flag = false;
                    break;
                }
            }

            if(flag)
                res.push_back(word);
        }

        return res;
    }
};