/*
Trick: use given array as a hash table (works bc values are in range of 1-n)

[4,3,2,7,8,2,3,1]
size = 8

- Each element corresponds to a bucket in the array
- Iterating through the array, when we see a particular element, we increment the corresponding
bucket by length of the array
- if after doing this we find that an element is now > 2*array_len, then that original element has 2 copies

*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            nums[ (nums[i] - 1) % size] = nums[ (nums[i] - 1) % size] + size;
        }
        
        for (int i = 0; i < size; i++) {
            if (nums[i] > 2 * size) {
                answer.push_back(i + 1);
            }
        }
        
        return answer;
    }
};