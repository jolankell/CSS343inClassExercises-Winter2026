#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class PriorityQueue {
 private:
    vector<T>  list;
 public:
    PriorityQueue() {

    }
    PriorityQueue operator=(const PriorityQueue& queue) {
        this->list = queue->list;
        return *this;
    }    
    void enqueue(T value) {
        list.push_back(value);
        for(int i = list.size() - 2; i >= 0; i--) {
            if(value <= list[i]) {
                break;
            }
            T temp = list[i];
            list[i] = value;
            list[i + 1] = temp;
        }
    }
    T dequeue() {
        T toReturn = list[0];
        list.erase(list.begin());
        return toReturn;
    }
    int size() {
        return list.size();
    }
    void print() {
        PriorityQueue<T> copyQ = *this;
        T data;
        cout << "Queue contents: ";
        while(copyQ.size() != 0) {
            data = copyQ.dequeue();
            cout << data << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue<int> maxQ;
    for(int i = 0; i < 10; i++) {
        maxQ.enqueue(i);
    }
    maxQ.print();
}