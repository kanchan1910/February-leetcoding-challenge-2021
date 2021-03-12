class Solution {
public:
    string simplifyPath(string path)
    {
        stack<string>s;
        
        string tmp = "";
        string ans = "";
        path += "/";
        int n = path.length();
        for(int i = 1; i < n ; i++)
        {
            if(path[i] != '/')
            {
                tmp += path[i];
            }
            else
            {
                if(tmp == "..")
                {
                    if(!s.empty())
                    {
                        s.pop();
                    }
                }
                else if(tmp != "" && tmp != ".")
                {
                    s.push(tmp);
                }
                tmp = "";
            }
        }
        if(s.empty())
        {
            return "/";
        }
        while(!s.empty())
        {
            ans = "/" + s.top() + ans;
            s.pop();
        }
        return ans;
    }
};


// TC O(N)
// SC O(N)

