class Solution {
    public int maxChunksToSorted(int[] input) {
        int n = input.length;
        int[] suffixR = new int[n];

        suffixR[n - 1] = input[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixR[i] = Math.min(suffixR[i + 1], input[i]);
        }

        int leftMax = input[0];
        int chunks = 0;

        for (int i = 1; i < n; i++) {
            if (leftMax <= suffixR[i]) {
                chunks++;
                leftMax = input[i];   // important reset
            } else {
                leftMax = Math.max(leftMax, input[i]);
            }
        }

        return chunks + 1;
    }
}