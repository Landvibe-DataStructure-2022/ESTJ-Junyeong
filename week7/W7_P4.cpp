#include<iostream>
#include<vector>
using namespace std;

vector<int>nodeValue;
vector<int>nodeDepth;

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
	

	Tree() {
		root = nullptr;

	}

	void makeTree() {
		int depth = -1;
		Node* curNode = root;

		for (int i = nodeDepth.size() - 1; i >= 0; i--) {


			if (nodeDepth[i] == 0) {
				root = new Node();
				root->value = nodeValue[i];
				depth = nodeDepth[i];
				curNode = root;
			}


			else {
			
				if (depth < nodeDepth[i]) {
					Node* newNode = new Node();
					newNode->value = nodeValue[i];
					newNode->parent = curNode;

					curNode->child.push_back(newNode);
					curNode = newNode;
				}
				else if (depth == nodeDepth[i]) {
					Node* newNode = new Node();
					newNode->value = nodeValue[i];
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
					newNode->value = nodeValue[i];
					newNode->parent = curNode->parent;
					curNode->parent->child.push_back(newNode);
					curNode = newNode;

				}
				depth = nodeDepth[i];
			}
		}
	}
	void preOrder(Node* n) {
		Node* p = n;

		cout << p->value << " ";

		for (int i = p->child.size() - 1; i >= 0;i--) {
			preOrder(p->child[i]);
		}
	}
};

int main() {
	int order, size;

	cin >> order;
	
	for (int i = -0; i < order; i++) {
		Tree* t = new Tree();

		nodeValue.clear();
		nodeDepth.clear();

		cin >> size;

		for (int i = 0; i < size; i++) {
			int a;
			cin >> a;
			nodeValue.push_back(a);
		}

		for (int i = 0; i < size; i++) {
			int a;
			cin >> a;
			nodeDepth.push_back(a);
		}

		t->makeTree();
		t->preOrder(t->root);
		cout << endl;



	}
	
}