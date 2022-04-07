#include <iostream>
#include <string>

using namespace std;

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
};

int main() {
    int tc;
    string query;
    cin >> tc;
    Sequence s;
    Iterator p(s.begin());

    while (tc--) {
        cin >> query;
        if (query == "begin") {
            p.node = s.begin();
        }
        else if (query == "end") {
            p.node = s.end();
        }
        else if (query == "insert") {
            int n;
            cin >> n;
            s.insert(p, n);
        }
        else if (query == "erase") {
            s.erase(p);
        }
        else if (query == "nextP") {
            if (p.node != s.end())
                ++p;
        }
        else if (query == "prevP") {
            if (p.node != s.begin())
                --p;
        }
        else if (query == "print") {
            s.print();
        }
        else if (query == "upper") {
            int n;
            cin >> n;
            s.upper(n);
        }
    }

}