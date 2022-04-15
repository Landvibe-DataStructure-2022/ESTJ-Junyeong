#include<iostream>
#include<vector>

using namespace std;

vector<int> nodevalue;
vector<int> nodeDepth;

class Node {
public:
	int value;
	Node* parent;
	vector<Node*>child;

	Node() {
		value = 0;
		parent = nullptr;
	}
	friend class Tree;

};

class Tree {
public:
	Node* root;
	

	Tree() {
		root = new Node();
		root->value = 1;
	}

	void makeTree() {
		int depth = -1;

		Node* curNode = root;

		for (int i = 0; i < nodeDepth.size(); i++) {


			if (nodeDepth[i] == 0) {
				root->value = nodevalue[i];
				depth = 0;
				curNode = root;
			}

			else {
				if (depth < nodeDepth[i]) {

					Node* newNode = new Node();
					newNode->value = nodevalue[i];
					newNode->parent = curNode;

					curNode->child.push_back(newNode);
					curNode = newNode;
				}
				else if (depth == nodeDepth[i]) {

					Node* newNode = new Node();
					newNode->value = nodevalue[i];
					newNode->parent = curNode->parent;

					curNode->parent->child.push_back(newNode);

					curNode = newNode;
				}
				else if (depth > nodeDepth[i]) {

					while (depth != nodeDepth[i]) {

						curNode = curNode->parent;
						depth--;
					}

					Node* newNode = new Node();
					newNode->value = nodevalue[i];
					newNode->parent = curNode->parent;

					newNode->parent->child.push_back(newNode);
					curNode = newNode;
				}

				depth = nodeDepth[i];
			}
		}
	}

	void postOrder(Node* n) {

		Node* p = n;

		for (Node* child : p->child) {
			postOrder(child);
		}

		cout << p->value << " ";

	}


};


int main() {
	int order;
	cin >> order;



	for (int i = 0; i < order; i++) {
		Tree* t = new Tree();

		int num;
		cin >> num;

		nodevalue.clear();
		nodeDepth.clear();

		for (int j = 0; j < num; j++) {
			int a;
			cin >> a;
			nodevalue.push_back(a);
		}

		for (int j = 0; j < num; j++) {
			int a;
			cin >> a;
			nodeDepth.push_back(a);
		}

		t->makeTree();
		t->postOrder(t->root);
		cout << endl;


	}
}