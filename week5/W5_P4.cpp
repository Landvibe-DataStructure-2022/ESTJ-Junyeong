#include <iostream>
#include <string>

using namespace std;

int MAX(int a, int b, int c) {
    int tmp = (a > b ? a : b);
    return (tmp > c ? tmp : c);
}

int MIN(int a, int b, int c) {
    if (a == 0) {
        a = 101;
    }
    if (c == 0) {
        c = 101;
    }
    int tmp = (a < b ? a : b);
    return (tmp < c ? tmp : c);
}

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node() {
        data = 0;
        prev = NULL;
        next = NULL;
    }
};

struct Iterator {
    Node* node;

    Iterator(Node* node) {
        this->node = node;
    }

    Iterator* operator++() {
        node = node->next;
        return this;
    };

    Iterator* operator--() {
        node = node->prev;
        return this;
    };
};

class Sequence {
private:
    int size;
    Node* head;
    Node* tail;
public:
    Sequence() {
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    Node* begin() {
        return head->next;
    }

    Node* end() {
        return tail;
    }

    void insert(Iterator& p, int data) {
        Node* newNode = new Node();
        newNode->data = data;

        p.node->prev->next = newNode;
        newNode->prev = p.node->prev;

        p.node->prev = newNode;
        newNode->next = p.node;

        size++;
    }

    void erase(Iterator& p) {

        if (empty()) {
            cout << "Empty" << endl;
            return;
        }
        if (p.node == end())
            return;

        p.node->prev->next = p.node->next;
        p.node->next->prev = p.node->prev;

        delete p.node;
        size--;

        p.node = begin();
    }

    void print() {
        if (empty()) {
            cout << "Empty" << endl;
            return;
        }
        Node* cur = begin();
        for (int i = 0; i < size; i++) {
            cout << cur->data << ' ';
            cur = cur->next;
        }
        cout << endl;
    }

    bool empty() {
        return (size == 0);
    }

    void upper(int data) {
        if (empty()) {
            cout << -1 << endl;
            return;
        }
        Node* cur = begin();
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            if (cur->data > data) {
                cout << i << ' ';
                cnt++;
            }
            cur = cur->next;
        }
        if (cnt == 0) {
            cout << -1;
        }
        cout << endl;
    }

    void MAXMIN() {
        Node* cur = begin();
        for (int i = 0; i < size; i++) {
            cout <<
                MAX(cur->prev->data, cur->data, cur->next->data)
                - MIN(cur->prev->data, cur->data, cur->next->data)
                << ' ';
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        Sequence s;
        Iterator p(s.begin());
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int n;
            cin >> n;
            s.insert(p, n);
        }
        s.MAXMIN();
    }
}