class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (prev->next != nullptr) {
            if (prev->next->val == val) {
                ListNode* node = prev->next;
                prev->next = node->next;
                delete node;
            } else {
                prev = prev->next;
            }
        }

        return dummy.next;
    }
};
