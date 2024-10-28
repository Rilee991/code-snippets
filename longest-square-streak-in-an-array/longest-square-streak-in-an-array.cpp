class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // 2 3 4 6 8 16
        sort(nums.begin(), nums.end());
        unordered_map<int,int> numFreqMap;
        int res = 0;

        for(int num: nums) {
            int sqrtNum = sqrt(num);

            if(sqrtNum * sqrtNum == num && numFreqMap.find(sqrtNum) != numFreqMap.end()) {
                numFreqMap[num] = numFreqMap[sqrtNum] + 1;
            } else {
                numFreqMap[num] = 1;
            }

            res = max(res, numFreqMap[num]);
        }

        return res > 1 ? res : -1;
    }
};