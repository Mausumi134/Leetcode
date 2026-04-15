class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int count = 0;

        int mini = Integer.MAX_VALUE;
        int[] mn_till = new int[n];

        // suffix minimum array
        for (int i = n - 1; i >= 0; i--) {
            mini = Math.min(mini, arr[i]);
            mn_till[i] = mini;
        }

        int maxi = arr[0];

        // check valid splits
        for (int i = 1; i < n; i++) {
            if (maxi <= mn_till[i]) {
                count++;
                maxi = arr[i];   // reset for next chunk
            } else {
                maxi = Math.max(maxi, arr[i]);
            }
        }

        return count + 1;
    }
}