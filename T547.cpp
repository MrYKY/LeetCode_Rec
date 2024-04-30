#include <vector>
using namespace std;


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int circleNum = 0;
        for(int i=0;i<isConnected.size();i++){
            for(int j=i;j<isConnected.size();j++){
                if(isConnected[i][j]==1){
                    dfs(isConnected, i, j);
                    circleNum++;
                }
            }
        }
        return circleNum;
    }
    void dfs(vector<vector<int>>& isConnected, int i, int j){
        isConnected[i][j] = 0;
        isConnected[j][i] = 0;
        for(int k=0;k<isConnected.size();k++){
            if(isConnected[j][k]==1){
                dfs(isConnected, j, k);
            }
        }
    }
};