class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        // column binary search, only the first index
        int Begin = 0;
        int End = matrix.size();
        while (Begin < End) {
            int middle = Begin + (End - Begin) / 2;

            if (target < matrix[middle][0]) {
                End = middle;
            } else {
                Begin = middle + 1;
            }
        }

        int rowNum = End - 1;
        if (rowNum < 0)
            return false;

        int rowBegin = 0;
        int rowEnd = matrix.front().size();
        while (rowBegin < rowEnd) {  // row binary search
            int rowMiddle = rowBegin + (rowEnd - rowBegin) / 2;

            if (target == matrix[rowNum][rowMiddle]) {
                return true;
            } else if (target < matrix[rowNum][rowMiddle]) {
                rowEnd = rowMiddle;
            } else {
                rowBegin = rowMiddle + 1;
            }
        }
        return false;
    }
};