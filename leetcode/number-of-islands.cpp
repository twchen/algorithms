/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
 */

// similar to union find algorithm but with some optimization
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        vector<vector<int>> groups(m, vector<int>(n));
        int g = 0;
        if(grid[0][0] == '1') groups[0][0] = ++g;
        for(int i = 1; i < m; ++i){
            if(grid[i][0] == '1'){
                groups[i][0] = grid[i - 1][0] == '1' ? groups[i - 1][0] : ++g;
            }   
        }
        for(int j = 1; j < n; ++j){
            if(grid[0][j] == '1'){
                groups[0][j] = grid[0][j - 1] == '1' ? groups[0][j - 1] : ++g;
            }   
        }
        int count = g;
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(grid[i][j] == '0') continue;
                if(grid[i][j - 1] == '0' && grid[i - 1][j] == '0'){
                    groups[i][j] = ++g;
                    ++count;
                }else if(grid[i][j - 1] == '0'){
                    groups[i][j] = groups[i - 1][j];
                }else if(grid[i - 1][j] == '0'){
                    groups[i][j] = groups[i][j - 1];
                }else if(groups[i - 1][j] == groups[i][j - 1]){
                    groups[i][j] = groups[i][j - 1];
                }else{
                    int g1 = groups[i][j - 1];
                    int g2 = groups[i - 1][j];
                    int real_g1 = find(g1);
                    int real_g2 = find(g2);
                    int min_g = min(real_g1, real_g2);
                    if(real_g1 != real_g2){
                        --count;
                        remap(g1, real_g1, min_g);
                        remap(g2, real_g2, min_g);
                    }
                    groups[i][j] = min_g;
                }
            }
        }
        return count;
    }
    
    int find(int group){
        auto it = hash.find(group);
        if(it != hash.end()) return it->second;
        else return group;
    }
    
    void remap(int g, int real_g, int min_g){
        hash[g] = min_g;
        if(g != real_g) hash[real_g] = min_g;
    }

private:
    unordered_map<int, int> hash;
};

// more efficient implementation of the above idea
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        vector<vector<int>> groups(m, vector<int>(n));
        vector<int> hash = { 0 };
        int g = 0;
        if(grid[0][0] == '1'){
            groups[0][0] = ++g;
            hash.push_back(g);
        }
        for(int i = 1; i < m; ++i){
            if(grid[i][0] == '1'){
                if(grid[i - 1][0] == '1'){
                    groups[i][0] = groups[i - 1][0];
                }else{
                    groups[i][0] = ++g;
                    hash.push_back(g);
                }
            }   
        }
        for(int j = 1; j < n; ++j){
            if(grid[0][j] == '1'){
                if(grid[0][j - 1] == '1'){
                    groups[0][j] = groups[0][j - 1];
                }else{
                    groups[0][j] = ++g;
                    hash.push_back(g);
                }
            }
        }
        int count = g;
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(grid[i][j] == '0') continue;
                if(grid[i][j - 1] == '0' && grid[i - 1][j] == '0'){
                    groups[i][j] = ++g;
                    hash.push_back(g);
                    ++count;
                }else if(grid[i][j - 1] == '0'){
                    groups[i][j] = groups[i - 1][j];
                }else if(grid[i - 1][j] == '0'){
                    groups[i][j] = groups[i][j - 1];
                }else{
                    int g1 = groups[i][j - 1];
                    int g2 = groups[i - 1][j];
                    int real_g1 = hash[g1];
                    int real_g2 = hash[g2];
                    groups[i][j] = real_g1;
                    if(real_g1 == real_g2) continue;
                    --count;
                    if(real_g1 < real_g2){
                        hash[g2] = hash[real_g2] = real_g1;
                    }else{
                        hash[g1] = hash[real_g1] = groups[i][j] = real_g2;
                    }
                }
            }
        }
        return count;
    }
};

// naive solutions

// dfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j){
        grid[i][j] = 'x';
        if(i > 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j);
        if(i + 1 < grid.size() && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
        if(j > 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
        if(j + 1 < grid[0].size() && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
    }
};

// bfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
    
    void bfs(vector<vector<char>> &grid, int x, int y){
        queue<pair<int, int>> q;
        q.emplace(x, y);
        grid[x][y] = 'x';;
        while(!q.empty()){
            auto p = q.front();
            int i = p.first, j = p.second;
            q.pop();
            if(i > 0 && grid[i - 1][j] == '1'){
                q.emplace(i - 1, j);
                grid[i - 1][j] = 'x';
            }
            if(i + 1 < grid.size() && grid[i + 1][j] == '1'){
                q.emplace(i + 1, j);
                grid[i + 1][j] = 'x';
            }
            if(j > 0 && grid[i][j - 1] == '1'){
                q.emplace(i, j - 1);
                grid[i][j - 1] = 'x';
            }
            if(j + 1 < grid[0].size() && grid[i][j + 1] == '1'){
                q.emplace(i, j + 1);
                grid[i][j + 1] = 'x';
            }
        }
    }
};

// wrong implementation of bfs
// because some points are push to queue more than once.
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    bfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
    
    void bfs(vector<vector<char>> &grid, int i, int j){
        static const vector<pair<int, int>> diff { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        queue<pair<int, int>> q;
        q.emplace(i, j);
        while(!q.empty()){
            int sz = q.size();
            for(int k = 0; k < sz; ++k){
                auto p = q.front();
                grid[p.first][p.second] = 'x'; // mark as visited
                q.pop();
                for(auto d : diff){
                    int x = p.first + d.first;
                    int y = p.second + d.second;
                    if(0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[x][y] == '1')
                        q.emplace(x, y);
                }
            }
        }
    }
};