//
// Created by User on 20/05/2022.
//

#ifndef EX3_MTM_QUEUE_H
#define EX3_MTM_QUEUE_H

#include "Node.h"

template <class T>
class QueueV1{
public:
    /**
     * C'tor of QueueV1
     */
    QueueV1();

    /**
     * copy C'tor of QueueV1
     */
    QueueV1(const QueueV1&);

    /**
     * D'tor of QueueV1
     */
    ~QueueV1();

    /**
     * Assignment operator of QueueV1
     * @return reference to updated instance of the class
     */
    QueueV1& operator=(const QueueV1& other);

    /**
     * Add new copy of the element to the end of the QueueV1
     * @param element element to be added
     */
    void pushBack(const T& element);

    /**
     * The function return the first element in the non-const queue
     * @return reference to the first element (in the non-const queue)
     */
    T& front();

    /**
     * The function return the first element in the constant queue
     * @return const reference to the first element (in the constant queue)
     */
    const T& front() const;

    /**
     * The function remove the first element in the QueueV1
     */
    void popFront();

    /**
     * The function returns the size of the QueueV1
     * @return the size of the QueueV1
     */
    int size() const;

    class EmptyQueue{};

    /**
     * Iterator for a non - const QueueV1 instance.
     */
    class Iterator;
    /**
     * returns the pointer to the first element in the (non-const) queue
     */
    Iterator begin();
    /**
     * returns the pointer to the last element in the (non-const) queue
     */
    Iterator end();

    /**
     * Iterator for a const instance of QueueV1.
     */
    class ConstIterator;

    /**
     * returns the pointer to the first element in the constant queue
     */
    ConstIterator begin() const;
    /**
     * returns the pointer to the last element in the constant queue
     */
    ConstIterator end() const;
private:
    Node<T> m_firstElement;
    Node<T> m_lastElement;

    /**
    * The function checks if there are no left elements in the queue
    * @return true if the there are no left elements in the queue, otherwise returns false.
    */
    bool isEmpty() const;
};

/**
 * The functions filter create and return a new QueueV1 contains only the elements that correspond to the
 * condition of the given Condition function.
 * @tparam T class of the elements
 * @tparam Condition class of function object or pointer to a function
 * @param queue QueueV1 to be filtered
 * @param condition function object or pointer to a function that recieves element and returns a
 * boolean value
 * @return
 */
 /** The non - const verse of filter function */
template <class Condition, class T>
QueueV1<T>& filter(const QueueV1<T>& queue, Condition condition);

/** The constant verse of filter function */
template <class Condition, class T>
const QueueV1<T>& filter(const QueueV1<T>& queue, Condition condition);

/**
 * The function goes over the elements of a queue and changes them one by one according to a given operation
 * @tparam T class of the elements
 * @tparam Condition class of function object or pointer to a function
 * @param queue QueueV1 to be transformed
 * @param operation function object or pointer to a function that receives an element and changes it
 * @return
 */
template <class Operation, class T>
void transform(QueueV1<T> queue, Operation operation);

template <class T>
class QueueV1<T>::Iterator{
public:
    const T& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);

    bool operator!=(const Iterator& iterator) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;

    class InvalidOperation{};

private:
    const QueueV1<T>* m_queue;
    Node<T>& m_currentNode;
    Iterator(const QueueV1<T>* queue);
    friend class Queue<T>;
};

template <class T>
class QueueV1<T>::ConstIterator{
public:
    const T& operator*() const;
    ConstIterator& operator++();
    ConstIterator operator++(int);

    bool operator!=(const ConstIterator& iterator) const;
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;
    class InvalidOperation{};

private:
    const QueueV1<T>* m_queue;
    const Node<T> currentNode;
    ConstIterator(const QueueV1<T>* queue, int index);
    friend class Queue<T>;
};


template <class T>
QueueV1<T>::QueueV1() : m_firstElement(NULL), m_lastElement(NULL){};

template <class T>
QueueV1<T>::QueueV1(const QueueV1& other) : m_firstElement(other.m_firstElement)
{
    m_lastElement = m_firstElement;
    Node <T> temp = other.m_firstElement;
    if(temp){
        while(temp.getNext()){
            temp = temp.getNext();
            m_lastElement.setNext(Node<T>(temp));
            m_lastElement = m_lastElement.getNext();
        }
    }
}

template <class T>
QueueV1<T>& QueueV1<T>::operator=(const QueueV1& other)
{
    if (this == &other){
        return *this;
    }

    QueueV1<T> copyQueue(other); // prevent losing data in case of error

    while(!isEmpty()){
        Node<T> toDelete = m_firstElement;
        m_firstElement = m_firstElement.getNext();
        delete(toDelete);
    }

    m_firstElement = copyQueue.m_firstElement;
    m_lastElement = copyQueue.m_lastElement;
}


template <class T>
void QueueV1<T>::pushBack(const T& element)
{
    try {
        Node<T> newNode = Node<T>(element);
        if (isEmpty()){
            m_firstElement = newNode;
            m_lastElement = m_firstElement;
        }
        m_lastElement.setNext(newNode);
        m_lastElement = newNode;
    }
    catch(std::bad_alloc& MemoryAllocationError) {
        delete (this);
        throw MemoryAllocationError;
    }
}

template <class T>
T& QueueV1<T>::front()
{
    if (isEmpty()){
        throw QueueV1<T>::EmptyQueue();
    }
    return m_firstElement.getValue();
}

template <class T>
const T& QueueV1<T>::front() const
{
    if (isEmpty()){
        throw QueueV1<T>::EmptyQueue();
    }
    return m_firstElement.getValue();
}

template <class T>
void QueueV1<T>::popFront()
{
    if (isEmpty()){
        throw QueueV1<T>::EmptyQueue();
    }
    Node<T> temp = m_firstElement;
    m_firstElement = m_firstElement.getNext();
    delete(temp);
}

template <class T>
int QueueV1<T>::size() const
{
    int size = 0;
    if (isEmpty()){
        return size;
    }
    Node<T> tempHead = m_firstElement;
    while(tempHead != m_lastElement){
        size++;
        tempHead = tempHead.getNext();
    }
    return ++size;
}

template <class T>
bool QueueV1<T>::isEmpty() const
{
    return (m_firstElement == nullptr);
}

template <class T>
typename QueueV1<T>::Iterator QueueV1<T>::begin()
{
    return Iterartor(this, m_firstElement);
}

template <class T>
typename QueueV1<T>::Iterator QueueV1<T>::end()
{
    return Iterartor(this, m_lastElement);
}

template <class Condition, class T>
QueueV1<T>& filter(QueueV1<T> queue, Condition (*condition)())
{
    QueueV1<T> filteredQueue = QueueV1<T>();
    for (const Node<T>& currentNode : queue){
        if(condition(currentNode.getValue())){
            filteredQueue.pushBack(currentNode);
        }
    }
    return filteredQueue;
}

template <class Operation, class T>
void transform(QueueV1<T> queue, Operation (*operation)())
{
    Node<T> tempNode = queue.m_firstElement;
    while (!tempNode) {
        operation(tempNode.getValue());
        tempNode = tempNode.getNext();
    }
}


template <class T>
QueueV1<T>::Iterator::Iterator(const QueueV1<T>* queue) : m_queue(queue), m_currentNode(queue->m_firstElement)
{}

template <class T>
const T& QueueV1<T>::Iterator::operator*() const
{
    if (!m_currentNode){
        return QueueV1<T>::Iterator::InvalidOperation();
    }
    return *m_currentNode;
}

template <class T>
typename QueueV1<T>::Iterator& QueueV1<T>::Iterator::operator++()
{
    Node<T> nodeBeforePromotion = m_currentNode;
    m_currentNode++;
    return nodeBeforePromotion;
}

template <class T>
typename QueueV1<T>::Iterator QueueV1<T>::Iterator::operator++(int)
{
    Iterator result = *this;
    ++*this;
    return result;
}

template <class T>
bool QueueV1<T>::Iterator::operator!=(const Iterator& otherIterator) const
{
    return ((m_queue == otherIterator.m_queue ) && (m_currentNode!=otherIterator.m_currentNode));
}




template <class T>
QueueV1<T>::ConstIterator::ConstIterator(const QueueV1<T>* queue, int index) : m_queue(queue), m_currentNode(queue->m_firstElement)
{}

template <class T>
const T& QueueV1<T>::ConstIterator::operator*() const {
    if (m_index >= m_queue->size()) {
        return QueueV1<T>::ConstIterator::InvalidOperation();
    }
    Node<T> temp = m_queue->m_firstElement;
    for (int i = 0; i < m_index; i++) {
        temp = temp.getNext();
    }
    return temp.getValue();
}

template <class T>
typename QueueV1<T>::ConstIterator& QueueV1<T>::ConstIterator::operator++(){
    ++m_index;
    return *this;
}

template <class T>
typename QueueV1<T>::ConstIterator QueueV1<T>::ConstIterator::operator++(int){
    Iterator result = *this;
    ++*this;
    return result;
}

template <class T>
bool QueueV1<T>::ConstIterator::operator!=(const ConstIterator& otherConstIterator) const{
    return ((m_queue == otherConstIterator.m_queue ) && (m_index!=otherConstIterator.m_index));
}


#endif //EX3_MTM_QUEUE_H
