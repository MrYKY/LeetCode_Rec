
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;


// 经典的滑动窗口问题，编写过程的难点是各种边界条件的处理，很恶心。整体思路非常清晰明了。
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> needs;
        for(char c:t){
            needs[c]++;
        }
        int needcnt = 0;
        for(pair<char, int> need:needs){
            needcnt+=need.second;
        }
        int left = 0;
        int right = 0;
        int minlen = INT_MAX;
        int minleft = 0;
        while(right<s.size()){
            if(needs.find(s[right])!=needs.end()){
                needs[s[right]]--;
                if(needs[s[right]]>=0){
                    needcnt--;
                }
            }
            if(needcnt==0){
                while(needcnt==0){
                    if(right-left+1<minlen){
                        minlen = right-left+1;
                        minleft = left;
                    }
                    if(needs.find(s[left])!=needs.end()){
                        needs[s[left]]++;
                        if(needs[s[left]]>0){
                            needcnt++;
                        }
                    }
                    left++;
                }
            }
            right++;
        }
        if(minlen==INT_MAX){
            return "";
        }
        return s.substr(minleft, minlen);

    }
};