class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        std::vector<vector<int>> adj(numCourses);
        std::vector<int> indegree(numCourses, 0);

        for (const auto& p : prerequisites) {
            int A = p[0];
            int B = p[1];

            adj[B].emplace_back(A);
            indegree[A]++;
        }

        std::queue<int> q;
        std::vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int completed = 0;
       
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            order.push_back(curr);
            completed++;
            
            for (int neighbour : adj[curr]) {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        if (numCourses == completed) {
            return order;
        } else {
            return {};
        }
    }
};