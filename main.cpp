#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue {
private:
    template<typename T2>
    struct Node {
        public:
        T2 data;
        Node *next;
        Node(T2 data) {
            this->data = data;
            this->next = nullptr;
        }
    };

private:
    Node<T> *front, *rear;
    size_t size;

public:
    void enqueue(T data);
    T dequeue();
    bool isEmpty();
    size_t getSize();
    void display();

public:
    Queue() {
        this->front = nullptr;
        this->rear = nullptr;
        this->size = 0;
    }
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

template<typename T>
size_t Queue<T>::getSize() {
    return size;
}

template<typename T>
bool Queue<T>::isEmpty () {
    return front == nullptr;
}

template<typename T>
void Queue<T>::enqueue(T data) {
    Node<T> *newNode = new Node(data);
    if (isEmpty()) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

template<typename T>
T Queue<T>::dequeue() {

    if (front == nullptr) {
        rear = nullptr;
    }

    auto *temp = front;
    auto value = front->data;
    front = front->next;
    delete temp;

    size--;

    return value;
}

template<typename T>
void Queue<T>::display() {
    if (isEmpty()) {
        throw out_of_range("Queue is empty");
    }
    Node<T> *curr = front;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }

}


int main() {
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.getSize() << endl;

    q.display();

    return 0;
}