class Solution {
public:
    int maxArea(vector<int>& h) 
    {
        int n = h.size();
        int l = 0 , r = n - 1;
        int ans = 0;
        while(l < r)
        {
            ans = max(ans , (r - l) * (min(h[l], h[r])));
            if(h[l] < h[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};

// tc o(n)
// sc o(1)
