class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;

        // preprocess
        for (string &w : wordlist) {
            string lower = toLower(w);
            if (!caseInsensitive.count(lower))
                caseInsensitive[lower] = w;

            string dev = devowel(lower);
            if (!vowelInsensitive.count(dev))
                vowelInsensitive[dev] = w;
        }

        vector<string> ans;
        for (string &q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lowerQ = toLower(q);
            if (caseInsensitive.count(lowerQ)) {
                ans.push_back(caseInsensitive[lowerQ]);
                continue;
            }

            string devQ = devowel(lowerQ);
            if (vowelInsensitive.count(devQ)) {
                ans.push_back(vowelInsensitive[devQ]);
                continue;
            }

            ans.push_back("");
        }
        return ans;
    }

private:
    string toLower(const string &s) {
        string res = s;
        for (char &c : res) c = tolower(c);
        return res;
    }

    string devowel(const string &s) {
        string res = s;
        for (char &c : res) {
            if (isVowel(c)) c = '*';
        }
        return res;
    }

    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
};
