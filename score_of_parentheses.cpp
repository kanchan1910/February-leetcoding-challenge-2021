class Solution {
public:
    int scoreOfParentheses(string S) 
    {
        int ans = 0;
        stack<int>s;
        s.push(0); // initially score is 0
        int n = S.length();
        for(int i = 0 ; i < n ; i++)
        {
            if(S[i] == '(')
            {
                s.push(0);
            }
            else
            {
                if(s.top() == 0) // add wala case
                {
                    s.pop();
                    s.top() += 1;
                    
                }
                else // multiply wala case
                {
                    int val = s.top();
                    s.pop();
                    s.top() += 2 * val;
                }
            }
        }
        while(!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};
// tc o(n)
// sc o(n)
