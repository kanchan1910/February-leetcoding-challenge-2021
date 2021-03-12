class Solution {
public:
    vector<int> shortestToChar(string s, char c) 
    {
        vector<int>pos;
        int n = s.length();
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == c)
            {
                pos.push_back(i);
            }
        }
        vector<int>ans(n);
        for(int i = 0 ; i < n ; i++)
        {
            int mn = INT_MAX;
            for(int j = 0 ; j < pos.size(); j++)
            {
                mn = min(mn , abs(pos[j] - i));
            }
            ans[i] = mn;
        }
        return ans;
    }
};

// tc o(n*n)
// sc o(n)


class Solution {
public:
    vector<int> shortestToChar(string s, char c) 
    {
       int n = s.length();
        vector<int>ans(n,10005);
        int dis = 10005;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == c)
            {
                dis = 0;
            }
            ans[i] = dis;
            dis++;
        }
        for(int i = n - 1 ; i >= 0 ;i--)
        {
            if(s[i] == c)
            {
                dis = 0;
            }
            ans[i] = min(ans[i], dis);
            dis++;
        }
        return ans;
    }
};
// tc o(n)
// sc o(1)
