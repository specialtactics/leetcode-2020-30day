/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *middle = head;
    int count = 0;
    
    while (head != NULL) {
        ++count;
        
        if (count % 2 == 0) {
            middle = middle->next;
        }
        
        head = head->next;
    }
    
    return middle;
}
 
