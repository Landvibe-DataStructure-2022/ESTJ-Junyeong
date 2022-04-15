#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node {
private:
	Node* parent;
	vector<Node*> child;
	int value;

public:
	Node() {
		parent = nullptr;
		value = 0;
	}

	friend class Tree;
};

class Tree {

public:
	Node* root;
	vector<Node*> nodeList;

	Tree() {
		root = new Node();
		root->value = 1;
		nodeList.push_back(root);
	}


	Node* find(int x) {
		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i]->value == x) {
				return nodeList[i];
			}
		}

		return nullptr;
	}

	void insert(int x, int y) {
		if (x == y) {
			return;
		}

		Node* p = find(x);

		if (p == nullptr) {
			cout << "-1" << endl;
		}

		else {
			Node* c = new Node();
			c->parent = p;

			for (int i = 0; i < nodeList.size(); i++) {
				if (nodeList[i]->value == y) {
					cout << "-1" << endl;
					return;
				}
			}
			c->value = y;
			p->child.push_back(c);
			nodeList.push_back(c);
		}

	}



	void preOrder(Node* n) {
		Node* p = n;

		if (p == root) {
			cout << 0 << " ";
		}
		else {
			cout << p->parent->value << " ";
		}

		for (Node* a : p->child) {
			preOrder(a);
		}

	}


};


int main() {
	int order_num;
	string order;

	cin >> order_num;
	Tree* t = new Tree();


	for (int i = 0; i < order_num; i++) {
		int tree_num;
		cin >> tree_num;
		for (int j = 0; j < tree_num; j++) {
			int a, b;
			cin >> a >> b;
			t->insert(a, b);
		}
		t->preOrder(t->root);



	}
}