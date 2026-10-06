class Solution {
  public:
  
    int helper(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();       //row
        int m = mat[0].size();    //column
        int low = mat[0][0];
        int high = mat[0][m-1];
        int count = 0;
        int ans = 0;
        
        
        for(auto &row : mat)
        {
            low = min(low, row[0]);
            high = max(high, row[m-1]);
        }

        
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            count = CountTheSmallestNumber(mat, mid);
            
            if(count < k)
            {
                low = mid+1;
            }
            else
            {
                ans = mid;
                high = mid-1;
            }
            
        }
        return ans;
    }
    
    int CountTheSmallestNumber(vector<vector<int>> &mat, int mid)
    {
        
        int count = 0;
        
       for(auto &row : mat)
        {
            count += upper_bound(row.begin(), row.end(), mid) - row.begin();
        }
        return count;
        
    }
    
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        int k = (n * m + 1) / 2;

        return helper(mat, k);
    }
};
