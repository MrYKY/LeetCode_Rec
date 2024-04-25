
#include <vector>
using namespace std;

// 81.搜索旋转数组
// 总的来讲旋转了一次只是边界条件以及分支判断更恶心加复杂了，但是二分法的思路还是基本不变的。
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = right/2;
        while(left<=right){
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]==nums[left] && nums[mid]==nums[right]){
                left++;
                right--;
            }else if(nums[mid]>=nums[left]){
                if(target>=nums[left] && target<nums[mid]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{
                if(target>nums[mid] && target<=nums[right]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
            mid = (left+right)/2;
        }
        return false;
    }
};