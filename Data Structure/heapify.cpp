class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        for (int i = A.size()/ 2 - 1; i >= 0; --i) {
            siftDown(A, i);
        }
    }

    void siftDown(vector<int>& A, int index) {
        while (index < A.size()) {
            int newIndex = index;
            if (index * 2 + 1 < A.size() && A[index * 2 + 1] < A[newIndex]) {
                newIndex = index * 2 + 1;
            }
            if (index * 2 + 2 < A.size() && A[index * 2 + 2] < A[newIndex]) {
                newIndex = index * 2 + 2;
            }
            if (index  == newIndex) { // doesnt switch with both children nodes
                break;
            }
            swap(A[newIndex], A[index]);
            index = newIndex;
        }
    }
};