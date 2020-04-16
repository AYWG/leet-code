/*

Approach: constant space: using input and output vectors to form left and right product lists


*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> output(size, 0);

        for (int i = size - 1; i > 0; i--) {
            if (i == size - 1) {
                output[i] = nums[i];
            } else {
                output[i] = nums[i] * output[i + 1];
            }
        }

        for (int i = 0; i < size; i++) {
            if (i == 0) {
                output[i] = output[i + 1];
            }
            else if (i == size - 1) {
                output[i] = nums[i - 1];
            }
            else {
                output[i] = output[i + 1] * nums[i - 1];

                nums[i] *= nums[i - 1];
            }
        }

        return output;

    }
};


/*


Approach: two linked lists (singly-linked)
    - tail represents product of list up to that point (from head)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        forward_list<int> rightList;
        forward_list<int> leftList;
        int size = nums.size();
        vector<int> output(size, 0);

        for (int i = size - 1; i > 0; i--) {
            if (i == size - 1) {
                rightList.push_front(nums[i]);
            } else {
                rightList.push_front(nums[i] * rightList.front());
            }
        }

        for (int i = 0; i < size; i++) {
            if (i == 0) {
                output[i] = rightList.front();
                rightList.pop_front();
                leftList.push_front(nums[i]);
            }
            else if (i == size - 1) {
                output[i] = leftList.front();
            }
            else {
                output[i] = rightList.front() * leftList.front();
                rightList.pop_front();
                leftList.push_front(nums[i] * leftList.front());
            }
        }

        return output;

    }
};

*/

/*

First attempt (time limit exceeded)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        
        vector<vector<int>> table(size, vector<int>(size, INT_MAX));
        
        vector<int> output(size, 0);
        
        for (int i = 0; i < size; i++) {
            int prefixStart = 0;
            int prefixEnd = i - 1;
            
            int suffixStart = i + 1;
            int suffixEnd = size - 1;
            output[i] = getProductForSubarray(nums, table, prefixStart, prefixEnd) * getProductForSubarray(nums, table, suffixStart, suffixEnd);
        }
        
        return output;
    }
    
    int getProductForSubarray(vector<int>& nums, vector<vector<int>>& table, int start, int end) {
        if (end < start || start > end) {
            // empty subarray
            return 1;
        }
        
        if (end == start) {
            return nums[start];
        }
        
        if (table[start][end] != INT_MAX) {
            return table[start][end];
        }
        
        int mid = start + (end - start) / 2;
        int result = getProductForSubarray(nums, table, start, mid) * getProductForSubarray(nums, table, mid + 1, end);
        table[start][end] = result;
        
        return result;
        
    }
};

*/