// Nice Problem

class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        string ans = "";
        int o = 0 , c= 0;
        int n = s.length();
        for(int i = 0 ; i <n ; i++)
        {
            if(s[i] == '(')
            {
                o++;
            }
            else if(s[i] == ')')
            {
                c++;
            }
            if(c > o)
            {
                s[i] = '*';
                c--;
            }
        }
        
        o = 0 , c = 0;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(s[i] == '(')
            {
                o++;
            }
            else if(s[i] == ')')
            {
                c++;
            }
            if(o > c)
            {
                s[i] = '*';
                o--;
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] != '*')
            {
                ans += s[i];
            }
        }
        return ans;
    }
};

// tc o(n)
// sc o(1)



class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        string ans = "";
        stack<pair<char, int>>st;
        int n = s.length();
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '(')
            {
                st.push({s[i], i});
            }
            else if(s[i] == ')')
            {
                if(st.empty())
                {
                    st.push({s[i], i});
                }
                else
                {
                    if(st.top().first == '(')
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push({s[i],i});
                    }
                }
            }
        }
        if(st.empty())   // means string is already balanced 
        {  
            return s;
        }
        while(!st.empty())   // marking those characters that we want to remove
        {   
            s[st.top().second] = '*';
            st.pop();
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] != '*')
            {
                ans += s[i];
            }
        }
        return ans;
    }
};

// tc o(n)
// sc O(n)
