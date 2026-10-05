class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n-1;

        while(row>= 0 && row<m && col>=0 && col <n)
        {
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target)
            {
                row = row+1;
            }
            else
            {
                col = col -1;
            }
        }
        return false;
    }
};