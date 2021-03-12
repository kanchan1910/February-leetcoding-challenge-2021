class Solution {
public:
    static bool com(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       vector<pair<int,int>>tmp;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            int count = 0;
            for(int j = 0 ; j < m ; j++)
            {
                if(mat[i][j] == 1)
                {
                    count++;
                }
            }
            tmp.push_back({count , i});
        }
        sort(tmp.begin(),tmp.end(),com);
        vector<int>ans;
        for(int i = 0 ; i < tmp.size() && k > 0; i++)
        {
            k--;
            ans.push_back(tmp[i].second);
        }
        return ans;
    }
};

// tc o(n*m)
// sc o(n)
