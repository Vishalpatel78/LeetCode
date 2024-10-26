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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL)return NULL;
        int length = 1;
        ListNode* temp = head;
        while(temp -> next != NULL){
            length++;
            temp = temp -> next;
        }
        int half = length / 2;
        int i = 1;
        while(i<half + 1){
            head = head -> next;
            i++;
        }
        return head;
        
    }
};