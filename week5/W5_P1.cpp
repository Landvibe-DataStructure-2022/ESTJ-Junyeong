#include<iostream>
using namespace std;


class Node {
private:
	Node* next;
	Node* prev;
	int elem;
public:
	Node() {
		next = NULL;
		prev = NULL;
		elem = 0;
	}

	friend class Iterator;
	friend class Sequence;

};

class Iterator {
public:
	Node* node;
	Iterator(Node* n) {
		node = n;
	}

	Iterator* operator++() {
		
		node = node->next;
		return this;
	}

	Iterator* operator--() {
		
		node = node->prev;
		return this;
	}

	friend class Sequence;

};

class Sequence {
private:
	Node* head;
	Node* tail;
	int size;
public:
	Sequence() {
		head = new Node;
		tail = new Node;

		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	Node* begin() {
		return head->next;
	}


	Node* end() {
		return tail;
	}

	void insert(Iterator& p, int e) {
		if (p.node == NULL) {
			return;
		}
		else {


			Node* newNode = new Node;
			newNode->elem = e;

			p.node->prev->next = newNode;
			newNode->prev = p.node->prev;

			newNode->next = p.node;
			p.node->prev = newNode;

			size++;
		}

	}

	void erase(Iterator& p) {
		if (size == 0) {
			cout << "Empty" << endl;
		}
		else if (p.node == end()){
			return;
		}
		else {
			
			p.node->prev->next = p.node->next;
			p.node->next->prev = p.node->prev;

			delete p.node;

			p.node = begin();
			size--;
			

		}

	}

	void print() {
		if (size == 0) {
			cout << "Empty" << endl;
		}
		else {
			Node* newNode = head->next;

			while (newNode != tail) {
				cout << newNode->elem << " ";
				newNode = newNode->next;
			}
			cout << endl;

		}
	}

	void find(int x) {
	
			Node* newNode = head->next;
			int count = 0;

			for(int i=0;i<size;i++){
				if (newNode->elem == x) {
					cout << i << " ";
					count++;
					newNode = newNode->next;
				}
				else {
					newNode = newNode->next;
				
				}

			}
			if (count == 0) {
				cout << "-1";
			}
			cout << endl;
			
	}
	

};


int main() {
	int order_num;
	string order;
	cin >> order_num;

	Sequence seq = Sequence();
	Iterator p(seq.begin());

	for (int i = 0; i < order_num; i++) {
		cin >> order;

		if (order == "begin") {
			p = seq.begin();
		}
		else if (order == "end") {
			p = seq.end();
		}
		else if (order == "insert") {
			int a;
			cin >> a;
			seq.insert(p, a);
		}
		else if (order == "erase") {
			seq.erase(p);
		}
		else if (order == "nextP") {
			if (p.node != seq.end()) {
				++p;
			}
		}
		else if (order == "prevP") {
			if (p.node != seq.begin()) {
				--p;
			}
		}
		else if (order == "print") {
			seq.print();
		}
		else if (order == "find") {
			int a;
			cin >> a;
			seq.find(a);
		}

	}
}