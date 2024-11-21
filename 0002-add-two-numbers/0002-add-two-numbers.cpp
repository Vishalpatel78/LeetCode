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
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);  // Dummy node to simplify result handling
        ListNode* current = dummy;          // Pointer to construct the result list
        int carry = 0;                      // Variable to store the carry from previous addition
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;  // Start with the carry from the previous operation
            
            // Add the value of the current node in l1 (if exists)
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;  // Move to the next node in l1
            }
            
            // Add the value of the current node in l2 (if exists)
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;  // Move to the next node in l2
            }
            
            // Update carry and the current digit for the result
            carry = sum / 10;   // Carry will be 1 if sum is 10 or more, otherwise 0
            current->next = new ListNode(sum % 10);  // Create the new node for the result
            current = current->next;  // Move to the next node in the result list
        }
        
        return dummy->next;  // Return the actual head of the result list
    }
};
 