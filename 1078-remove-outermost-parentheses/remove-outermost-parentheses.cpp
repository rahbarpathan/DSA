class Solution {
public:
    string removeOuterParentheses(string s) {
        int i=0,j=0,count=0;
        for(j=0;j<s.length();j++){
            
            if(s[j]=='(') count++;
            else count--;
            if(count ==0){
                
                s.erase(j,1);
                s.erase(i,1);
                j=j-2;
                i=j+1;
            }
        }
        return s;
    }
};