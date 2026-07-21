class NumArray {
    int[] numArray;
    int[] prefixSum;

    public NumArray(int[] nums) {
        numArray = nums;
        prefixSum = new int[nums.length];
        initializePrefixArray(nums.length);
    }

    public void initializePrefixArray(int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += numArray[i];
            prefixSum[i] = sum;
        }
    }

    public int sumRange(int left, int right) {
        if (left == 0) {
            return prefixSum[right];
        }
        return prefixSum[right] - prefixSum[left] + numArray[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left, right);
 */