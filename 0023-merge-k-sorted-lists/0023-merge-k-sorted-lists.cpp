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
    struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    // Min-heap to store nodes in sorted order
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

    // Push the head of each list into the min-heap
    for (auto list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    // Dummy node to start the merged list
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;

    while (!minHeap.empty()) {
        // Get the smallest node from the heap
        ListNode* smallest = minHeap.top();
        minHeap.pop();

        // Add the smallest node to the result
        current->next = smallest;
        current = current->next;

        // If there is a next node in the list, push it into the heap
        if (smallest->next) {
            minHeap.push(smallest->next);
        }
    }

    return dummy->next;
}
};