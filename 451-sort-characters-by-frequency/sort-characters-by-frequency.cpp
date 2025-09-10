class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Put into vector for sorting
        vector<pair<char, int>> vec(freq.begin(), freq.end());

        // Step 3: Sort by frequency (descending)
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Step 4: Build answer
        string ans = "";
        for (auto &p : vec) {
            ans.append(p.second, p.first);  // repeat char p.first, p.second times
        }

        return ans;
    }
};
