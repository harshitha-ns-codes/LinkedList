class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;

        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return true;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* newHead = reverseList(slow->next);
        slow->next = NULL;

        // Step 3: Compare both halves
        ListNode* first = head;
        ListNode* second = newHead;

        while (second != NULL) {
            if (first->val != second->val) {
                reverseList(newHead); // restore
                return false;
            }
            first = first->next;
            second = second->next;
        }

        // Step 4: Restore list
        reverseList(newHead);
        return true;
    }
};
