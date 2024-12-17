class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>> pq;
        unordered_map<char,int> mp;
        string res = "";

        for(int r=0;r<s.size();r++) {
            mp[s[r]]++;
        }

        for(auto it: mp) {
            pq.push({ it.first, it.second });
        }
        // c-1, a-1
        // zzccca

        while(!pq.empty()) {
            char ch = pq.top().first;
            int fr = pq.top().second;

            pq.pop();

            res += string(min(fr, repeatLimit), ch);
            
            if(fr > repeatLimit) {
                if(pq.empty())
                    break;
                char ch2 = pq.top().first;
                int fr2 = pq.top().second;
                res += ch2;
                pq.pop();
                
                if(fr2 > 1)
                    pq.push({ ch2, fr2-1 });
                pq.push({ ch, fr-repeatLimit });
            }
        }

        return res;
    }
};