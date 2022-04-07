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



    void find() {
        Node* cur = begin();
    

        int max=0;
        int min=101;


        for (int i = 0; i < size; i++) {

            int num1 = cur->prev->data;
            int num2 = cur->data;
            int num3 = cur->next->data;

            int max = 0;
            int min = 101;

           
            

            if (num1 >= num2 && num1 >= num3) {
                max = num1;
                if (num2 >= num3) {
                    min = num3;
                }
                else {
                    min = num2;
                }
            }
            else if (num2 >= num1 && num2 >= num3) {
                max = num2;
                if (num1 == 0) {
                    num1 = 101;

                }
                if (num3 == 0) {
                    num3 = 101;
                }
                if (num1 >= num3) {
                    min = num3;
                }
                else {
                    min = num1;
                }
            }
            else if (num3 >= num1 && num3 >= num2) {
                max = num3;
                if (num1 == 0) {
                    num1 = 101;

                }
               
                if (num1 >= num2) {
                    min = num2;
                }
                else {
                    min = num1;
                }
            }
            cur = cur->next;
            cout << max - min << " ";
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
        s.find();
    }
}