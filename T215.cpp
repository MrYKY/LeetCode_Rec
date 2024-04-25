
#include <vector>

using namespace std;

// 215.数组中第K个最大元素
// 开始写之前就意识到这是一个非常经典的问题，已经见过不知道多少次了，但总是看过就忘记。
// 确实，其最合理的解法就是做了一半的快排，然后判断一下当前的pivot是不是第K个，如果是就返回，如果不是就继续递归。

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int left = 0;
        int n = nums.size();
        int right = n - 1;
        int pivot = nums[left];
        // Start和End是用来记录当前pivot的左右边界的。之后也要更新
        int start = left;
        int end = right;

        while (left < right)
        {
            while (left < right)
            {
                while (left < right && nums[right] <= pivot)
                {
                    right--;
                }
                nums[left] = nums[right];
                while (left < right && nums[left] >= pivot)
                {
                    left++;
                }
                nums[right] = nums[left];  
            }
            nums[left] = pivot;
            if (left == k - 1)
            {
                return pivot;
            }
            else if (left < k - 1)
            {
                right = end;
                // 考虑到一个全是1的特殊用例，复杂度到了On2只能这么搞了。
                while(left < right && nums[left] == pivot&&left<k-1)
                {
                    left++;
                }
                start = left;
                pivot = nums[left];
            }
            else
            {
                right = left - 1;
                end = right;
                left = start;
                pivot = nums[left];
            }
        }

        return pivot;
    }
};