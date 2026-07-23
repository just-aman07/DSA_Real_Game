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
class Solution
{
public:
    ListNode* gpt(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* amn=head;

        while(amn)
        {
            ListNode* next=amn->next;
            amn->next=prev;
            prev=amn;
            amn=next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
            return true;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* two=gpt(slow->next);

        ListNode* first=head;
        ListNode* temp=two;

        while(temp)
        {
            if(first->val!=temp->val)
            {
                gpt(two); 
                return false;
            }

            first=first->next;
            temp=temp->next;
        }

        gpt(two); 

        return true;
    }
};