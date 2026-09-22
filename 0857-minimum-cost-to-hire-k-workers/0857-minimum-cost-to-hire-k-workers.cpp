class Solution {
public:

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        if (quality.size() < 1 || wage.size() < 1) return 0.0;
        int n = quality.size();
        double answer = DBL_MAX;

        // new vector to sort employees based on R
        vector<pair<double, int>> worker; worker.reserve(n);
        for (int i = 0; i < n; ++i) {
            worker.emplace_back(
                static_cast<double>(wage.at(i)) / quality.at(i), 
                quality.at(i)
            );
        }
        
        sort(worker.begin(), worker.end());

        // queue
        priority_queue<int> q;
        int qualitySum = 0;
        for (int i = 0; i < worker.size(); ++i) {
            q.push(worker.at(i).second);
            qualitySum += worker.at(i).second;
            double maxRatio = worker.at(i).first;
            
            if (q.size() > k) {
                qualitySum -= q.top();
                q.pop();
            }

            if (q.size() == k) {
                answer = min(answer, maxRatio * qualitySum);
            }
        }

        return answer;
    }
};