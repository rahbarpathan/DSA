class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        int total_squares = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (matrix[i][j] == 1 && i > 0 && j > 0) {

                    matrix[i][j] = 1 + std::min({matrix[i-1][j],matrix[i][j-1], matrix[i-1][j-1]});
                }
                total_squares += matrix[i][j];
            }
        }

        return total_squares;
    }
};