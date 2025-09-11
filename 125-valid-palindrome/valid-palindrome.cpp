class Solution {
public:
    bool isPalindrome(string s) {
        string revstr;

        for(const auto&c:s){
            if(isalnum(c)) revstr.push_back(tolower(c));
        } 
        if(revstr.empty()) return true;

        auto temp_str =revstr;

        reverse(revstr.begin(),revstr.end());

        return revstr==temp_str;
    }
};