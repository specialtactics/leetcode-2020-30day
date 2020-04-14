char * stringShift(char * s, int** shift, int shiftSize, int* shiftColSize){
    int length = strlen(s);
    char *result = malloc(length + 1);
    int pointer = 0;
    
    // Calculate shiftiness
    while (--shiftSize >= 0) {
        if (shift[shiftSize][0] == 0) {
            pointer += shift[shiftSize][1];
        } else {
            pointer -= shift[shiftSize][1];
        }
    }
    
    // Deal with negative results
    while (pointer < 0) {
        pointer += length;
    }
    
    // Form answer
    for (int i = 0; i < length; ++i) {
        // Normalise pointer that's ran past
        if (pointer > length - 1) {
            pointer = pointer % length;
        }
        
        result[i] = s[pointer++];
        
    }
    result[length] = '\0';
   
    return result;
}
