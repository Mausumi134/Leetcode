class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> reversedGraph(n);
        for (int person = 0; person < n; ++person) {
            reversedGraph[favorite[person]].push_back(person);
        }

        auto bfs = [&](int startNode, unordered_set<int>& visitedNodes) -> int {
            queue<pair<int, int>> q;
            q.push({startNode, 0});
            int maxDistance = 0;
            while (!q.empty()) {
                auto [currentNode, currentDistance] = q.front();
                q.pop();
                for (int neighbor : reversedGraph[currentNode]) {
                    if (visitedNodes.count(neighbor)) continue;
                    visitedNodes.insert(neighbor);
                    q.push({neighbor, currentDistance + 1});
                    maxDistance = max(maxDistance, currentDistance + 1);
                }
            }
            return maxDistance;
        };

        int longestCycle = 0, twoCycleInvitations = 0;
        vector<bool> visited(n, false);

        for (int person = 0; person < n; ++person) {
            if (!visited[person]) {
                unordered_map<int, int> visitedPersons;
                int current = person;
                int distance = 0;
                while (true) {
                    if (visited[current]) break;
                    visited[current] = true;
                    visitedPersons[current] = distance++;
                    int nextPerson = favorite[current];
                    if (visitedPersons.count(nextPerson)) {  
                        int cycleLength = distance - visitedPersons[nextPerson];
                        longestCycle = max(longestCycle, cycleLength);
                        if (cycleLength == 2) {
                            unordered_set<int> visitedNodes = {current,
                                                               nextPerson};
                            twoCycleInvitations +=
                                2 + bfs(nextPerson, visitedNodes) +
                                bfs(current, visitedNodes);
                        }
                        break;
                    }
                    current = nextPerson;
                }
            }
        }

        return max(longestCycle, twoCycleInvitations);
    }
};