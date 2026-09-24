class Solution {
public:

    int FindFirst(vector<int>& nums, int target)
    {
        int l= 0;
        int r = nums.size() - 1;
        int first = -1;
        

        while(l<=r)
        {
            int m = l + (r-l)/2;

            if(nums[m] == target)
            {
                first = m;
                r = m-1;
            }
            else if(target > nums[m])
            {
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }
        return first;
    }

    int FindSecond(vector<int>& nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int second = -1;
        

        while(l<=r)
        {
            int m = l + (r-l)/2;

            if(nums[m] == target)
            {
                second = m;
                l = m+1;
            }
            else if(target > nums[m])
            {
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }

        return second;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = FindFirst(nums, target);
        if(l == -1) return {-1,-1};
        int r = FindSecond(nums, target);

        return {l,r};
    }
};