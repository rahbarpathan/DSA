// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();
//         vector<int> mergeArray;

//         for (int i = 0; i < m; i++) {
//             mergeArray.push_back(nums1[i]);
//         }

//         for (int j = 0; j < n; j++) {
//             mergeArray.push_back(nums2[j]);
//         }

//         sort(mergeArray.begin(), mergeArray.end());

//         int s= 0;
//         int e =mergeArray.size()-1;
//         int mid = (s + e) / 2;
//         double ans;

//         if (mergeArray.size() % 2 == 0) {
//             ans = (mergeArray[mid] + mergeArray[mid + 1]) / 2.0;
//         } else {
//             ans = mergeArray[mid];
//         }

//         return ans;
//     }
// };

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size();
        int n2 = nums2.size();

        if(n1>n2) return findMedianSortedArrays(nums2 , nums1);

        int left = (n1 +n2 +1)/2 ;
        int n = n1+n2;
        int low =0;
        int high =n1;

        while(low<=high){
            int mid1 = (low + high ) >> 1;
            int mid2 = left- mid1;

            int l1 = INT_MIN ,l2 =INT_MIN;
            int r1= INT_MAX ,r2= INT_MAX;

            if(mid1 <n1) r1  =nums1[mid1];
            if(mid2 < n2) r2 =nums2[mid2];

            if(mid1 -1 >= 0) l1 = nums1[mid1-1];
            if(mid2-1 >= 0) l2 = nums2[mid2-1]; 

            if(l1 <= r2 && l2 <=r1){
                if(n%2 ==1) return max(l1 ,l2);
                return (double(max(l1 ,l2)+min(r1 , r2)))/2.0;
            }
            else if(l1 >r2) high = mid1-1;
            else
                low =mid1+1;
        }
        return 0;

    }
};