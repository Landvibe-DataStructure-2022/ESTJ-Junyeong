#include<iostream>
#include<string>

using namespace std;

class node {
public:
	node* next;
	int elem;

	friend class queue;
};

class queue {
private:
	node* head;
	node* tail;
	int qSize;
public:
	queue() { head = NULL; tail = NULL; qSize = 0; };


	void enqueue(int value) {
		node* newNode = new node;
		newNode->elem = value;

		if (isEmpty()) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		qSize++;
	}

	void dequeue() {
		node* temp = head;

		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << temp->elem << endl;

			if (qSize == 1) {
				head = tail = NULL;
			}
			else {
				head = temp->next;
			}

			delete temp;
			qSize--;
		}
	}

	bool isEmpty() {
		if (qSize == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	int size() {
		return qSize;
	}

	void front() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout<< head->elem << endl;
		}
	}

	void rear() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << tail->elem << endl;
		}
	}

};

int main() {
	int order_num;
	string order;
	queue q;
	cin >> order_num;

	for (int i = 0; i < order_num; i++) {
		cin >> order;

		if (order == "enqueue") {
			int a = 0;
			cin >> a;
			q.enqueue(a);
		}
		else if (order == "dequeue") {
			q.dequeue();
		}
		else if (order == "isEmpty") {
			if (q.isEmpty()) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		else if (order == "size") {
			cout << q.size() << endl;
		}
		else if (order == "front") {
			q.front();
		}
		else if (order == "rear") {
			q.rear();
		}



	}

}