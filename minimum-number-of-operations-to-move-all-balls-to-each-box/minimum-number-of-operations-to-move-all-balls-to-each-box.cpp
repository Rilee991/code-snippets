class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.size(), 0);
        int balls = 0, moves = 0;

        for(int i=0;i<boxes.size();i++) {
            res[i] += balls + moves;

            moves += balls;

            if(boxes[i] == '1')
                balls++;
            
        }

        balls = moves = 0;

        for(int i=boxes.size()-1;i>=0;i--) {
            res[i] += balls + moves;

            moves += balls;

            if(boxes[i] == '1')
                balls++;
            
        }

        return res;
    }
};