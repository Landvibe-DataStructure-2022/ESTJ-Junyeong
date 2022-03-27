#include<iostream>
#include<string>
using namespace std;



class queue {
private:
	int arr[10000]{};
	int front;
	int rear;
	int qSize;
public:
	queue() { front = 0; rear = 0; qSize = 0; }

	bool isEmpty() {
		if (qSize == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void enqueue(int value) {

			arr[rear] = value;
			rear++;
			qSize++;

	}

	int dequeue() {
		int a = arr[front];
		front++;
		qSize--;
		return a;
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