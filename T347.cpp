#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
// 347.前K个高频元素
// 本题对我来说的难点在于：1.堆排序忘了；2.C++的优先队列没听说过。
// 堆就是一个完全二叉树，其性质为：1.父节点的值大于（小于）子节点；2.堆是一个完全二叉树。（完全二叉树是指除了最后一层，其他层都是满的，最后一层的节点都靠左排列）
class Solution {
public:
    
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        priority_queue<pair<int, int>,vector<pair<int, int>>,mycomparison> pri_que;
        for(pair<int,int> it:freq){
            pri_que.push(it);
            if(pri_que.size()>k){
                pri_que.pop();
            }
        }
        vector<int> res;
        while(!pri_que.empty()){
            res.push_back(pri_que.top().first);
            pri_que.pop();
        }
        return res;
    }
};