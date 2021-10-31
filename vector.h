#ifndef MYSTL_VECTOR_H
#define MYSTL_VECTOR_H

#include <stddef.h>

namespace MySTD {
    template<typename T>
    class vector {
    public:
        vector() {
            capacity_ = 1;
            size_ = 0;
            begin_ = new T[capacity_];
        }

        vector(size_t size, T value) {
            capacity_ = size;
            size_ = size;
            begin_ = new T[capacity_];
            auto end = begin_ + size_;
            for (auto it = begin_; it != end; ++it) {
                *it = value;
            }
        }

        void push_back(T value) {
            if (size_ == capacity_) {
                auto new_begin = new T[capacity_ << 1];
                auto old_end = begin_ + capacity_;
                for (auto old_it = begin_, new_it = new_begin; old_it != old_end; ++old_it, ++new_it) {
                    *new_it = *old_it;
                }
                begin_ = new_begin;
                capacity_ <<= 1;
            }
            begin_[size_] = value;
            ++size_;
        }

        void pop_back() {
            if (size_) {
                --size_;
            }
        }

        T back() const {
            if (size_) {
                return begin_ + (size_ - 1);
            }
        }

        size_t size() const {
            return size_;
        }

        ~vector() {
            delete[] begin_;
        }

    private:
        size_t capacity_ = 0;
        size_t size_ = 0;
        T* begin_ = nullptr;
    };
}

#endif //MYSTL_VECTOR_H
