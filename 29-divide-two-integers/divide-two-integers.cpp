class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a=dividend;
        long long b=divisor;

        if(a == INT_MIN && b == -1)
		return INT_MAX;
  
    // The sign will be negative only if sign of 
    // divisor and dividend are different
    int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;

    // remove sign of operands
    a = abs(a);
    b = abs(b);

    // Initialize the quotient
    long long quotient = 0;

    // Iterate from most significant bit to 
    // least significant bit
    for (int i = 31; i >= 0; --i) {

        // Check if (divisor << i) <= dividend
        if ((b << i) <= a) {
            a -= (b << i);
            quotient |= (1LL << i);
        }
    }
    
return sign *quotient;
    }
};