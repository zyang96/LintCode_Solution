class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        if (nums.size() < 4) {
            return ret;
        }
        vector<int> currSet;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int subTarget = target - nums[i] - nums[j];
                int start = j + 1, end = nums.size() - 1;
                while (start < end) {
                    if (nums[start] + nums[end] == subTarget) {
                        currSet.push_back(nums[i]);
                        currSet.push_back(nums[j]);
                        currSet.push_back(nums[start]);
                        currSet.push_back(nums[end]);
                        ret.push_back(currSet);
                        currSet.clear();
                        start++;
                        end--;
                        while (nums[start] == nums[start - 1]) {
                            start++;
                        }
                        while (nums[end] == nums[end + 1]) {
                            end--;
                        }
                    } else if (nums[start] + nums[end] < subTarget) {
                        start++;
                    } else {
                        end--;
                    }
                }
            }
        }
        return ret;
    }
};
