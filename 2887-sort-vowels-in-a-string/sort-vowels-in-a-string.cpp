#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        vector<char> extracted;
        for (char c : s) {
            if (vowels.count(c)) {
                extracted.push_back(c);
            }
        }
        sort(extracted.begin(), extracted.end());
        int idx = 0;
        for (char &c : s) {
            if (vowels.count(c)) {
                c = extracted[idx++];
            }
        }
        return s;
    }
};
