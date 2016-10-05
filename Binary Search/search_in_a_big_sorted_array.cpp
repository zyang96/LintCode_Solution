/**
 * Definition of ArrayReader:
 * 
 * class ArrayReader {
 * public:
 *     int get(int index) {
 *          // return the number on given index, 
 *          // return -1 if index is less than zero.
 *     }
 * };
 */
class Solution {
public:
    /**
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader *reader, int target) {
        // write your code here
        int start = 0, end = INT_MAX;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (reader->get(mid) == target) {
                end = mid;
            } else if (reader->get(mid) < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (reader->get(start) == target) {
            return start;
        } else if (reader->get(end) == target) {
            return end;
        }
        return -1;
    }
};