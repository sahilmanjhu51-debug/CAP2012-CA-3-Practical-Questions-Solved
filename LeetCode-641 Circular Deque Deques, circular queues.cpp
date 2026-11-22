class MyCircularDeque {
public:
    vector<int> arr;
    int k, front, size;

    MyCircularDeque(int k) {
        arr.resize(k);
        this->k = k;
        front = 0;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        front = (front - 1 + k) % k;
        arr[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        int rear = (front + size) % k;
        arr[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        front = (front + 1) % k;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[(front + size - 1) % k];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == k;
    }
};
