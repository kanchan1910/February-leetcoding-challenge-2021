class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A)
    {
        int n = A.size();
        if(n < 3)
        {
            return 0;
        }
        // will store ki iss point p khtm hone wali kitni AP's hai
        int dp[n];
        dp[0] = dp[1] = 0;
    
        for(int i = 2 ; i < n ; i++)
        {
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            {
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                dp[i] = 0;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n; i++)
        {
            ans += dp[i];
        }
        return ans;
    }
};

// tc o(n)
// sc o(n)

// https://youtu.be/rSi4MpGEz1M 
