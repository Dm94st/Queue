#pragma once

#include <iostream>

template<typename T>
struct Node
{
  T m_data;
  Node * m_next;
  Node(const T &data):m_data(data), m_next(nullptr){}
};

template<typename T>
class CustomQueue
{
public:
  CustomQueue():m_head(nullptr), m_tail(nullptr), m_size(0){}

  void Push(const T &valType)
  {
    if(m_head == nullptr) // Queue is not initialize
    {
      m_head = m_tail = new Node<T>(valType);
      m_tail->m_next = nullptr;
      m_size++;
    }
    else
    {
      m_tail->m_next = new Node<T>(valType);
      m_tail = m_tail->m_next;
      m_tail->m_next = nullptr;
      m_size++;
    }
  }

  void Pop()
  {
    if(m_head != nullptr)
    {
      Node<T> * tmpNode = m_head;
      m_head = m_head->m_next;
      delete tmpNode;
      m_size--;
    }
    else
      return;
  }

  void Clear()
  {
    if(!IsEmpty())
    {
      while(m_head != nullptr)
      {
        Node<T> * tmpNode = m_head;
        m_head = m_head->m_next;
        delete tmpNode;
        m_size--;
      }
      m_tail = nullptr;
    }
    else
      return;
  }

  void Print() const
  {
    Node<T> * tmpNode = m_head;
    while(tmpNode != nullptr)
    {
      std::cout<<tmpNode->m_data<<" ";
      tmpNode = tmpNode->m_next;
    }
  }

  void Top() const
  {
    if(m_head != nullptr)
      std::cout << m_head->m_data << std::endl;
    else
      return;
  }

  bool IsEmpty() const
  {
    return m_tail == nullptr;
  }

  int Size() const
  {
    return m_size;
  }

private:
  Node<T> * m_head;
  Node<T> * m_tail;
  int m_size;
}
;
