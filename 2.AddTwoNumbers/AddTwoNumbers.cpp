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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = NULL;
        int carry = 0;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *temp = ans;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val + temp2->val + carry < 10)
            {
                if (ans == NULL)
                {
                    ListNode *node = new ListNode(temp1->val + temp2->val + carry);
                    ans = node;
                    temp = ans;
                }
                else
                {
                    ListNode *node = new ListNode(temp1->val + temp2->val + carry);
                    temp->next = node;
                    temp = node;
                }
                carry = 0;
            }
            else
            {
                if (ans == NULL)
                {
                    ListNode *node = new ListNode((temp1->val + temp2->val + carry) % 10);
                    ans = node;
                    temp = ans;
                }
                else
                {
                    ListNode *node = new ListNode((temp1->val + temp2->val + carry) % 10);
                    temp->next = node;
                    temp = node;
                }
                carry = 1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while (temp1 != NULL)
        {
            if (temp1->val + carry < 10)
            {
                ListNode *node = new ListNode(temp1->val + carry);
                temp->next = node;
                temp = node;
                carry = 0;
            }
            else
            {
                ListNode *node = new ListNode((temp1->val + carry) % 10);
                temp->next = node;
                temp = node;
                carry = 1;
            }
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            if (temp2->val + carry < 10)
            {
                ListNode *node = new ListNode(temp2->val + carry);
                temp->next = node;
                temp = node;
                carry = 0;
            }
            else
            {
                ListNode *node = new ListNode((temp2->val + carry) % 10);
                temp->next = node;
                temp = node;
                carry = 1;
            }
            temp2 = temp2->next;
        }
        if (carry)
        {
            ListNode *node = new ListNode(carry);
            temp->next = node;
            temp = node;
            carry = 0;
        }
        return ans;
    }
};