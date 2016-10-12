class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        vector<int> left(nums.size(), 0), right(nums.size(), 0);
        int sum(0), maxSum(INT_MIN), minSum(0);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum - minSum);
            minSum = min(sum, minSum);
            left[i] = maxSum;
        }
        sum = 0;
        maxSum = INT_MIN;
        minSum = 0;
        for (int i = nums.size() - 1; i>= 0; i--) {
            sum += nums[i];
            maxSum = max(maxSum, sum - minSum);
            minSum = min(minSum, sum);
            right[i] = maxSum;
        }
        maxSum = INT_MIN;
        for (int i = 0; i < nums.size() - 1; i++) {
            maxSum = max(maxSum, left[i] + right[i + 1]);
        }
        return maxSum;
    }
};
