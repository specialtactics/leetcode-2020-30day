void moveZeroes(int* nums, int numsSize){
    int zeroCount = 0;
    int upTo = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0) {
            ++zeroCount;
        } else if (i != upTo) {
            nums[upTo++] = nums[i];
        } else {
            ++upTo;
        }
    }
    
    while (zeroCount-- > 0) {
        nums[numsSize - zeroCount - 1] = 0;
    }
}


