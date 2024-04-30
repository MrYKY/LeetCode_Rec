#include <vector>
using namespace std;
// 695.岛屿最大面积

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // 在这种巨多的判例题中，不要用static变量，会导致多次调用时出错
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int max_area = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(visited[i][j]==0){
                    visited[i][j] = 1;
                    if(grid[i][j]==1){
                        max_area = max(max_area, dfs(grid, visited, i, j));
                    }
                }
            }
        }
        return max_area;
    }
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j){
        int area = 1;
        static vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto dir:directions){
            int new_i = i+dir[0];
            int new_j = j+dir[1];
            if(new_i>=0 && new_i<grid.size() && new_j>=0 && new_j<grid[0].size()){
                if( visited[new_i][new_j]==0 && grid[new_i][new_j]==1){
                    visited[new_i][new_j] = 1;
                    area += dfs(grid, visited, new_i, new_j);
                }
            }
        }
        return area;
    }
};