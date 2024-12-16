class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double,int>> pq;
        double sum = 0.0;

        for(int i=0;i<classes.size();i++) {
            int pass = classes[i][0];
            int total = classes[i][1];
            double passRatio = (pass*1.0)/(total*1.0);
            double newPassRatio = ((pass+1)*1.0)/((total+1)*1.0);
            double increment = newPassRatio - passRatio;

            pq.push({ increment, i });
        }

        while(extraStudents--) {
            auto tp = pq.top();
            double increment = get<0>(tp);
            int idx = get<1>(tp);
            pq.pop();

            classes[idx][0] += 1;
            classes[idx][1] += 1;

            int pass = classes[idx][0];
            int total = classes[idx][1];
            double passRatio = (pass*1.0)/(total*1.0);
            double newPassRatio = ((pass+1)*1.0)/((total+1)*1.0);
            double newIncrement = newPassRatio - passRatio;

            pq.push({ newIncrement, idx });
        }

        for(int i=0;i<classes.size();i++) {
            int pass = classes[i][0];
            int total = classes[i][1];
            double passRatio = (pass*1.0)/(total*1.0);

            sum += passRatio;
        }

        return sum/classes.size();
    }
};