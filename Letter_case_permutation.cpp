class Solution {
public:
    void fun(vector<string>&ans, string S, string op, int idx)
    {
        if(idx == S.length())
        {
            ans.push_back(op);
            return;
        }
        if(isdigit(S[idx]))
        {
            op.push_back(S[idx]);
            fun(ans ,S, op, idx + 1);
        }
        else // alphabets
        {
            string op1 = op;
            string op2 = op;
            op1.push_back(tolower(S[idx]));
            op2.push_back(toupper(S[idx]));
            fun(ans, S, op1,idx + 1);
            fun(ans , S, op2, idx + 1);
        }
    }
    vector<string> letterCasePermutation(string S)
    {
        vector<string>ans;
        fun(ans , S, "", 0);
        return ans;
    }
};
