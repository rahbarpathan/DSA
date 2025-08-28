class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diag;

        // Step 1: collect diagonals
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diag[i - j].push_back(grid[i][j]);
            }
        }

        // Step 2: sort each diagonal
        for (auto &d : diag) {
            if (d.first >= 0) { // bottom-left including main diagonal
                sort(d.second.begin(), d.second.end(), greater<int>()); // descending
            } else { // top-right
                sort(d.second.begin(), d.second.end()); // ascending
            }
        }

        // Step 3: put back sorted values
        unordered_map<int, int> idx; // track position in each diagonal
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                grid[i][j] = diag[key][idx[key]++];
            }
        }

        return grid;
    }
};
