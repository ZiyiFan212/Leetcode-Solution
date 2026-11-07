class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        std::vector<vector<int>> adj(numCourses);
        std::vector<int> indegree(numCourses, 0);

        for (const auto& p : prerequisites) {
            int A = p[0];
            int B = p[1];

            adj[B].emplace_back(A);
            indegree[A]++;
        }

        std::queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int completed = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            completed++;

            for (int neighbour : adj[curr]) {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return completed == numCourses;
    }
};