#include <iostream>
#include<string>
using namespace std;

int order_num = 0;
int arr_size = 0;

class arr {
private:
	int* array;
	int size = 0;



public:
	arr() {array = new int[10];}

	int empty() {

		if (size == 0) {
			return  1;
		}
		else {
			return 0;
		}


	}

	int top() {
		if (empty()==1){
			return  -1;
		}
		else {
			return array[size-1];

		}

	}

	void push(int x) {
		if (size == arr_size) {
			cout << "FULL" << endl;
		}
		else {
			array[size] = x;
			size++;
		}
		
	}

	int pop() {

		if (empty() == 1) {
			return -1;
		}
		else {
			return array[size-1];
			size--;
		}

	}

};



int main() {
	

	cin >> arr_size >> order_num;

	arr Array;

	while (--order_num) {

		string order;
		cin >> order;

		if (order == "empty") {
			cout << Array.empty() << "\n";
		}
		else if (order == "top") {
			cout << Array.top() << "\n";
		}
		else if (order == "push") {
			int input;
			cin >> input;
			Array.push(input);
		}
		else if (order == "pop") {
			cout << Array.pop() << "\n";
		}
	}

}