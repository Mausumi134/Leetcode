class Solution {
private:
    int exploreIsland(vector<vector<int>>& grid, int islandId, int currentRow,
                      int currentColumn) {
        if (currentRow < 0 || currentRow >= grid.size() || currentColumn < 0 ||
            currentColumn >= grid[0].size() ||
            grid[currentRow][currentColumn] != 1)
            return 0;

        grid[currentRow][currentColumn] = islandId;
        return 1 +
               exploreIsland(grid, islandId, currentRow + 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow - 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow, currentColumn + 1) +
               exploreIsland(grid, islandId, currentRow, currentColumn - 1);
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> islandSizes;
        int islandId = 2;

        // Step 1: Mark all islands and calculate their sizes
        for (int currentRow = 0; currentRow < grid.size(); ++currentRow) {
            for (int currentColumn = 0; currentColumn < grid[0].size();
                 ++currentColumn) {
                if (grid[currentRow][currentColumn] == 1) {
                    islandSizes[islandId] = exploreIsland(
                        grid, islandId, currentRow, currentColumn);
                    ++islandId;
                }
            }
        }

        // If there are no islands, return 1
        if (islandSizes.empty()) {
            return 1;
        }
        // If the entire grid is one island, return its size or size + 1
        if (islandSizes.size() == 1) {
            --islandId;
            return (islandSizes[islandId] == grid.size() * grid[0].size())
                       ? islandSizes[islandId]
                       : islandSizes[islandId] + 1;
        }

        int maxIslandSize = 1;

        // Step 2: Try converting every 0 to 1 and calculate the resulting
        // island size
        for (int currentRow = 0; currentRow < grid.size(); ++currentRow) {
            for (int currentColumn = 0; currentColumn < grid[0].size();
                 ++currentColumn) {
                if (grid[currentRow][currentColumn] == 0) {
                    int currentIslandSize = 1;
                    unordered_set<int> neighboringIslands;

                    // Check down
                    if (currentRow + 1 < grid.size() &&
                        grid[currentRow + 1][currentColumn] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow + 1][currentColumn]);
                    }

                    // Check up
                    if (currentRow - 1 >= 0 &&
                        grid[currentRow - 1][currentColumn] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow - 1][currentColumn]);
                    }

                    // Check right
                    if (currentColumn + 1 < grid[0].size() &&
                        grid[currentRow][currentColumn + 1] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn + 1]);
                    }

                    // Check left
                    if (currentColumn - 1 >= 0 &&
                        grid[currentRow][currentColumn - 1] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn - 1]);
                    }

                    // Sum the sizes of all unique neighboring islands
                    for (int id : neighboringIslands) {
                        currentIslandSize += islandSizes[id];
                    }

                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }

        return maxIslandSize;
    }
};