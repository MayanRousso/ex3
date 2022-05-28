//
// Created by User on 21/05/2022.
//

#ifndef EX3_MTM_NODE_H
#define EX3_MTM_NODE_H

#include <stdio.h>
#include <new>   // std::bad_alloc


template <class T>
class Node{
public:
    /**
     * C'tor of Node
     * @param value of the element
     */
    Node(T value);

    /**
     * Copy C'tor of Node
     * @param value of the element
     */
    Node(const Node& other);

    /**
     * D'tor of Node
     */
    ~Node();

    /**
     *
     */
    Node<T>& operator=(const Node<T>& other) = default;

    /**
     * The operator return the next Node in the list
     * @return the next element in the list
     */
    Node<T> operator++() const;

    /**
     * The operator return the value of the Node
     * @return the Node's value
     */
    const T& operator*() const;

    /**
     * The function adds a new node to the end of the list
     * @param nextNode node to add to the end of the list
     */
    void setNext(Node nextNode);


private:
    T m_value;
    Node *m_next;
};

template <class T>
Node<T>::Node(T value): m_value(value), m_next(NULL){};

//Todo: implemet destructor in QueueV1
template <class T>
Node<T>::~Node()
{
    ~m_value;
}

template <class T>
Node<T> Node<T>::operator++() const
{
    return m_next;
}

template <class T>
const T& Node<T>::operator*() const
{
    return *m_value;
}

template <class T>
void Node<T>::setNext(Node<T> nextNode)
{
    m_next = nextNode;
}

template <class T>
Node<T>::Node(const Node& other)
{
        Node newNode = Node(T(other.m_value));
        if (newNode){
            newNode.setNext(other.m_next);
        }
//    catch (std::bad_alloc& MemoryAllocationError){
//        throw MemoryAllocationError;
//    }
}

#endif //EX3_MTM_NODE_H
