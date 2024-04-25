
#include <vector>

using namespace std;

// 二分法最让人头疼的就是边界条件的判定，但这个写法竟然意外地通过了，而且非常简洁。核心就是更新left或right的时候，要避开mid。
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = right/2;
        while(left<=right){
            if(nums[mid]==target){
                break;
            }
            if(nums[mid]<target){
                left = mid+1;
            }else{
                right = mid-1;
            }
            mid = (left+right)/2;
        }
        if(left>right){
            return {-1, -1};
        }
        int i = mid;
        int j = mid;
        while(i>=0 && nums[i]==target){
            i--;
        }
        while(j<nums.size() && nums[j]==target){
            j++;
        }
        return {i+1, j-1};

    }
};