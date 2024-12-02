class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word = "";
        int curr = 1;

        for(char ch: sentence) {
            if(ch == ' ') {
                bool isValid = true;
                for(int i=0;i<searchWord.size();i++) {
                    if(i == word.size() || word[i] != searchWord[i]) {
                        isValid = false;
                        break;
                    }
                }

                if(isValid) return curr;

                word = "";
                curr++;
            } else {
                word += ch;
            }
        }

        bool isValid = true;
        for(int i=0;i<searchWord.size();i++) {
            if(i == word.size() || word[i] != searchWord[i]) {
                isValid = false;
                break;
            }
        }

        if(isValid) return curr;

        return -1;
    }
};