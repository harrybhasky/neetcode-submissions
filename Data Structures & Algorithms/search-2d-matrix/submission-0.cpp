class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bottom = matrix.size() - 1;
        int targetRow = -1;

        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;
            if (target < matrix[mid][0]) bottom = mid - 1;
            else if (target > matrix[mid].back()) top = mid + 1;
            else { targetRow = mid; break; }
        }

        if (targetRow == -1) return false;

        vector<int>& row = matrix[targetRow];
        int i = 0, j = row.size() - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (row[mid] == target) return true;
            else if (target < row[mid]) j = mid - 1;
            else i = mid + 1;
        }
        return false;
    }
};