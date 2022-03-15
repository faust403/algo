#ifndef __CPP_REAL_HPP__
#define __CPP_REAL_HPP__

#include <memory>
#include <stdexcept>
#include <iostream>

template <typename typeList>
class listNode
{
    typeList field;
    std::unique_ptr<listNode<typeList>> next = nullptr;

 public:
    void setField(const typeList & arg);
    typeList getField(void);
    void setNext(const std::unique_ptr<listNode<typeList>> & newNext);
    std::unique_ptr<listNode<typeList>> getNext(void);
};

template <typename typeList>
void listNode<typeList>::setField(const typeList & arg)
{
    field = arg;
    return;
}
template <typename typeList>
typeList listNode<typeList>::getField(void)
{return field;}

template <typename typeList>
void listNode<typeList>::setNext(const std::unique_ptr<listNode<typeList>> & newNext)
{
    next = std::move(newNext);
    return;
}
template <typename typeList>
std::unique_ptr<listNode<typeList>> listNode<typeList>::getNext(void)
{return next;}

template<typename typeList>
class list
{
    std::unique_ptr<listNode<typeList>> head = nullptr;
 public:
    void push(const typeList & arg);
    typeList getHead();
    friend std::ostream & operator<<(std::ostream & os, const typeList & arg);
    typeList operator*(const listNode<typeList> & node);
    bool is_empty();
    std::unique_ptr<listNode<typeList>> getHeadReference(void);
};

template<typename typeList>
typeList list<typeList>::operator*(const listNode<typeList> & node)
{return node.getField();}

template<typename typeList>
bool list<typeList>::is_empty()
{
    if(head == nullptr)
        return true;
    else
        return false;
}

template<typename typeList>
typeList list<typeList>::getHead(void)
{
    if(is_empty())
        throw
            std::runtime_error("List is empty");
    return *head;
}

template<typename typeList>
std::unique_ptr<listNode<typeList>> list<typeList>::getHeadReference(void)
{return *this;}

template <typename typeList>
void list<typeList>::push(const typeList & arg)
{
    listNode<typeList> currentNode;
    currentNode.setField(arg);

    if(head == nullptr)
    {
        head = std::make_unique<listNode<typeList>>(currentNode);
        return;
    }
    else
    {
        currentNode.setNext(head);
        head = std::make_unique<listNode<typeList>>(currentNode);
    }
    return;
}

template<typename typeList>
std::ostream & operator<<(std::ostream & os, const list<typeList> & list)
{
    std::unique_ptr<listNode<typeList>> currentNode = list.getHeadReference();

    while(currentNode != nullptr)
    {
        os << (*currentNode).getField() << ' ';
        currentNode = (*currentNode).getNext();
    }
    return os;
}
#endif