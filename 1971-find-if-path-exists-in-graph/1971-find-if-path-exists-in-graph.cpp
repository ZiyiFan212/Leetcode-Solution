class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        //adj.reserve(n);

        for(int i = 0; i < edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        queue<int> q;
        vector<bool> visited(n,false);
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == destination){
                return true;
            }

            for(auto neighbour: adj[curr]){
                if(visited[neighbour] == false){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};
