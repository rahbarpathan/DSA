class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = 0;
        int zeroCount = 0, ans = 0;
        while(right < n){
            if(nums[right] == 0) zeroCount++;

            while(zeroCount > 1){
                if(nums[left] == 0) zeroCount--;
                left++;
            }

            ans = max(ans, right-left);
            right++;
        }

        return ans;
    }
};