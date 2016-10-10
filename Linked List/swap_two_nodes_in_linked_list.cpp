class Solution {
public:
    /**
     * @param head a ListNode
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        if (head == NULL) {
            return head;
        }
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * currNode = dummy;
        ListNode * prev1(NULL);
        ListNode * prev2(NULL);
        while (currNode->next != NULL) {
            if (currNode->next->val == v1) {
                prev1 = currNode;
            } else if (currNode->next->val == v2) {
                prev2 = currNode;
            }
            if (prev1 != NULL && prev2 != NULL) {
                if (prev1->next == prev2) {
                    ListNode * node2 = prev2->next;
                    prev1->next->next = node2->next;
                    node2->next = prev1->next;
                    prev1->next = node2;
                    return dummy->next;
                } else if (prev2->next == prev1) {
                    ListNode * node1 = prev1->next;
                    prev2->next->next = node1->next;
                    node1->next = prev2->next;
                    prev2->next = node1;
                    return dummy->next;
                } else {
                    ListNode * node1 = prev1->next;
                    ListNode * node2 = prev2->next;
                    prev1->next = node1->next;
                    node1->next = node2->next;
                    prev2->next = node1;
                    node2->next = prev1->next;
                    prev1->next = node2;
                    return dummy->next;
                }
            }
            currNode = currNode->next;
        }
        return dummy->next;
    }
};