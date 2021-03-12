class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        map<int,int>m;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            m[nums[i]]++;
        }
        vector<pair<int,int>>tmp;
        for(auto x : m)
        {
            tmp.push_back({x.first, x.second});
        }
        if(tmp.size() == 0 || tmp.size() == 1)
        {
            return 0;
        }
        int ans = 0;

        for(int i = 1 ; i < tmp.size(); i++)
        {
            if(abs(tmp[i].first - tmp[i - 1].first) == 1)
            {
                ans = max(ans ,tmp[i].second + tmp[i - 1].second);
            }
        }
        return ans;    
    }
};

// TC O(N)
// SC O(N)
