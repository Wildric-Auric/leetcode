#include "common.h"

class Solution {
public:
    void order(vector<int>& nums, int i) {
        sort(nums.begin() + i, nums.end());
    }

    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int minn;
        int index;
        for (int i = nums.size() - 2; i > -1; i--) {
            minn = 101;
            index = i;
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[j] > nums[i] && nums[j] < minn) {
                    minn = nums[j];
                    index = j;
                }
            }
            if (minn == 101) 
                continue;
            int t       = nums[i];
            nums[i]     = minn;
            nums[index] = t;
            order(nums, i+1);
            return;
        }
        order(nums, 0);
        return;
    }
};



int main() {
    vector<int> a{1,2}; 
    Solution().nextPermutation(a);
    for (int& c : a) 
        printf("%d ", c);
}
