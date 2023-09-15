// 1->2
// 2->3->3
// ans: 3->5->3


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    private:
    void insertAtTail(ListNode* &head, ListNode* &tail, int val) {
        
        ListNode* temp = new ListNode(val);
        //empty list
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }

    ListNode* add(ListNode* first, ListNode* second){
        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;


        while(first != NULL && second != NULL){
            int sum = carry+first->val + second->val;
            int digit = sum%10;

            insertAtTail(ansHead, ansTail, digit);

            carry = sum/10;

            first = first->next;
            second = second->next;
        }

        while(first != NULL){
            int sum = first->val + carry;
            int digit = sum%10;

            insertAtTail(ansHead, ansTail, digit);

            carry = sum/10;
            first = first->next;
        }

        while(second != NULL){
            int sum = second->val + carry;
            int digit = sum%10;

            insertAtTail(ansHead, ansTail, digit);

            carry = sum/10;
            second = second->next;
        }

        while(carry != 0){
            int sum = carry;
            int digit = sum%10;

            insertAtTail(ansHead, ansTail, digit);

            carry = sum/10;
        }
        return ansHead;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = add(l1,l2);

        return ans;
    }
};