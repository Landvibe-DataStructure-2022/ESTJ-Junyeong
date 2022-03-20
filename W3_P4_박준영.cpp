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

	void push(int x) {
		node* temp = new node;
		temp->elem = x;
		temp->next = head;
		head = temp;
		size++;
	}

	int pop() {
		node* temp = head;
		head = temp->next;
		size--;
		return temp->elem;
	}

};

int main() {
	int order_num;
	cin >> order_num;

	while (order_num--) {
		string order;
		cin >> order;
		linkedList st;


		for (int i = 0; i < order.length(); i++) {

			if (9 >= order[i] - '0' && 0 <= order[i] - '0') {
				st.push(order[i] - '0');
			}
			else {
				int a = st.pop();
				int b = st.pop();

				if (order[i] == '+') {
					st.push(a + b);
				}
				else if (order[i] == '-') {
					st.push(b - a);
				}
				else if (order[i] == '*') {
					st.push(a * b);
				}
			}

		}

		cout << st.pop() << endl;

	}

}