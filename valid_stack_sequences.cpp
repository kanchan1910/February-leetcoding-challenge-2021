class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int>s;
        int n = pushed.size();
        int j = 0;
        for(int i = 0 ; i < n ;i++)
        {
            s.push(pushed[i]);
            while(!s.empty() && j < n && s.top() == popped[j])
            {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};

// tc o(n)
// sc o(n)
