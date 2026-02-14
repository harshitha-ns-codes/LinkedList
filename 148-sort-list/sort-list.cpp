class Solution {
public:

    // Step 1: Find Middle
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;   // important change

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Step 2: Merge Two Sorted Lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        if(l1) temp->next = l1;
        if(l2) temp->next = l2;

        return dummy->next;
    }

    // Step 3: Merge Sort
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* middle = findMiddle(head);
        ListNode* rightHead = middle->next;
        middle->next = NULL;   // break the list

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return merge(left, right);
    }
};
