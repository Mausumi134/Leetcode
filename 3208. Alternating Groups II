class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // Extend the array to handle circular sequences
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        int length = colors.size();
        int result = 0;
        // Initialize the bounds of the sliding window
        int left = 0;
        int right = 1;

        while (right < length) {
            // Check if the current color is the same as the last one
            if (colors[right] == colors[right - 1]) {
                // Pattern breaks, reset window from the current position
                left = right;
                right++;
                continue;
            }

            // Expand the window to the right
            right++;

            // Skip counting sequence if its length is less than k
            if (right - left < k) continue;

            // Record a valid sequence and shrink window from the left to search
            // for more
            result++;
            left++;
        }

        return result;
    }
};