/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        if (root == NULL) {
            return NULL;
        }
        DoublyListNode * dummy = new DoublyListNode(-1);
        DoublyListNode * currNode = dummy;
        stack<TreeNode *> myStack;
        TreeNode * currTreeNode(root);
        while (currTreeNode != NULL || !myStack.empty()) {
            while (currTreeNode != NULL) {
                myStack.push(currTreeNode);
                currTreeNode = currTreeNode->left;
            }
            currTreeNode = myStack.top();
            myStack.pop();
            currNode->next = new DoublyListNode(currTreeNode->val);
            currNode->next->prev = currNode;
            currNode = currNode->next;
            currTreeNode = currTreeNode->right;
        }
        dummy = dummy->next;
        dummy->prev = NULL;
        return dummy;
    }
};


