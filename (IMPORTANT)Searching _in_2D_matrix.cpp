
// important problem (all ways covered)

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

// 1

class Solution {
public:
    // linear searching 
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(matrix[i][j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// tc o(n * m)
// sc o(1)
// TLE


// 2 (take all matrix elements in the temporary array and then do bianry search on it , but it will not work here because , we have given that each row is sorted and each column is sorted but not that the next row starting element will be always greater than the previous row last element , so it will not work here as temporary array will not be sorted)

// 3
class Solution {
public:
    // binary search
    bool binary_search(vector<int>&arr,int target)
    {
        int len = arr.size();
        int l = 0;
        int r = len - 1;
        while(l <= r)
        {
            int mid = (l + (r - l) / 2);
            if(arr[mid] == target)
            {
                return true;
            }
            if(arr[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int row = 0 ; row < n ; row++)
        {
            if(binary_search(matrix[row] , target) == true)
            {
                return true;
            }
        }
        return false;
    }
};

// tc o(n * log(m))
// sc o(1)

(best method)
// 4
class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = m - 1;
        while(i < n && j >= 0)
        {
            if(matrix[i][j] == target)
            {
                return true;
            }
            if(matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};

// tc o(n + m)
// sc o(1)


Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


class Solution {
public:
    // linear searching 
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(matrix[i][j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// tc o(n * m)
// sc o(1)
// ACCEPTED

// 2 here it will work as given that first element of row eill be graeter than the last element of the previous row , and each row is sorted , so tmp array will be sorted

class Solution {
public:
        // binary search

    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>tmp;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ;j++)
            {
                tmp.push_back(matrix[i][j]);  // tmp will be sorted
            }
        }
        int len = tmp.size();
        int l = 0;
        int r = len - 1;
        while(l <= r)
        {
            int mid = (l + (r - l) / 2);
            if(tmp[mid] == target)
            {
                return true;
            }
            if(tmp[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return false;
    }
};

// tc o(log(n * m))
// sc o(n * m)

// 3
class Solution {
public:
    // binary search
    bool binary_search(vector<int>&arr,int target)
    {
        int len = arr.size();
        int l = 0;
        int r = len - 1;
        while(l <= r)
        {
            int mid = (l + (r - l) / 2);
            if(arr[mid] == target)
            {
                return true;
            }
            if(arr[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int row = 0 ; row < n ; row++)
        {
            if(binary_search(matrix[row] , target) == true)
            {
                return true;
            }
        }
        return false;
    }
};

// tc (n * log(m))
// sc (1)

// 4
class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = m - 1;
        while(i < n && j >= 0)
        {
            if(matrix[i][j] == target)
            {
                return true;
            }
            if(matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};

// tc o(n + m)
// sc o(1)


(best method)
// 5 same as approach 2 , just for removing space complexity

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r)
        {
            int mid = (l + (r - l) / 2);
            if(matrix[mid / m][mid % m] == target)
            {
                return true;
            }
            if(matrix[mid / m][mid % m] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return false;
    }
};

// tc o(log(m * n))
// sc o(1)

