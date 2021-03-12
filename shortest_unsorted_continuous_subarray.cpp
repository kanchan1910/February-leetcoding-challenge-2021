class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
        {
            return 0;
        }
        int l = 0 , r = n - 1;
        int ans = 0;
        while(l < r)
        {
            if(nums[l] > nums[r])
            {
                ans = r - l + 1;
                break;
            }
            else
            {
                if(nums[l + 1] >= nums[l] && nums[r - 1] <= nums[r])
                {
                    l++;
                    r--;
                }
                else if(nums[l + 1] >= nums[l])
                {
                    l++;
                }
                else if(nums[r - 1] <= nums[r])
                {
                    r--;
                }
                else
                {
                    ans = r - l + 1;
                    break;
                }
            }
        }
        int mini = INT_MAX , maxi = INT_MIN;
        for(int i = l ; i <= r; i++)
        {
            mini = min(mini , nums[i]);
            maxi = max(maxi , nums[i]);
        }
        for(int i = 0 ; i <= l - 1; i++)
        {
            if(nums[i] > mini)
            {
                ans += (l - i);
                break;
            }
        }
        for(int i = n - 1; i >= r + 1 ; i--)
        {
            if(nums[i] < maxi)
            {
                ans += (i - r);
                break;
            }
        }
        return ans;
    }
};
// tc o(n)
// sc o(1)
