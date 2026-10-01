class Solution {
public:
    int helper(vector<int> &arr, int k)
    {
        if(arr.size() < k) return -1;
        long long l = 0;
        long long h = 0;
        
        for(int p: arr)
        {
            l = max(l, (long long)p);
            h+= p;
        }
        
        long long ans = -1;
        
        while(l<=h)
        {
            long long mid = l + (h-l)/2;
            
            if(check(arr, k, mid))
            {
                ans= mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return (int)ans;
    }
    
    bool check(vector<int> &arr, int k, long long  page)
    {
        int pageSum = 0;
        int grp = 1;
        for(int p:arr)
        {
            if(pageSum + p <= page)
            {
                pageSum+= p;
            }
            else
            {
                grp++;
                pageSum = p;
            }
        }
        return grp <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        return helper(nums, k);
    }
};