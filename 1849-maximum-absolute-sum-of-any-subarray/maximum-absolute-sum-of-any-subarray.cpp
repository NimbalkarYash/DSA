class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sump = 0;
        int sumn = 0;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        int result;

        for(int num: nums)
        {
            //most maximum postitive number
            sump += num;
            maxi = max(sump, maxi);
            if(sump < 0 ) sump = 0;

            //most largest negative number
            sumn += num;
            mini = min(mini, sumn);
            if(sumn > 0)sumn = 0;

        }
        result =  max(maxi, -mini);
        return result;
    }
};