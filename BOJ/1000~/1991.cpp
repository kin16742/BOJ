#include <iostream>
using namespace std;

int t;
struct node {
	node* left;
	node* right;
	char ch, leftCh, rightCh;
};
node nodes[100];


void traversal_1(node n) {
	cout << n.ch;
	if (n.left != NULL) traversal_1(*n.left);
	if (n.right != NULL) traversal_1(*n.right);
}

void traversal_2(node n) {
	if (n.left != NULL) traversal_2(*n.left);
	cout << n.ch;
	if (n.right != NULL) traversal_2(*n.right);
}

void traversal_3(node n) {
	if (n.left != NULL) traversal_3(*n.left);
	if (n.right != NULL) traversal_3(*n.right);
	cout << n.ch;
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		char c, le, ri;
		cin >> c >> le >> ri;
		nodes[i].ch = c;
		nodes[i].leftCh = le;
		nodes[i].rightCh = ri;
	}
	for (int i = 0; i < t; i++) {
		if (nodes[i].leftCh != '.') {
			for (int j = 0; j < t; j++) {
				if (nodes[j].ch == nodes[i].leftCh) {
					nodes[i].left = &nodes[j];
					break;
				}
			}
		}
		if (nodes[i].rightCh != '.'){
			for (int j = 0; j < t; j++) {
				if (nodes[j].ch == nodes[i].rightCh) {
					nodes[i].right = &nodes[j];
					break;
				}
			}
		}
	}
	traversal_1(nodes[0]);
	cout << endl;
	traversal_2(nodes[0]);
	cout << endl;
	traversal_3(nodes[0]);
	cout << endl;
}