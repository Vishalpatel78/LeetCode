/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findLength(ListNode* head){
        ListNode* temp = head;
        int length = 0;  
        while(temp != NULL){
            length++;
            temp = temp ->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head ->next == NULL){
            return NULL; 
        }

        int length = findLength(head);

        
        if (n == length) {
            return head->next;  
        }

         
        int prev = length - n;
        int prevTrack = 1;
        ListNode* getPrev = head;

        while(prevTrack != prev){
            prevTrack++;
            getPrev = getPrev -> next;
        }

        
        getPrev ->next = getPrev ->next ->next;
        return head;
    }
};
