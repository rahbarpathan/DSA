#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> grid; // rows x 26 grid
    int rows;

    // Helper: parse cell reference "A1" → (row, col)
    pair<int,int> parseCell(const string &cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1; // 1-indexed
        return {row, col};
    }

    // Helper: get value from either number or cell reference
    int getOperandValue(const string &token) {
        if (isdigit(token[0])) {
            return stoi(token);
        } else {
            auto [r, c] = parseCell(token);
            return grid[r][c];
        }
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = value;
    }

    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = 0;
    }

    int getValue(string formula) {
        // formula format: "=X+Y"
        string expr = formula.substr(1); // remove '='
        size_t plusPos = expr.find('+');
        string left = expr.substr(0, plusPos);
        string right = expr.substr(plusPos + 1);

        int val1 = getOperandValue(left);
        int val2 = getOperandValue(right);

        return val1 + val2;
    }
};
