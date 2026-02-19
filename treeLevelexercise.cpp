#include <string>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

class Tree {
 private:
    class Node {
    public:
    string value;
    Node* pLeft;
    Node* pRight;
    Node(string data) {
        value = data;
        pLeft = nullptr;
        pRight = nullptr;
    }
    };

    Node* root = nullptr;
 public:
    bool add(string data) {
        if(root == nullptr) {
            root = new Node(data);
            return true;
        }
        else {
            Node* it = root;
            while(true) {
                if(data < it->value) {
                    if(it->pLeft == nullptr) {
                        it->pLeft = new Node(data);
                        return true;
                    }
                    it = it->pLeft;
                    continue;
                }
                else if(data > it->value) {
                    if(it->pRight == nullptr) {
                        it->pRight = new Node(data);
                        return true;
                    }
                    it = it->pRight;
                    continue;
                }
                else {
                    return false;
                }
            }
        }
    }

    void printLevels() {

        if(root != nullptr) {
            queue<pair<Node*, int>> q;
            pair<Node*, int> myPair(root, 0);
            q.push(myPair);
            pair<Node*, int> temp;

            while(q.empty() == false) {
                temp = q.front();
                q.pop();
                cout << temp.first->value << " " << temp.second << endl;
                if(temp.first->pLeft != nullptr) {
                    pair<Node*, int> newPair(temp.first->pLeft, temp.second + 1);
                    q.push(newPair);
                }
                if(temp.first->pRight != nullptr) {
                    pair<Node*, int> newPair(temp.first->pRight, temp.second + 1);
                    q.push(newPair);
                }
            }
        }

    }


};

int main() {
    Tree tree;
    tree.add("D");
    tree.add("B");
    tree.add("C");
    tree.add("A");
    tree.add("F");
    tree.add("E");
    tree.add("H");
    tree.add("Q");
    tree.add("Z");
    tree.add("G");
    tree.printLevels();
}