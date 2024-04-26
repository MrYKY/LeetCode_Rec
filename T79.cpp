#include <vector>
#include <string>
using namespace std;

// 79.单词搜索
// 这个写法写了半天没有考虑不能重复访问的问题，整体上是错误的。
// 逻辑对了，时间复杂度也和例子一样，但就是超出时间限制了，不知道哪里该优化。
// 看到一个评论：用二维数组存方向超时，拆开成vector xDirects = {-1, 1, 0, 0};vector yDirects = {0, 0, -1, 1};这样的一维数组就击败70%，有意思吗这样？
// WOKKKKKKKKKK!!!!!!!!!!!!!!!!!!!! 终于发现问题所在了！！！！对二维数组的访问/修改会极大地拖慢速度！！看我中间注释掉的visited[i][j] = false;，注释掉之前超出时间，注释掉时候性能比官方题解要快！
// WOKKKKKKKKKK！！！！！！！！！又一次发现了问题所在！！！其实也不是二维数组的访问/修改拖慢了速度，而是出现了死循环！对于visited数组的修改，要本着谁改成true的，谁负责改成false，看下面注释，如果发现visited，然后在返回false之前却把visited给改了，这个逻辑就离谱的很！
class Solution
{
public:
    // vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> xDirects = {-1, 1, 0, 0};
    vector<int> yDirects = {0, 0, -1, 1};
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, word, 0, i, j, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, string &word, int index, int i, int j, vector<vector<bool>> &visited)
    {
        if (!(i >= 0 && i < board.size() && j >= 0 && j < board[0].size()))
        {
            return false;
        }
        if (visited[i][j])
        {
            // visited[i][j] = false; 
            //！！！！！实际上不是访问数组的问题，而是这里出现了死循环。！！！！！！
            return false;
        }
        visited[i][j] = true;
        if (board[i][j] != word[index])
        {
            visited[i][j] = false;
            return false;
        }
        if (index == word.length() - 1)
        {
            return true;
        }
        // visited[i][j] = true;//改到这个位置
        for (int ind : {0, 1, 2, 3})
        {
            if (dfs(board, word, index + 1, i + xDirects[ind], j + yDirects[ind], visited))
            {
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
};

// 完美的解法是这样的，它与我最大的区别是没有使用一个表来记录visited。
// 我与这个几乎完全一样的思路，但就是一个不超时一个超时，问题在哪里呢？
class Solution1
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    int rows, cols;
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int k)
    {
        if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k])
            return false;
        if (k == word.size() - 1)
            return true;
        board[i][j] = '\0';
        bool res = dfs(board, word, i + 1, j, k + 1) ||
                   dfs(board, word, i - 1, j, k + 1) ||
                   dfs(board, word, i, j + 1, k + 1) ||
                   dfs(board, word, i, j - 1, k + 1);
        board[i][j] = word[k];
        return res;
    }
};
