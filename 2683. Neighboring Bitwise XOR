class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int> original = {0};
        for (int i = 0; i < derived.size(); i++) {
            original.push_back((derived[i] ^ original[i]));
        }
        bool checkForZero = (original[0] == original[original.size() - 1]);
        original = {1};
        for (int i = 0; i < derived.size(); i++) {
            original.push_back((derived[i] ^ original[i]));
        }
        bool checkForOne = (original[0] == original[original.size() - 1]);

        return checkForZero | checkForOne;
    }
};