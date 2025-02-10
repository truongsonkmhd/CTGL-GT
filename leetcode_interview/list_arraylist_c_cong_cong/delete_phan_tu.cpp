class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index;
        for(int i = 0; i < nums.length(), i++){
            if(nums[index] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};