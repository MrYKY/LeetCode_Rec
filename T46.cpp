#include <vector>
using namespace std;

// 46.全排列
// 本题的难点在于：1.回溯算法的理解；2.如何在回溯算法中交换元素。
// 全排列可以说是最经典的回溯算法，没有之一。
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res,nums,0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int start){
        if(start==nums.size()-1){
            res.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[start], nums[i]);
            backtrack(res, nums, start+1);
            swap(nums[start], nums[i]);
        }
    }
};
