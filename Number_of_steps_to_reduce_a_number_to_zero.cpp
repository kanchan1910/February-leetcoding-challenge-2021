class Solution {
public:
    int numberOfSteps (int num) {
        if(num == 0)
        {
            return 0;
        }
        int ans = 0;
        while(num != 0)
        {
        if(num % 2 != 0)
        {
            ans++;
            num--;
        }
        else
        {
            while(num % 2 == 0 && num != 0)
            {
                ans++;
                num /= 2;
            }
        }   
        }
        return ans;
    }
};
// tc o(N)
// sc O(1)
