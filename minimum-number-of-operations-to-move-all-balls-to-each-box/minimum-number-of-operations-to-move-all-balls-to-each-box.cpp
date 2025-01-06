class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.size(), 0);

        for(int i=0;i<res.size();i++) {
            for(int j=0;j<boxes.size();j++) {
                if(boxes[j] == '1') {
                    res[i] += abs(j-i);
                }
            }
        }

        return res;
    }
};