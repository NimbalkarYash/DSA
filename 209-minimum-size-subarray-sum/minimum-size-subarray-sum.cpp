class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int mini = INT_MAX;
        int left = 0;
        int sum = 0;

        for(int r=0;r<nums.size();r++)
        {
            sum+= nums[r];

            while(sum >= target && left <= r)
            {
                mini = min(r-left+1, mini);
                sum -= nums[left];
                left++;
            }
        }
        return (mini == INT_MAX) ? 0:mini;
    }
};