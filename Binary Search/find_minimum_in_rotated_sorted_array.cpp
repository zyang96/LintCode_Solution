class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int start = 0, end = nums.size() - 1;
        int target = nums[end];
        while (start + 1 < end) {
            int mid = (start + end) / 2;
            if (nums[mid] < target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (nums[start] < target) {
            return nums[start];
        } else {
            return nums[end];
        }
    }
};
