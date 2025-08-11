class Solution {
public:
    int M = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        vector<int> result;

        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) != 0) {
                power.push_back(1 << i);
            }
        }

        for (auto& query : queries) {
            int st = query[0];
            int end = query[1];

            long product = 1;

            for (int i = st; i <= end; i++) {
                product = (product * power[i]) % M;
            }

            result.push_back(product);
        }
        return result;
    }
};