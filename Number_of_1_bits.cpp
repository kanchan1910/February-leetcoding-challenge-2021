class Solution {
public:
    int hammingWeight(uint32_t n)
    {
     return __builtin_popcount(n);   
    }
};
// TC ??
//SC O(1)


// OR

class Solution {
public:
    int hammingWeight(uint32_t n)
    {
    int bits = 0;
    int mask = 1;
    for (int i = 0; i < 32; i++) {
        if ((n & mask) != 0) {
            bits++;
        }
        if(i != 31)
        {
            mask <<= 1;
        }
        
    }
    return bits;
    }
};

// TC O(1)
// SC O(1)
/*
Complexity Analysis

The run time depends on the number of bits in nn. Because nn in this piece of code is a 32-bit integer, the time complexity is O(1)

The space complexity is O(1), since no additional space is allocated.
*/
