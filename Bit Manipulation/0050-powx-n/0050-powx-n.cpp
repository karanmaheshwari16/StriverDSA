class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;

        if(n<1) 
            return 1/(x * myPow(x, -(n+1)));

        if(n&1) 
            return x * myPow(x * x, n/2);
        else return myPow(x * x, n/2);
    }
};