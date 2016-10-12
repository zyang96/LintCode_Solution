class Solution {
private:
    int k;
    priority_queue<int, vector<int>, less<int>> myHeap;
    vector<int> myVec;
public:
    Solution(int k) {
        // initialize your data structure here.
        this->k = k;
    }

    void add(int num) {
        // Write your code here
        myHeap.push(num);
    }

    vector<int> topk() {
        // Write your code here
        myVec.clear();
        for (int i = 0; i < k && !myHeap.empty(); i++) {
            myVec.push_back(myHeap.top());
            myHeap.pop();
        }
        for (int i = 0; i < myVec.size(); i++) {
            myHeap.push(myVec[i]);
        }
        return myVec;
    }
};