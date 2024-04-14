//My Solution
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    //胃口越小越容易满足，先从小数找起
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gsize = g.size();
        int ssize = s.size();
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int satisfynum = 0;
        int i = 0,j = 0;
        while(i<gsize){
            while(j<ssize){
                if(g[i]<=s[j]){
                    satisfynum++;
                    j++;
                    break;
                }
                j++;
            }
            i++;
        }
        return satisfynum;
    }
};



// Best Solution
//没有必要用两个循环，因为数组下标只增不减
class Solution1 {
public:
    int findContentChildren(vector<int>& children, vector<int>& cookies) {
        sort(children.begin(), children.end());
        sort(cookies.begin(), cookies.end());
        int child = 0, cookie = 0;
        while (child < children.size() && cookie < cookies.size()) {
            if (children[child] <= cookies[cookie]) ++child;
            ++cookie;
        }
        return child;
    }
};
