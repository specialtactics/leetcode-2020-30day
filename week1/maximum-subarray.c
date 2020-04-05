int maxSubArray(int* nums, int numsSize){
    int current, highest, addingSet;
    highest = addingSet = nums[0];
    
    for (int i = 1; i < numsSize; ++i) {
        current = nums[i];
        
        // No point adding to the subarray, if the next number is already bigger than the current subarray going
        if (current > current + addingSet) {
            addingSet = current;
        } else {
            addingSet += current;
        }

        if (addingSet > highest) {
            highest = addingSet;
        }
    }
    
    return highest;
} 
