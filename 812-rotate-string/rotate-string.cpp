class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;

        string Concat =s+s;

        if(Concat.find(goal)!=std::string::npos) return true;

        return false;
    }
};