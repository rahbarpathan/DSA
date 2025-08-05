class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(fruits[i] != INT_MAX && fruits[i] <= baskets[j]) {
                    baskets[j] = 0;      
                    fruits[i] = INT_MAX;   
                    ans++;               
                    break;               
                }
            }
        }

        return n - ans; 
    }
};
