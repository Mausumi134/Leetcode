class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Create adjacency list representation of the graph
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        // Process each unvisited vertex
        for (int vertex = 0; vertex < n; vertex++) {
            if (!visited[vertex]) {
                // BFS to find all vertices in the current component
                vector<int> component;
                queue<int> q;
                q.push(vertex);
                visited[vertex] = true;

                while (!q.empty()) {
                    int current = q.front();
                    q.pop();
                    component.push_back(current);

                    // Process neighbors
                    for (int neighbor : graph[current]) {
                        if (!visited[neighbor]) {
                            q.push(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                }

                // Check if component is complete (all vertices have the right
                // number of edges)
                bool isComplete = true;
                for (int node : component) {
                    if (graph[node].size() != component.size() - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};