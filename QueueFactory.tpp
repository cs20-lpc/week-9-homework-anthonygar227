template <typename T>
Queue<T>* QueueFactory<T>::GetQueue() {
    return new LinkedQueue<T>();
}

template <typename T>
Queue<T>* QueueFactory<T>::GetQueue(int capacity) {
    return new ArrayQueue<T>(capacity);
}