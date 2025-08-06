class Solution {
public:
    void build(int i, int l, int r, vector<int>& baskets, vector<int>& SegTree) {
        if (l == r) {
            SegTree[i] = baskets[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i + 1, l, mid, baskets, SegTree);
        build(2 * i + 2, mid + 1, r, baskets, SegTree);

        SegTree[i] = max(SegTree[2 * i + 1], SegTree[2 * i + 2]);
    }

    bool QuerySegTree(int i, int l, int r, vector<int>& SegTree, int fruit) {
        if (SegTree[i] < fruit) {
            return false;
        }
        if (l == r) {
            SegTree[i] = -1;  
            return true;
        }

        int mid = (l + r) / 2;
        bool placed = false;

        if (SegTree[2 * i + 1] >= fruit) {
            placed = QuerySegTree(2 * i + 1, l, mid, SegTree, fruit);
        } else {
            placed = QuerySegTree(2 * i + 2, mid + 1, r, SegTree, fruit);
        }

        SegTree[i] = max(SegTree[2 * i + 1], SegTree[2 * i + 2]);
        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int m = baskets.size();
        vector<int> SegTree(4 * m, -1);

        build(0, 0, m - 1, baskets, SegTree);

        int unplaced = 0;
        for (int fruit : fruits) {
            if (!QuerySegTree(0, 0, m - 1, SegTree, fruit)) {
                unplaced++;
            }
        }

        return unplaced;
    }
};
