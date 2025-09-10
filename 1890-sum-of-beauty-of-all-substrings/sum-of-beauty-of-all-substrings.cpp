// class Solution {
// public:
//     int beautySum(string s) {
//         int n = s.length();
//         string SubStr;
//         map<char, int> mpp;
//         int ans = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 string subStr = s.substr(i, j - i + 1);
//                 map<char, int> freq;
//                 for (char c : subStr) {
//                     freq[c]++;
//                 }

//                 int maxFreq = 0, minFreq = subStr.length();
//                 for (auto& pair : freq) {
//                     maxFreq = max(maxFreq, pair.second);
//                     minFreq = min(minFreq, pair.second);
//                 }
//                 int beauty = maxFreq - minFreq;
//                 ans += beauty;
//             }
//         }
//         return ans;
//     }
// };


//---------------------------------------------------------------------------

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int maxFreq = 0, minFreq = INT_MAX;
                for (int f : freq) {
                    if (f > 0) {
                        maxFreq = max(maxFreq, f);
                        minFreq = min(minFreq, f);
                    }
                }

                ans += (maxFreq - minFreq);
            }
        }
        return ans;
    }
};
