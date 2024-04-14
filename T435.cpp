#include <vector>
using namespace std;

/*
我的题解没有通过，废了半天劲，写的那么长，真是笑死了。
思路完全错误。
*/

#define start 0
#define end 1
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int intervalNum = intervals.size();
        int eraseNum = 0;

        vector<int> overlapCount(intervalNum, 0);
        vector<vector<int>> overlapMap(intervalNum,vector<int>(intervalNum, 0));

        for(int i = 0; i<intervalNum; ++i){
            for(int j = i+1; j<intervalNum; ++j){
                if(isOverlap(intervals[i], intervals[j])){
                    overlapMap[i][j] = 1;
                    overlapMap[j][i] = 1;
                    overlapCount[i]++;
                    overlapCount[j]++;
                }
            }
        }

        int index = 0;
        while (true)
        {
            if(!isStillOverlap(overlapCount)){
                break;
            }
            index = findMaxOverlapIndex(overlapCount);
            overlapCount[index] = 0;
            eraseNum++;
            for(int i = 0;i<intervalNum;++i){
                if(overlapMap[index][i]==1){
                    overlapCount[i]--;
                    overlapMap[index][i] = 0;
                    overlapMap[i][index] = 0;
                }
            }
        }
        
    return eraseNum;

    }
private:

    int findMaxOverlapIndex(vector<int>& overlapCount){
        int index = 0;
        int max = 0;
        for(int i = 0;i<overlapCount.size();++i){
            if(overlapCount[i]>max){
                max = overlapCount[i];
                index = i;
            }
        }
        return index;
    }

    bool isStillOverlap(vector<int> overlapCount){
        for(int i = 0;i<overlapCount.size();++i){
            if(overlapCount[i]>0){
                return true;
            }
        }
        return false;
    }
    bool isOverlap(vector<int> intvA, vector<int> intvB){
        if((intvA[start]>=intvB[start]&&intvA[start]<intvB[end])
        ||(intvA[end]>intvB[start]&&intvA[end]<=intvB[end])
        ||(intvA[start]<=intvB[start]&&intvA[end]>=intvB[end])){
            return true;
        }
        return false;
    }
};

/*
贪心算法求无重叠区间
People tend to like who likes them.That is true because I have faced this situation this time.
算法的实现并不难，难点还是在于如何想到这一点。
*/
class Solution1 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int intervalNum = intervals.size();
        int remainIntervalNum = 0;
        if(intervalNum==0||intervalNum==1){
            return 0;
        }
        remainIntervalNum = 1;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
        {return a[1] < b[1];});
        int j = 0;
        for(int i = 0;i<intervalNum;){
            for(j = i+1;j<intervalNum;++j){
                    if(intervals[j][0]>=intervals[i][1]){
                        remainIntervalNum++;
                        i = j;
                        break;
                    }
                }
            if(j==intervalNum) break;
            }
        return intervalNum - remainIntervalNum;
        }
    };