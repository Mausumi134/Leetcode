class Solution {
public:
    bool canChange(string start, string target) {
        // To keep track of visited states to avoid cycles
        unordered_set<string> visitedStates;
        // Queue for current state
        queue<string> stateQueue;
        // Start with the initial state
        stateQueue.push(start);

        while (!stateQueue.empty()) {
            string currentState = stateQueue.front();
            stateQueue.pop();

            // If we reach the target state, return true
            if (currentState == target) return true;

            for (int position = 1; position < currentState.size(); position++) {
                // Try moving 'L' to the left
                if (currentState[position] == 'L' &&
                    currentState[position - 1] == '_') {
                    swap(currentState[position], currentState[position - 1]);
                    if (visitedStates.find(currentState) ==
                        visitedStates.end()) {
                        // Add the new state to the queue
                        stateQueue.push(currentState);
                        // Mark the new state as visited
                        visitedStates.insert(currentState);
                    }
                    // Restore the state
                    swap(currentState[position], currentState[position - 1]);
                }
                // Try moving 'R' to the right
                if (currentState[position - 1] == 'R' &&
                    currentState[position] == '_') {
                    swap(currentState[position], currentState[position - 1]);
                    if (visitedStates.find(currentState) ==
                        visitedStates.end()) {
                        // Add the new state to the queue
                        stateQueue.push(currentState);
                        // Mark the new state as visited
                        visitedStates.insert(currentState);
                    }
                    // Restore the state
                    swap(currentState[position], currentState[position - 1]);
                }
            }
        }

        // If no valid transformation sequence is found, return false
        return false;
    }
};