class Solution {
public:
    bool isSubsequence(string str, string pat, int n1, int n2)
    {
        int pati = 0, strj = 0;
        
        while (pati < pat.length() && strj < str.length()) {
            
            if (pat[pati] == str[strj])
            {
              pati++;    
            }
            strj++;
        }
        
        return pati == pat.length();
 
    }
    string findLongestWord(string s, vector<string>& d) 
    {
        string ans = "";
        for(int i = 0 ; i < d.size(); i++)
        {
            if(isSubsequence(s, d[i], s.length(), d[i].length()) == true)
            {
                if((ans.length() < d[i].length()) || (ans.length() == d[i].length() && d[i] < ans))
                {
                    ans = d[i];
                }
            }
        }
        return ans;
    }
};
// accepted


class Solution {
public:
    bool isSubsequence(string str, string pat, int n1, int n2)
    {
        if(n2 == 0)
        {
            return true;
        }
        if(n1 == 0)
        {
            return false;
        }
        if(str[n1 - 1] == pat[n2 - 1])
        {
            return isSubsequence(str, pat, n1 - 1, n2 - 1);
        }
        else
        {
            return isSubsequence(str, pat , n1 - 1, n2);
        }
    }
    string findLongestWord(string s, vector<string>& d) 
    {
        string ans = "";
        for(int i = 0 ; i < d.size(); i++)
        {
            if(isSubsequence(s, d[i], s.length(), d[i].length()) == true)
            {
                if((ans.length() < d[i].length()) || (ans.length() == d[i].length() && d[i] < ans))
                {
                    ans = d[i];
                }
            }
        }
        return ans;
    }
};
// TLE
