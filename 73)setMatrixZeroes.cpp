class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool firstRowZero = false;
        bool firstColZero = false;

        // Check if first row needs to be zero
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0)
                firstRowZero = true;
        }

        // Check if first column needs to be zero
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0)
                firstColZero = true;
        }

        // Use first row and column as flags
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeroes based on flags
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Zero first row if needed
        if (firstRowZero) {
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }

        // Zero first column if needed
        if (firstColZero) {
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};

