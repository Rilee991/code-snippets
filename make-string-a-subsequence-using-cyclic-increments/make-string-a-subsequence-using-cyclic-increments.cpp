class Solution {
public:
    char inc(char ch) {
        if(ch == 'z')
            return 'a';
        return (char)(ch + 1);
    }

    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;

        while(i < str1.size() && j < str2.size()) {
            if(str1[i] == str2[j] || inc(str1[i]) == str2[j]) {
                j++;
            }
            i++;
        }

        return j == str2.size();
    }
};