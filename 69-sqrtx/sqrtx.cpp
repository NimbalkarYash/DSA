class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x ==1) return 1;
        int l = 0;
        int r = x/2;

        while(l<=r)
        {
            long long mid = (l+r)/2;
            long long sum = mid*mid;
            if(sum == x) return abs(mid);

            if(sum < x)
            {
                l= mid+1;
            }
            if(sum > x)
            {
                r = mid-1;
            }
        }
        return abs(r);
    }
};