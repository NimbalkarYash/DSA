class Solution {
public:
    int findNthDigit(int n) {
        long long start = 1;
        long long length = 1;
        long long count = 9;

        while(n > length*count)
        {
            n -= length*count;
            length++;
            start*=10;
            count*=10;
        } 

        long long targetNumber = start+(n-1)/length;

        string target = to_string(targetNumber);
        return target[(n - 1) % length] - '0';
    }
};