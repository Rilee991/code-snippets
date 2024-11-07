class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int size = 0;

        for(int i=25;i>=0;i--) {
            int curr = 0;
            for(int &candidate: candidates) {
                if(candidate&(1<<i)) {
                    curr++;
                }
            }

            size = max(size, curr);
        }

        return size;
    }
};