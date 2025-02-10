#include <iostream>
#include <vector>
using namespace std;
class ArrayRotator {
public:
    // Function to rotate the array nums to the right by k steps
    void rotate(vector<int>& nums, int k) {
         int n = nums.size();
        k = k % n; // Effective rotations
        if (k == 0) return; // No need to rotate if k is 0 or multiple of 
        //Reverse the Entire Array
        reverse(nums, 0, nums.size() - 1);
        //Reverse the First k Elements
        reverse(nums, 0, k - 1);
        //Reverse the Remaining Elements
        reverse(nums, k, nums.size() - 1);
    }

private:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
           swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};

int main() {
    ArrayRotator rotator;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 4;
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    rotator.rotate(nums, k);
    cout << "\nRotated array: ";
    for (int num : nums) {
       cout << num << " ";
    }

    return 0;
}
