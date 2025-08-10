class Solution {
public:
    string getSorted(int n){
        string s =to_string(n);
        sort(begin(s) ,end(s));
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string s =getSorted(n);

        for(int i=0; i<=29;i++){
            if(s == getSorted(1<<i))
                return true;
        }
        return false;
    }
};