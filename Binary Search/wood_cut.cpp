class Solution {
public:
int woodCut(vector<int> L, int k) {
        const int n = L.size();
        if (n == 0) {
            return 0;
        }

        int left = 1, right = *max_element(L.cbegin(), L.cend());
        while (left <= right) {
            const auto mid = left + (right - left) / 2;

            // Find the smallest x,  s.t. pieceCount(x) < k <= pieceCound(x - 1)
            if (pieceCount(L, mid) < k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // The max length is x - 1
        return left - 1;
    }

private:
    int pieceCount(vector<int>& L, int x) {
        int cnt = 0;
        for (const auto& len : L) {
            cnt += len / x;
        }
        return cnt;
    }
};

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int calcuPieces(vector<int> & L, int cutLength) {
        int ret(0);
        for (int i = 0; i < L.size(); i++) {
            ret += L[i] / cutLength;
        }
        return ret;
    }
    int woodCut(vector<int> L, int k) {
        // write your code here
        if (L.size() == 0) {
            return 0;
        }
        int maxLength = (int)*max_element(L.begin(), L.end());
        int minLength = 0;
        int mid;
        while (minLength + 1 < maxLength) {
            mid = minLength + (maxLength - minLength) / 2;
            if (calcuPieces(L, mid) < k) {
                maxLength = mid;
            } else {
                minLength = mid;
            }
        }
        return minLength;
    }
};