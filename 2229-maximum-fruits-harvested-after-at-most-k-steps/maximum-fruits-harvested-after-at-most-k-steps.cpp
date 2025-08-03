class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        vector<int> prefixSum(n); //fruits ka prefix sum
        vector<int> position(n); // sorted milega ye to


        for(int i=0; i<n ;i++){
            position[i] =fruits[i][0];

            prefixSum[i] = fruits[i][1] +(i>0 ? prefixSum[i-1] :0);
        }

        int maxFruit =0;

        for(int d=0; d<= k/2 ;d++){
            // case1- d left side jaane k liye

            int remain =k- 2*d;
            int i=startPos -d;
            int j =startPos +remain;

            int left = lower_bound(begin(position) ,end(position),i) - begin(position);
            int right = upper_bound(begin(position) ,end(position),j) -begin(position) -1;

            if(left <= right){
                int total =prefixSum[right] -(left >0 ? prefixSum[left-1] :0);
                maxFruit = max(maxFruit ,total);
            }

            //case2- d right side ko move krega

            i=startPos -remain;
            j =startPos +d;

            left = lower_bound(begin(position) ,end(position),i) - begin(position);
            right = upper_bound(begin(position) ,end(position),j) -begin(position) -1;

            if(left <= right){
                int total =prefixSum[right] -(left >0 ? prefixSum[left-1] :0);
                maxFruit = max(maxFruit ,total);
            }
        }
        return maxFruit;
    }
};