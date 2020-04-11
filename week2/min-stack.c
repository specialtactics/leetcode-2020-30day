typedef struct {
    int value;
    void *prev;
} El;

typedef struct {
    El *top;
    int min;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate() {
    MinStack* new = malloc(sizeof(MinStack));
    
    new->top = NULL;
    new->min = 0; // If stack has no elements
    
    return new;
}

void minStackPush(MinStack* obj, int x) {
    // Push
    El* new = malloc(sizeof(El));
    new->value = x;
    
    // First element
    if (obj->top == NULL) {
        new->prev = NULL;
        obj->min = x;
    }
    // Other elements
    else {
        new->prev = obj->top;
        
        // Handle min caching
        if (x < obj->min) {
            obj->min = x;
        }
    }
    
    obj->top = new;
}

void minStackPop(MinStack* obj) {
    if (obj->top != NULL) {
        El *toRemove = obj->top;
        obj->top = toRemove->prev;
        
        // Recalculate minimum if needed
        if (toRemove->value == obj->min) {
            recalculateMin(obj);
        }
        
        free(toRemove);
    }
}

int minStackTop(MinStack* obj) {
    return obj->top->value;
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    El *remove, *next = obj->top;
    
    while (next != NULL) {
        remove = next;
        next = next->prev;
        
        free(remove);
    }
    
    free(obj);
}

void recalculateMin(MinStack* obj) {
    El *next = obj->top;
    int min = 0;
    
    if (next != NULL) {
        min = next->value;
        next = next->prev;
        
        while (next != NULL) {
            if (next->value < min) {
                min = next->value;
            }
            next = next->prev;
        }
    }
    
    obj->min = min;
}


/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
