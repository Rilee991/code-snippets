class Solution {
public:
    bool exists(string &s, int len) {
        map<string,int> mp;
        string str = "";
        int strlen = 0;
        cout<<"len:"<<len<<"\n";

        // aaaa
        // 0123
        //    i
        // str="aa"
        // mp=aa->1
        for(int i=0;i<s.size();i++) {
            if(strlen == 0) {
                str += s[i];
                strlen = 1;
                continue;
            }

            if(strlen < len) {
                if(str[strlen-1] != s[i]) {
                    str = "";
                    strlen = 0;
                }
                
                str += s[i];
                strlen++;
                cout<<"i:"<<i<<"\n";
                cout<<"str:"<<str<<"\n";
            } else {
                mp[str]++;
                cout<<"str:"<<str<<"\n";
                cout<<"mp[str]:"<<mp[str]<<"\n";

                if(mp[str] > 2)
                    return true;
                
                if(str[strlen-1] != s[i]) {
                    str = "";
                    strlen = 0;
                    str += s[i];
                    strlen++;
                } else {
                    str += s[i];
                    str = str.substr(1, len);
                }
                cout<<"i:"<<i<<"\n";
                cout<<"str:"<<str<<"\n";
            }
        }

        mp[str]++;
        if(mp[str] > 2)
            return true;

        return false;
    }
// cccerrrecdcdccedecdcccddeeeddcdcddedccdceeedccecde
    int maximumLength(string s) {
        int n = s.size();
        int lo = 1, hi = n - 2;
        int res = -1;

        while(lo <= hi) {
            int mid = (lo+hi)/2;

            if(exists(s, mid)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return res;
    }
};