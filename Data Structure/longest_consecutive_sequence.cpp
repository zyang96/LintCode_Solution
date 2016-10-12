class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        if (num.size() == 0) {
            return 0;
        }
        unordered_set<int> mySet;
        for (int i = 0; i < num.size(); i++) {
            mySet.emplace(num[i]);
        }
        int upperBound(0), lowerBound(0), maxInterval(0);
        while (!mySet.empty()) {
            unordered_set<int>::iterator iter = mySet.begin();
            mySet.erase(*iter);
            upperBound = *iter + 1;
            while (mySet.count(upperBound)) {
                mySet.erase(upperBound);
                upperBound++;
            }
            lowerBound = *iter - 1;
            while (mySet.count(lowerBound)) {
                mySet.erase(lowerBound);
                lowerBound--;
            }
            maxInterval = max(maxInterval, upperBound - lowerBound - 1);
        }
        return maxInterval;
    }
};