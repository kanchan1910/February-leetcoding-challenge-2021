// Nice problem 

// using bfs and treating binary matrix like undirected , unweighted graph 

class Solution {
public:
    bool isvalid(int x, int y, int n ,int m , vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        if(x < 0 || y < 0 || x >= n || y >=m || grid[x][y] == 1 || vis[x][y] == true)
        {
            return false;
        }
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
        {
            return -1;
        }
        vector<vector<int>>vis(n, vector<int>(m, false));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0] = true;
        int level = 0;
        while(!q.empty())
        {
            int sz = q.size();
            level++;
            for(int i = 0; i < sz ; i++)
            {
                pair<int,int>cur = q.front();
                q.pop();
                int x = cur.first;
                int y = cur.second;
                if(x== n - 1 && y == m - 1)
                {
                    return level;
                }
                if(isvalid(x - 1, y , n ,m , grid, vis) == true)
                {
                    vis[x - 1][y] = true;
                    q.push({x - 1, y});
                }
                 if(isvalid(x + 1, y , n ,m , grid, vis) == true)
                {
                    vis[x + 1][y] = true;
                    q.push({x + 1, y});
                }
                 if(isvalid(x - 1, y - 1 , n ,m , grid, vis) == true)
                {
                    vis[x - 1][y - 1] = true;
                    q.push({x - 1, y - 1});
                }
                 if(isvalid(x - 1, y + 1, n ,m , grid, vis) == true)
                {
                    vis[x - 1][y + 1] = true;
                    q.push({x - 1, y + 1});
                }
                 if(isvalid(x , y - 1, n ,m , grid, vis) == true)
                {
                    vis[x][y - 1] = true;
                    q.push({x, y - 1});
                }
                 if(isvalid(x, y + 1 , n ,m , grid, vis) == true)
                {
                    vis[x ][y + 1] = true;
                    q.push({x, y + 1});
                }
                 if(isvalid(x + 1, y + 1, n ,m , grid, vis) == true)
                {
                    vis[x + 1][y + 1] = true;
                    q.push({x + 1, y + 1});
                }
                 if(isvalid(x + 1, y - 1, n ,m , grid, vis) == true)
                {
                    vis[x + 1][y - 1] = true;
                    q.push({x + 1, y - 1});
                }
            }
        }
        return -1;
    }
};



// OR



class Solution {
public:
    bool isvalid(int x, int y, int n ,int m , vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        if(x < 0 || y < 0 || x >= n || y >=m || grid[x][y] == 1 || vis[x][y] == true)
        {
            return false;
        }
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
        {
            return -1;
        }
        vector<vector<int>>vis(n, vector<int>(m, false));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0] = true;
        int level = 0;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,-1},{0,1},{-1,-1},{1,-1},{1,1},{-1,1}};
        while(!q.empty())
        {
            int sz = q.size();
            level++;
            for(int i = 0; i < sz ; i++)
            {
                pair<int,int>cur = q.front();
                q.pop();
                int x = cur.first;
                int y = cur.second;
                if(x== n - 1 && y == m - 1)
                {
                    return level;
                }
           
               for(int i = 0 ; i < 8 ; i++)
               {
                   int new_x = x + dir[i][0];
                   int new_y = y + dir[i][1];
                   if(isvalid(new_x, new_y, n, m, grid, vis) == true)
                   {
                       q.push({new_x, new_y});
                       vis[new_x][new_y] = true;
                   }
               }
            }
        }
        return -1;
    }
};


// we can also improve these solution by removing visited array and instead marking grid[new_x][new_y] = 1 as the indication that it is visited and when we will make grid[new_x][new_y] = 1 then we will never traverse it again and that we know that if grid[new_x][new_y] = 1 then we will not ho as it is seen as blocked cell , so there is no need to make extra visited vector . 
