class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

    int i =0 ;

    for(int j=1;j<nums.size() ;j++){
        if(nums[i]!=nums[j]){
            nums[i+1]= nums[j];
            i++;
        }
    }
    return {i+1};
    // int uniqueCount = 1; // start with the first element being unique by default

    // for (int i = 1; i < nums.size(); ++i) {
    //     if (nums[i] != nums[uniqueCount - 1]) {
    //         nums[uniqueCount] = nums[i];
    //         uniqueCount++;
    //     }
    // }

    // return uniqueCount;
    }
};