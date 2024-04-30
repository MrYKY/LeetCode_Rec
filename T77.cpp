#include <vector>
using namespace std;


// 77.组合
// 与46.排列差不多，甚至更简单
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> conbination;
        backtrack(res, conbination, n, k, 1);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& conbination, int n, int k, int index){
        if(conbination.size()==k){
            res.push_back(conbination);
            return;
        }
        for(int i=index;i<=n;i++){
            conbination.push_back(i);
            backtrack(res, conbination, n, k, i+1);
            conbination.pop_back();
        }
    }
};