/*
 * @Author: Sugar 45682h@gmail.com
 * @Date: 2022-11-28 11:19:14
 * @Describe: 
 */
#ifndef __LOCK_FREE_QUEUE_H
#define __LOCK_FREE_QUEUE_H

#include <atomic>
namespace xrtc {
// 要求一个生产者一个消费者
// 指针的操作是原子的

template <typename T>
class LockFreeQueue {
  public:
    LockFreeQueue() {
        first = divider = last = new Node(T());
        _size = 0;
    }

    ~LockFreeQueue() {
        while (first != nullptr) {
            Node* tmp = first;
            first = first->next;
            delete tmp;
        }
        _size = 0;
    }

    void produce(const T& t) {
        // 必须是单线程生成，如果多线程生产这里是线程不安全的
        last->next = new Node(t);
        last = last->next;
        ++_size;

        while (divider != first) {
            // 说明队头已经被消费了
            Node* temp = first;
            first = first->next;
            delete temp;
        }
    }

    bool consume(T* result) {
        if (divider != last) {
            *result = divider->next->value;
            divider = divider->next;
            --_size;
            return true;   
        }
        return false;
    }

    bool empty() {
        return _size == 0;
    }

    int size() {
        return _size;
    }

  private:
    struct Node {
        T value;
        Node* next;

        Node(const T& value) : value(value), next(nullptr) {}
    };

    Node* first;
    Node* divider; // 分割指针
    Node* last;
    std::atomic<int> _size;
};
} // namespace xrtc

#endif