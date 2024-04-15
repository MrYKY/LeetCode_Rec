/*
本题的难点是如何不开辟新的空间，在原地进行操作。
如果从小的开始排序，那么就会涉及到移动元素，会很麻烦也没必要。
既然num1的后半部分是空的，所以我们可以从大的开始排序，先对后半部分进行正确填充，这样就不会涉及到移动元素。
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m+n-1;
        m = m-1;
        n = n-1;
        while(index>=0){
            if(m<0){
                nums1[index] = nums2[n];
                --n;
                --index;
                continue;
            }
            if(n<0){
                nums1[index] = nums1[m];
                --m;
                --index;
                continue;
            }
            if(nums1[m]>nums2[n]){
                nums1[index] = nums1[m];
                --m;
                --index;
            }else{
                nums1[index] = nums2[n];
                --n;
                --index;
            }
        }
    }
};