class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        int total = 0;
        int lowest = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int num: nums)
        {
            sum+= num;
            total += num;
            maxi = max(maxi, sum);
            if(sum < 0) sum = 0;
            


            lowest += num;
            mini = min(mini, lowest);
            if(lowest > 0) lowest = 0;  
        }
        if(maxi < 0) return maxi;
        return max(maxi, total - mini);
    }
};