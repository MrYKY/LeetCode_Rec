
// 经典的二分查找求平方根的算法。注意边界条件的处理，以及mid的更新方式。
class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        if(x==1){
            return 1;
        }

        int left = 0;
        int right = x;
        int mid = x/2;
        while(left<=right){
            if(x/mid==mid){
                return mid;
            }else if(mid<x/mid){
                left = mid+1;
            }else{
                right = mid-1;
            }
            mid = (left+right)/2;
        }
        return mid;
    }
};