class Solution {
public:

    int BinaryTraversal(vector<int>& weights, int days)
    {
        int low = 0;
        long long high = 0;
        

        for(auto i: weights)
        {
            low = max(i, low);
            high += i;
        }

        int ans = high;
        long long total = high;
        while(low<=high)
        {
            int mid = low+(high-low)/2;

            if(check(weights, days, mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return ans;

    }

    bool check(vector<int>& weights, int days, int capacity)
    {
        int daysNeeded = 1;
        int currentLoad = 0;

        for(int w : weights) {

            if(currentLoad + w  > capacity) {//if adding the new load exceeds the capacity, this load is shipped the next day, hence increment the day, and set load to the new load
                daysNeeded++;      
                currentLoad = w;  
            } 
            //it reaches exact capacity, then reset it and start a new day
            else
            {
                currentLoad+=w;
            }
        }
        
        // If we needed more days than allowed, this capacity is invalid
        return daysNeeded <= days; 
        
    }

    int shipWithinDays(vector<int>& weights, int days) {
        return BinaryTraversal(weights, days);
    }
};