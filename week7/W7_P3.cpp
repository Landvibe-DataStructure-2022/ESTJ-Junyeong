#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	Node* parent;
	vector<Node*>child;
	int value;

	Node() {
		parent = nullptr;
		value = 0;
	}

	friend class Tree;
};

class Tree {
public:
	Node* root;
	vector<Node*>nodeList;

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
		Node* p = find(x);

		Node* c = new Node();
		c->value = y;

		c->parent = p;
		p->child.push_back(c);
		nodeList.push_back(c);
	}


	void postOrder(Node* n) {
		Node* p = n;

		for (Node* child : p->child) {
			postOrder(child);
		}

		if (p == root) {
			cout << 0 << " ";
		}
		else {
			cout << p->parent->value << " ";
		}
		
	}
};

int main() {
	int order_num;
	string order;

	cin >> order_num;
	


	for (int i = 0; i < order_num; i++) {
		Tree* t = new Tree();
		int tree_num;
		cin >> tree_num;
		for (int j = 0; j < tree_num; j++) {
			int a, b;
			cin >> a >> b;
			t->insert(a, b);
		}
		t->postOrder(t->root);
		cout << endl;


	}
}