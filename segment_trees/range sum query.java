class NumArray {
    private int[] nums;
    private int[] segmentTree;

    public NumArray(int[] nums) {
        this.nums = nums;
        int n = nums.length;
        if (n > 0) {
            int height = (int) Math.ceil(Math.log(n) / Math.log(2));
            int treeSize = 2 * (int) Math.pow(2, height) - 1;
            segmentTree = new int[treeSize];
            buildSegmentTree(0, 0, n - 1);
        }
    }

    private void buildSegmentTree(int index, int start, int end) {
        if (start == end) {
            segmentTree[index] = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;

            buildSegmentTree(leftChildIndex, start, mid);
            buildSegmentTree(rightChildIndex, mid + 1, end);

            segmentTree[index] = segmentTree[leftChildIndex] + segmentTree[rightChildIndex];
        }
    }

    public void update(int index, int val) {
        updateSegmentTree(0, 0, nums.length - 1, index, val);
    }

    private void updateSegmentTree(int treeIndex, int start, int end, int index, int val) {
        if (start == end) {
            nums[index] = val;
            segmentTree[treeIndex] = val;
        } else {
            int mid = start + (end - start) / 2;
            int leftChildIndex = 2 * treeIndex + 1;
            int rightChildIndex = 2 * treeIndex + 2;

            if (index <= mid) {
                updateSegmentTree(leftChildIndex, start, mid, index, val);
            } else {
                updateSegmentTree(rightChildIndex, mid + 1, end, index, val);
            }

            segmentTree[treeIndex] = segmentTree[leftChildIndex] + segmentTree[rightChildIndex];
        }
    }

    public int sumRange(int left, int right) {
        return querySegmentTree(0, 0, nums.length - 1, left, right);
    }

    private int querySegmentTree(int treeIndex, int start, int end, int queryStart, int queryEnd) {
        if (queryStart > end || queryEnd < start) {
            return 0;
        }

        if (queryStart <= start && queryEnd >= end) {
            return segmentTree[treeIndex];
        }

        int mid = start + (end - start) / 2;
        int leftChildIndex = 2 * treeIndex + 1;
        int rightChildIndex = 2 * treeIndex + 2;

        int leftSum = querySegmentTree(leftChildIndex, start, mid, queryStart, queryEnd);
        int rightSum = querySegmentTree(rightChildIndex, mid + 1, end, queryStart, queryEnd);

        return leftSum + rightSum;
    }
}
