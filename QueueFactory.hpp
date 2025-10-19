#ifndef QUEUE_FACTORY_HPP
#define QUEUE_FACTORY_HPP

#include "LinkedQueue.hpp"
#include "ArrayQueue.hpp"

template <typename T>
class QueueFactory {
    public:
    Queue<T>* GetQueue();
    Queue<T>* GetQueue(int capacity);
};

#include "QueueFactory.tpp"
#endif