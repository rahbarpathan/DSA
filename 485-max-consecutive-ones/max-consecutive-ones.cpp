class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int Ans=0;
        int currMax =0;
        for(int i=0 ; i<nums.size();i++){
            if(nums[i]==1){
                currMax++;
                Ans = max(Ans , currMax);
            }
            else{
                currMax =0;
            }
        
        }
        return Ans;
    }
};