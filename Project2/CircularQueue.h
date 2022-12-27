#pragma once

#include <vector>

template <typename T>
class CircularQueue {
private:
    std::vector<T> q_;
    size_t head_;
    size_t tail_;

public:
    CircularQueue(size_t capacity) {
        q_.resize(capacity);
        head_ = 0;
        tail_ = 0;
    }

    void push(const T& item) {
        q_[tail_] = item;
        tail_ = (tail_ + 1) % q_.size();
    }

    void pop() {
        head_ = (head_ + 1) % q_.size();
    }

    T front() {
        return q_[head_];
    }

    T back() {
        return q_[tail_ - 1];
    }

    bool empty() const {
        return head_ == tail_;
    }

    size_t size() const {
        return (tail_ - head_ + q_.size()) % q_.size();
    }
};