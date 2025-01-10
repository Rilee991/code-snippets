class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // a1b1c1e1f1k1o2, a1e1l1p2, a2m1n1o1z1, c1d1e3l1o1t1, e1g2l1o2
        // e1, o1
        unordered_map<char,int> mp2;
        vector<string> res;

        for(string &word: words2) {
            unordered_map<char,int> counter;
            for(char ch: word) {
                counter[ch]++;

                if(mp2[ch] < counter[ch])
                    mp2[ch] = counter[ch];
            }
        }

        for(string &word: words1) {
            unordered_map<char,int> counter;
            for(char ch: word) {
                counter[ch]++;
            }

            bool flag = true;

            for(auto it: mp2) {
                if(counter[it.first] < it.second) {
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