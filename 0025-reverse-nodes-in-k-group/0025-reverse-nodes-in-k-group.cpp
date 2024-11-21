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
    ListNode* reverseLinkedList(ListNode* head, ListNode* tail) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current != tail) {
        ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev; // New head after reversing
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* groupPrev = dummy;

    while (true) {
        // Find the kth node from groupPrev
        ListNode* groupEnd = groupPrev;
        for (int i = 0; i < k && groupEnd != nullptr; ++i) {
            groupEnd = groupEnd->next;
        }

        if (groupEnd == nullptr) break; // Not enough nodes for a full group

        // Save the next group's starting node
        ListNode* groupNext = groupEnd->next;

        // Reverse the current group
        ListNode* groupStart = groupPrev->next;
        groupEnd->next = nullptr; // Temporarily disconnect the group
        ListNode* newGroupStart = reverseLinkedList(groupStart, groupEnd->next);

        // Connect the reversed group back to the list
        groupPrev->next = newGroupStart;
        groupStart->next = groupNext;

        // Move to the next group
        groupPrev = groupStart;
    }

    return dummy->next;
}
};