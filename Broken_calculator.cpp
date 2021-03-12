class Solution {
public:
    int brokenCalc(int X, int Y) 
    {
        if(X == Y)
        {
            return 0;
        }
        if(Y < X)
        {
            return (X - Y);
        }
        // means y > X
        if(Y % 2 != 0)
        {  // Y + 1, operation is same as doing X - 1
            return 1 + brokenCalc(X , Y + 1);
        }
        else
        {  // Y / 2 operation is same as doing X * 2
            return 1 + brokenCalc(X, Y / 2);
        }
    }
};
