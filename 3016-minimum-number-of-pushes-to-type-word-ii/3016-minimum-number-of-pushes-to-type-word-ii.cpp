class Solution {
public:
    int minimumPushes(string word) {
     
        unordered_map<char, int> frequencyMap;

        for (char& c : word) {
            ++frequencyMap[c];
        }

       
        priority_queue<int> frequencyQueue;

      
        for (const auto& entry : frequencyMap) {
            frequencyQueue.push(entry.second);
        }

        int totalPushes = 0;
        int index = 0;

       
        while (!frequencyQueue.empty()) {
            totalPushes += (1 + (index / 8)) * frequencyQueue.top();
            frequencyQueue.pop();
            index++;
        }

        return totalPushes;
    }
};