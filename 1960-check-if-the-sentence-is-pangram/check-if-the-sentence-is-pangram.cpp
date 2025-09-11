class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>flag(26,false);
        for(const auto& c:sentence){
            if(c>='a'&& c<='z'){
                flag[c-'a']=true;
            }
            else if(c>='A' && c<='Z'){
                flag[c-'A']=true;
            }
        }
        for(auto const&c:flag){
            if(c==false) return false;
        }
        return true;
    }
};