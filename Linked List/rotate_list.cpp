/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if (head == NULL) {
            return head;
        }
        ListNode * curr = head;
        int count(1);
        while (curr->next != NULL) {
            curr = curr->next;
            count++;
        }
        curr->next = head;
        count = count - k % count;
        curr = head;
        for (int i = 0; i < count - 1; i++) {
            curr = curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};