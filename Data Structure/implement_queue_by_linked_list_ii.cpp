class Dequeue {
public:    
    ListNode * head;
    ListNode * endNode;
    
    Dequeue() {
        // do initialize if necessary
        head = new ListNode(-1);
        endNode = head;
    }

    void push_front(int item) {
        // Write your code here
        ListNode * temp = new ListNode(item);
        temp->next = head->next;
        head->next = temp;
    }

    void push_back(int item) {
        // Write your code here
        endNode = head;
        while (endNode->next != NULL) {
            endNode = endNode->next;
        }
        ListNode * temp = new ListNode(item);
        endNode->next = temp;
    }

    int pop_front() {
        // Write your code here
        int ret = head->next->val;
        head = head->next;
        return ret;
    }

    int pop_back() {
        // Write your code here
        int ret;
        if (head->next->next == NULL) {
            ret = pop_front();
            return ret;
        }
        endNode = head;
        while (endNode->next->next != NULL) {
            endNode = endNode->next;
        }
        ret = endNode->next->val;
        endNode->next = NULL;
        return ret;
    }
};
	
