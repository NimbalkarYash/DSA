class Solution {
public:

    int helper(vector<int>& dist, double hour)
    {
        int l =1;
        int r = 1e9;

        int ans = -1;

        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(check(dist, hour, mid))
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        return ans;
    }

    bool check(vector<int>& dist, double hour, int time)
    {

        double sum = 0.0;

        for(int i = 0; i<dist.size()-1;i++)
        {
            sum += (dist[i] + time - 1)/time;
        }
        sum+= ((double)dist[dist.size()-1])/time;

        return sum<=hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        return helper(dist, hour);
    }
};