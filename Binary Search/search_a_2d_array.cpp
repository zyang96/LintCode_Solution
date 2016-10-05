class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    int accessElement(vector<vector<int> > matrix, int index) {
        int rowIdx = index / matrix[0].size();
        int colIdx = index % matrix[0].size();
        return matrix[rowIdx][colIdx];
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int start = 0, end = matrix.size() * matrix[0].size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (accessElement(matrix, mid) == target) {
                return true;
            } else if (accessElement(matrix, mid) < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (accessElement(matrix, start) == target) {
            return true;
        }
        return false;
    }
};

//2nd
class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    int accessElement(vector<vector<int>> & matrix, int index) {
        int rowNum = index / matrix[0].size();
        int colNum = index % matrix[0].size();
        return matrix[rowNum][colNum];
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int start(0), end(matrix[0].size() * matrix.size() - 1);
        int mid;
        while (start + 1 < end) {
            mid = (start + end) / 2;
            int element = accessElement(matrix, mid);
            if (element == target) {
                return true;
            } else if (element < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (accessElement(matrix, start) == target || accessElement(matrix, end) == target) {
            return true;
        } else {
            return false;
        }
    }
};
