class Solution {
public:
    /**
     * @param stk an integer stack
     * @return void
     */
    void stackSorting(stack<int>& stk) {
        // Write your code here
        stack<int> retStack;
        int temp;
        int counter(0);
        while (!stk.empty()) {
            temp = stk.top();
            stk.pop();
            if (retStack.empty() || temp >= retStack.top()) {
                retStack.push(temp);
            } else {
                while (!retStack.empty() && temp < retStack.top()) {
                    stk.push(retStack.top());
                    retStack.pop();
                    counter++;
                }
                retStack.push(temp);
                while(counter > 0) {
                    retStack.push(stk.top());
                    stk.pop();
                    counter--;
                }
            }
        }
        stk = retStack;
    }
};