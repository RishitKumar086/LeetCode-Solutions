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

class compare
{
public:
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;

        int k = lists.size();

        if (k == 0)
            return NULL;

        for (int i = 0; i < k; i++)
        {
            if (lists[i] != NULL)
            {
                minHeap.push(lists[i]);
            }
        }

        ListNode *head = NULL;
        ListNode *tail = NULL;

        while (minHeap.size() > 0)
        {
            ListNode *temp = minHeap.top();
            minHeap.pop();

            // here we push only one element of the minimum list present at the
            // top of the minheap and if it is not the last element of the list
            // we push the remaining list back to the minheap so the minheap
            // will rearrange itself and the list with the first minimum element
            // comes to the top again
            if (head == NULL)
            {
                head = temp;
                tail = temp;
                if (tail->next != NULL)
                {
                    minHeap.push(tail->next);
                }
            }
            else
            {
                tail->next = temp;
                tail = temp;
                if (tail->next != NULL)
                {
                    minHeap.push(tail->next);
                }
            }
        }
        return head;
    }
};