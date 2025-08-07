class Solution {
public:

    void BuildSegTree(int i, int l, int r, int segTree[], vector<int>& heights) {
        if (l == r) {
            segTree[i] = l;
            return;
        }

        int mid = l + (r - l) / 2;
        BuildSegTree(2 * i + 1, l, mid, segTree, heights);
        BuildSegTree(2 * i + 2, mid + 1, r, segTree, heights);

        int leftIndex = segTree[2 * i + 1];
        int rightIndex = segTree[2 * i + 2];
        segTree[i] = (heights[leftIndex] >= heights[rightIndex]) ? leftIndex : rightIndex;
    }

    int* ConstructST(vector<int>& heights, int n) {
        int* segTree = new int[4 * n];
        BuildSegTree(0, 0, n - 1, segTree, heights);
        return segTree;
    }

    int QuerySeg(int start, int end, int i, int l, int r, int st[], vector<int>& heights) {
        if (l > end || r < start) {
            return -1;
        }

        if (l >= start && r <= end) {
            return st[i];
        }

        int mid = l + (r - l) / 2;
        int leftIndex = QuerySeg(start, end, 2 * i + 1, l, mid, st, heights);
        int rightIndex = QuerySeg(start, end, 2 * i + 2, mid + 1, r, st, heights);

        if (leftIndex == -1) return rightIndex;
        if (rightIndex == -1) return leftIndex;

        return (heights[leftIndex] >= heights[rightIndex]) ? leftIndex : rightIndex;
    }

    int RMIQ(int st[], vector<int>& heights, int n, int start, int end) {
        return QuerySeg(start, end, 0, 0, n - 1, st, heights);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int* segTree = ConstructST(heights, n);
        vector<int> result;

        for (auto& query : queries) {
            int min_idx = min(query[0], query[1]);
            int max_idx = max(query[0], query[1]);

            if (min_idx == max_idx) {
                result.push_back(min_idx);
                continue;
            }

            if (heights[max_idx] > heights[min_idx]) {
                result.push_back(max_idx);
                continue;
            }

            int l = max_idx + 1;
            int r = n - 1;
            int result_idx = INT_MAX;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                int idx = RMIQ(segTree, heights, n, l, mid);

                if (idx != -1 && heights[idx] > max(heights[min_idx], heights[max_idx])) {
                    result_idx = min(result_idx, idx);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (result_idx == INT_MAX) {
                result.push_back(-1);
            } else {
                result.push_back(result_idx);
            }
        }

        delete[] segTree;
        return result;
    }
};
