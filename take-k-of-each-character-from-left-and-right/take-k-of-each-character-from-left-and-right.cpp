class Solution {
public:
    int takeCharacters(string s, int k) {
        int lo = 3 * k, hi = s.size();
        int res = INT_MAX;

        while(lo <= hi) {
            int mid = (lo+hi)/2;
            int i = s.size() - mid, j = s.size() - 1;
            bool flag = false;
            unordered_map<char, int> mp;

            for(int t=i;t<=j;t++) {
                mp[s[t]]++;
            }

            if(mp['a'] >= k && mp['b'] >= k && mp['c'] >= k) {
                flag = true;
            }

            while(i < s.size()) {
                mp[s[i]]--;
                i++;
                j = (j+1)%(s.size());
                mp[s[j]]++;

                if(mp['a'] >= k && mp['b'] >= k && mp['c'] >= k) {
                    flag = true;
                    break;
                }
            }

            if(flag) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};