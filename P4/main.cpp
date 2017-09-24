#include <iostream>
using namespace std;
#include <vector>

double median(vector<int> a, int start_a, vector<int> b, int start_b, int k) {
    if (start_a > a.size() - 1) return b[start_b + k - 1];
    if (start_b > b.size() - 1) return a[start_a + k - 1];
    if (k == 1) return min(a[start_a], b[start_b]);
    int mid_a = INT_MAX;
    int mid_b = INT_MAX;
    if (start_a + k / 2 - 1 < a.size()) mid_a = a[start_a + k / 2 - 1];
    if (start_b + k / 2 - 1 < b.size()) mid_b = b[start_b + k / 2 - 1];
    if (mid_a < mid_b) return median(a, start_a + k / 2, b, start_b, k - k / 2);
    else return  median(a, start_a, b, start_b + k / 2, k - k / 2);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int l1 = nums1.size();
    int l2 = nums2.size();
    int left = (l1 + l2  + 1) / 2;
    int right = (l1 + l2 + 2) / 2;

    if (nums1.empty()) {
        if (l2 % 2 == 1) return nums2[l2 / 2];
        return (nums2[l2 / 2] + nums2[l2 / 2 - 1]) / 2.0;
    }
    if (nums2.empty()) {
        if (l1 % 2 == 1) return nums1[l1 / 2];
        return (nums1[l1 / 2] + nums1[l1 / 2 - 1]) / 2.0;
    }
    return (median(nums1, 0, nums2, 0, left) + median(nums1, 0, nums2, 0, right)) / 2.0;
}

int main(){
    vector<int> a = {1, 3};
    vector<int> b = {2, 4};
    cout << findMedianSortedArrays(a, b) << endl;
    //cout<<"Hello, World!"<<endl;
    return 0;
}