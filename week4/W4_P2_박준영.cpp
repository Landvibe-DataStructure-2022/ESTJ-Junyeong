#include<iostream>

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

	int dequeue() {
		
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {

			if (qSize == 1) {
				head = tail = NULL;
				qSize--;
			}
			else {
				int value = head->elem;
				head = head->next;
				qSize--;
				return value;
			}
	
			
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
};

int main() {

	queue P1;
	queue P2;

	int order_num;

	cin >> order_num;

	for (int i = 0; i < order_num; i++) {
		int p1Hp = 0;
		int p2Hp = 0;
		int winP1 = 0;
		int winP2 = 0;
		

		int card_num;
		cin >> card_num;


		for (int i = 0; i < card_num; i++) {
			int card;
			cin >> card;
			P1.enqueue(card);
		}
		for (int i = 0; i < card_num; i++) {
			int card;
			cin >> card;
			P2.enqueue(card);
		}

		for (int i = 0; i < card_num; i++) {
			int cardP1 = P1.dequeue() + p1Hp;
			int cardP2 = P2.dequeue() + p2Hp;


			if (cardP1 > cardP2) {
				winP1++;
				p1Hp = cardP1 - cardP2;
				p2Hp = 0;
			}
			else if (cardP1 < cardP2) {
				winP2++;
				p2Hp = cardP2 - cardP1;
				p1Hp = 0;
			}
			else {
				p1Hp = p2Hp = 0;
			}

		}

		if (winP1 > winP2) {
			cout << 1 << endl;
		}
		else if (winP1 < winP2) {
			cout << 2 << endl;
		}
		else if (winP1 == winP2) {
			cout << 0 << endl;
		}
	
	}
	

}