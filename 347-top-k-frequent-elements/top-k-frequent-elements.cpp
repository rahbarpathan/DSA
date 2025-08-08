class Solution {
public:
    typedef pair<int ,int>p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int  ,int>mpp;
        for(int &num : nums){
            mpp[num]++;
        }

        priority_queue<p  ,vector<p> , greater<p>> pq;
        for(auto &it :mpp){
            int value =it.first;
            int freq = it.second;

            pq.push({freq ,value});

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int>result;

        while(!(pq.empty())){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;

    }
};