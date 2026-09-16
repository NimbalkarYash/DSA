class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0;
        int maxu = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];

            if(maxu<sum){
                maxu = sum;
            } 
            
            if(sum<0){
                sum = 0;
                continue;
            } 
        }

        return maxu;
    }
};