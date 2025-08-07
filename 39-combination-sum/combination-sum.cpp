class Solution {
public:
    void combinationFind(int i, int target, vector<int>& arr,vector<vector<int>>& ans, vector<int>& ds) {
        if (i == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        if (arr[i] <= target) {
            ds.push_back(arr[i]);
            combinationFind(i, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
        combinationFind(i + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combinationFind(0, target, candidates, ans,ds);
        return ans;
    }
};