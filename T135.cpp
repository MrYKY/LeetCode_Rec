#include <vector>
using namespace std;

// 我的方法很直觉，正确性上也没考虑，有可能死循环，毕竟时间太长没过
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int childnum = ratings.size();
        if (childnum == 1)
        {
            return 1;
        }
        vector<int> candys(childnum, 1);
        bool adjustingDone = false;
        while (!adjustingDone)
        {
            adjustingDone = true;
            for (int i = 0; i < childnum; ++i)
            {
                if (i == 0)
                {
                    if (ratings[i] > ratings[i + 1] && candys[i] <= candys[i + 1])
                    {
                        candys[i] = candys[i + 1] + 1;
                        adjustingDone = false;
                    }
                    else if (ratings[i] < ratings[i + 1] && candys[i] >= candys[i + 1])
                    {
                        candys[i + 1] = candys[i] + 1;
                        adjustingDone = false;
                    }
                }
                else if (i == childnum - 1)
                {
                    if (ratings[i] > ratings[i - 1] && candys[i] <= candys[i - 1])
                    {
                        candys[i] = candys[i - 1] + 1;
                        adjustingDone = false;
                    }
                    else if (ratings[i] < ratings[i - 1] && candys[i] >= candys[i - 1])
                    {
                        candys[i - 1] = candys[i] + 1;
                        adjustingDone = false;
                    }
                }
                else
                {
                    if (ratings[i] > ratings[i - 1] && candys[i] <= candys[i - 1])
                    {
                        candys[i] = candys[i - 1] + 1;
                        adjustingDone = false;
                    }
                    else if (ratings[i] < ratings[i - 1] && candys[i] >= candys[i - 1])
                    {
                        candys[i - 1] = candys[i] + 1;
                        adjustingDone = false;
                    }
                    if (ratings[i] > ratings[i + 1] && candys[i] <= candys[i + 1])
                    {
                        candys[i] = candys[i + 1] + 1;
                        adjustingDone = false;
                    }
                    else if (ratings[i] < ratings[i + 1] && candys[i] >= candys[i + 1])
                    {
                        candys[i + 1] = candys[i] + 1;
                        adjustingDone = false;
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < childnum; ++i)
        {
            sum += candys[i];
        }
        return sum;
    }
};

/*
这个两次遍历方法并不难看懂，关键是对于其正确性的理解。
正反两次遍历，第一次遍历保证右边的孩子相对于左边孩子有一个正确的比较关系，而往回遍历则单独处理左边孩子相对于右边孩子的比较关系。
首先第一个问题是，第一次遍历是满足1.左孩子大于右孩子的情况，还是满足2.右孩子大于左孩子的情况？
如果1，则每次调整的对象是左孩子，而其对应的右孩子可能会由于接下来的计算而再次被调整，使得刚刚满足的条件又不满足了。
如果2，则每次调整的对象是右孩子，而其对应的左孩子不会再次被调整，因为左孩子的调整是在右孩子调整之前的，这样一次遍历后就能够保证右孩子得分更高的糖果一定更多。
根据以上的分析也可知，要保证右大于左的情况满足，必须从左往右遍历。
同理，要保证左大于右的情况满足，必须从右往左遍历。
则问题又在于，第二次遍历会不会破坏第一次遍历所形成的关系？
当左边孩子与其右边孩子有正确的数据关系后，则凡是右边评分更大的情况，右边孩子得到的糖果都更多，从后往前遍历时，如果左边的孩子评分更高，则在第一次遍历后，其一定大于等于其右孩子的糖果数，则需要完成的操作是如果等于则增加，如果大于则不变，不可能小于。
则对于左孩子的操作是增加或不变，只有增加可能会影响之前的关系。
当第一次遍历已经满足右大于左的情况后，对于第二次遍历的当前孩子对来说，肯定是没有问题的，而因为改变了当前的左孩子，所以可能会破坏第一次遍历中目前左孩子作为右孩子的关系，在这一对孩子中，如果右孩子更大，则再增加当然没有问题，如果右孩子更小却增加了，确实可能会临时破坏第一遍形成的正确关系，而往下的继续遍历却会立刻修复这个关系（通过让左孩子增加）。
所以第二次遍历不会破坏第一次遍历的关系。
从更高的角度来看，这是运用贪心的思想，局部最优即为一个比较方向的最优。
*/

class Solution1
{
public:
    int candy(vector<int> &ratings)
    {
        int size = ratings.size();
        if (size < 2)
        {
            return size;
        }
        vector<int> num(size, 1);
        for (int i = 1; i < size; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                num[i] = num[i - 1] + 1;
            }
        }
        for (int i = size - 1; i > 0; --i)
        {
            if (ratings[i] < ratings[i - 1])
            {
                num[i - 1] = max(num[i - 1], num[i] + 1);
            }
        }
        return accumulate(num.begin(), num.end(), 0);
    }
};