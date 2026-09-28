class Solution {
public:

    int BinaryTraversal(vector<int>& piles, int h)
    {
        int low = 1;
        int high = 0;

        //finding the biggest pile
        for(auto i : piles)
        {
            high = max(i, high);
            
        }

        //low must be the average time taken for each pile
        int ans = high;

        while(low<=high)
        {
            int mid = low + (high - low)/2;

            if(checkIfPossible(piles, h, mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid +1;
            }
        }

        return ans;
    }

    bool checkIfPossible(vector<int>& piles, int h, int k)
    {
        long long sum= 0;
        for(auto i: piles)
        {
            sum+= (i+k-1)/k;
            //this is done to get the upper bound
        }

        return sum<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = BinaryTraversal(piles, h);
        return ans;
    }
};