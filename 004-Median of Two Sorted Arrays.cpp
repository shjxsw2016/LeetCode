class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2)
            return find_kth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, total / 2 + 1);
        else
            return (find_kth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, total / 2) +
            find_kth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, total / 2 + 1)) / 2.0;
    }
    double find_kth(vector <int > A, int abegin, int aend, vector <int > B, int bbegin, int bend, int k){
        int m = aend - abegin + 1;
        int n = bend - bbegin + 1;
        if (m > n){
            //习惯短的数列在前面
            return find_kth(B, bbegin, bend, A, abegin, aend, k);
        }
        if (m == 0) return B[bbegin + k - 1];
        if (k == 1) return min(A[abegin], B[bbegin]);
        int ia = min(k / 2, m), ib = k - ia;
        if (A[abegin + ia - 1] < B[bbegin + ib - 1]){
            return find_kth(A, abegin + ia, aend, B, bbegin, bend, k - ia);
        }
        else if (A[abegin + ia - 1] > B[bbegin + ib - 1]){
            return find_kth(A, abegin, aend, B, bbegin + ib, bend, k - ib);
        }
        else
            return A[abegin + ia - 1];
    }
};

