class Solution {
public:
    bool equal(double num1, double num2)
    {
        if(num1 - num2 > -0.0000001
        && num1 - num2 < 0.0000001)
            return true;
        else 
            return false;
    }
    double myPow(double x, int n) {
        if(equal(x, 0.0) && n<= 0)
            return 0.0;
        
        unsigned int absN = (unsigned int)(n);
        if(n < 0)
            absN = (unsigned int)(-n);
        
        double result = 1.0;
        double tmp = x;
        while(absN)
        {
            if(absN&1) result *= tmp;
            absN>>=1;
            if(absN)tmp *= tmp;
        }
        
        if(n < 0)
            result = 1.0/result;
        return result;
    }
};