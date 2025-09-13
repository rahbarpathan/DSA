#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        string vowels = "aeiou";
        int maxVowel = 0, maxCons = 0;

        for (auto &p : freq) {
            char c = p.first;
            int count = p.second;
            if (vowels.find(c) != string::npos) { 
                // it's a vowel
                maxVowel = max(maxVowel, count);
            } else { 
                // consonant
                maxCons = max(maxCons, count);
            }
        }

        return maxVowel + maxCons;
    }
};
