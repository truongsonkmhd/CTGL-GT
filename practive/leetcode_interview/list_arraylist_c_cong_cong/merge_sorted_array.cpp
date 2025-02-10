#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Gộp các phần tử từ nums2 vào nums1
        for (int j = 0, i = m; j < n; j++) {
            nums1[i] = nums2[j];
            i++;
        }
        // Sắp xếp lại nums1
        sort(nums1.begin(), nums1.end());
    }
};

int main() {
    Solution sol;

    // Ví dụ 1
    vector<int> nums1_1 = {1, 2, 3, 0, 0, 0};
    int m1 = 3;
    vector<int> nums2_1 = {2, 5, 6};
    int n1 = 3;
    sol.merge(nums1_1, m1, nums2_1, n1);
    for (int num : nums1_1) {
        cout << num << " ";
    }
    cout << endl;

    // Ví dụ 2
    vector<int> nums1_2 = {1};
    int m2 = 1;
    vector<int> nums2_2 = {};
    int n2 = 0;
    sol.merge(nums1_2, m2, nums2_2, n2);
    for (int num : nums1_2) {
        cout << num << " ";
    }
    cout << endl;

    // Ví dụ 3
    vector<int> nums1_3 = {0};
    int m3 = 0;
    vector<int> nums2_3 = {1};
    int n3 = 1;
    sol.merge(nums1_3, m3, nums2_3, n3);
    for (int num : nums1_3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
