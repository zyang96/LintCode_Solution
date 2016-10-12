class Stack {
public:
    // Push a new item into the stack
    queue<int> q1;
    queue<int> q2;
    bool storeInQ1;
    Stack() {
        storeInQ1 = true;
    }
    void push(int x) {
        // Write your code here
        if (storeInQ1) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }

    // Pop the top of the stack
    void pop() {
        // Write your code here
        if (storeInQ1) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
            storeInQ1 = !storeInQ1;
        } else {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
            storeInQ1 = !storeInQ1;
        }
    }

    // Return the top of the stack
    int top() {
        // Write your code here
        int ret;
        if (storeInQ1) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            ret = q1.front();
            q1.pop();
            q2.push(ret);
            storeInQ1 = !storeInQ1;
            return ret;
        } else {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            ret = q2.front();
            q2.pop();
            q1.push(ret);
            storeInQ1 = !storeInQ1;
            return ret;
        }
    }

    // Check the stack is empty or not.
    bool isEmpty() {
        // Write your code here
        return (q1.empty() && q2.empty());
    }
};