class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int l = 0;
        int r = x/2;
        long long sum;
        long long m;
        while(l<= r)
        {
            m = l + (r-l)/2;
            sum = m*m;
            if(sum == x) return m;

            else if(sum>x) r = m-1;

            else l = m+1;
        }

        return r;
    }
};