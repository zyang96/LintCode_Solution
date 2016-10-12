class Queue {
public:
    ListNode * head;
    ListNode * end;
    Queue() {
        // do initialize if necessary
        head = new ListNode(-1);
        end = head;
    }

    void enqueue(int item) {
        // Write your code here
        ListNode * newNode = new ListNode(item);
        end->next = newNode;
        end = end->next;
    }

    int dequeue() {
        int ret = head->next->val;
        head = head->next;
        return ret;
        // Write your code here
    }
};
	
