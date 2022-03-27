#include<iostream>
#include<string>
using namespace std;


int arrSize;

class queue {
private:
	int arr[10000]{};
	int front;
	int rear;
	int qSize;
public:
	queue() { front = 0; rear = 0; qSize = 0; }

	void update() {
		front %= arrSize;
		rear  %= arrSize;
	}

	int size() {
		return  qSize;
	}

	bool isEmpty() {
		if (qSize == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void enqueue(int value) {
		if (qSize >= arrSize) {
			cout << "Full" << endl;
		}
		else {
			update();
			arr[rear] = value;
			rear++;
			qSize++;
		}
		

	}

	void dequeue() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << arr[front] << endl;
			front++;
			update();
			qSize--;

		}
		
	}

	void frontF() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else{
			cout << arr[front] << endl;
		}
	}

	void rearF() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << arr[rear-1] << endl;
		}
	}


};


int main() {
	int order_num;
	string order;
	cin >> arrSize >> order_num;
	queue q;

	for (int i = 0; i < order_num; i++) {
		cin >> order;
		if (order == "enqueue") {
			int a;
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
			q.frontF();
		}
		else if (order == "rear") {
			q.rearF();
		}
	}
}