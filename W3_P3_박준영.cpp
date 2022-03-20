#include<iostream>
#include<string>
using namespace std;

class node {
private:
	node* next;
	int elem;
	friend class linkedList;
};

class linkedList {
private:
	node* head;
	node* tail;
	int size;
public:
	linkedList() { size = 0; head = NULL; tail = NULL; };

	int empty() {
		if (size == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int top() {

		if (size == 0) {
			return -1;
		}

		else {
			return head->elem;
		}
		
	}

	void push(int x) {
		node* temp = new node;
		temp->elem = x;
		temp->next = head;
		head = temp;
		size++;
	}

	int pop() {
		if (size == 0) {
			return -1;
		}
		else {
			node* temp = head;
			head = temp->next;
			size--;
			return temp->elem;
		}

	}



};

int main() {
	int order_num;
	string order;
	cin >> order_num;

	linkedList list;

	for (int i = 0; i < order_num; i++) {
		cin >> order;

		if (order == "empty") {
			cout << list.empty() << endl;
		}
		else if (order == "top") {
			cout << list.top() << endl;
		}
		else if (order == "push") {
			int a = 0;
			cin >> a;
			list.push(a);
		}
		else if (order == "pop") {
			cout << list.pop() << endl;
		}




	}
}