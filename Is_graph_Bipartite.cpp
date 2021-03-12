class Solution {
public:
    bool dfs(int n ,vector<vector<int>>& graph, vector<int>&color, int source, int col)
    {
        color[source] = col;
        for(auto child : graph[source])
        {
            if(color[child] == -1)
            {
                if(dfs(n,graph,color,child,!col) == false)
                {
                    return false;
                }
            }
            else
            {
                if(color[source] == color[child])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph)
    {
      int n = graph.size();
      vector<int>color(n, -1);
      for(int i = 0 ; i < n ; i++)
      {
          if(color[i] == -1)
          {
               if(dfs(n,graph,color,i,0) == false)
               {
                   return false;
               }
          }
      }
        return true;
    }
};
