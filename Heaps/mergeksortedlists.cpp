class Compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    void insertAtTail(ListNode* node, ListNode*& head, ListNode*& tail) {
        if (!head) {
            head = node;
            tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        int k = lists.size();

        for (int i = 0; i < k; i++) {
            if (lists[i])
                pq.push(lists[i]);
        }

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (pq.size() > 0) {
            ListNode* node = pq.top();
            pq.pop();
            if (node->next)
                pq.push(node->next);
            insertAtTail(node, head, tail);
        }

        return head;
    }
};
