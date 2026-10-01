class Solution {
public:
    int helper(vector<int>& bloomDay, int m, int k)
    {
        int l = 0;
        int h = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(l<=h)
        {
            int mid = l + (h-l)/2;

            if(check(bloomDay, m, k, mid))
            {
                ans = mid;
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        return ans;
    }

    bool check(vector<int>& bloomDay, int m, int k, int days)
    {
        int flowers = 0;
        int boque = 0;

        for(int i=0; i<bloomDay.size();i++)
        {
            if(bloomDay[i] <= days)
            {
                flowers++;
                
                if(flowers == k)
                {
                    boque++;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }
        }
        return boque >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        return helper(bloomDay, m, k);
    }
};