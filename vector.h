#ifndef MYSTL_VECTOR_H
#define MYSTL_VECTOR_H

#include <algorithm>

namespace MySTD {
    template<typename T>
    class vector {
    public:
        // constructors and destructors:

        vector() {
            capacity_ = 1;
            size_ = 0;
            data_begin_ = new T[capacity_];
        }

        vector(const size_t size, const T& value) {
            capacity_ = size;
            size_ = size;
            data_begin_ = new T[capacity_];
            std::fill(data_begin_, data_begin_ + size_, value);
        }

        vector(const vector<T>& other) {
            capacity_ = other.size_;
            size_ = other.size_;
            data_begin_ = new T[capacity_];
            std::copy(other.data_begin_, other.data_begin_ + other.size_, data_begin_);
        }

        vector(vector<T>&& other) {
            delete[] data_begin_;
            capacity_ = other.size_;
            size_ = other.size_;
            data_begin_ = new T[capacity_];
            std::copy(other.data_begin_, other.data_begin_ + other.size_, data_begin_);
            delete[] other.data_begin_;
        }

        ~vector() {
            delete[] data_begin_;
        }

        //modifiers:

        void clear() {
            delete[] data_begin_;
            size_ = 0;
            capacity_ = 0;
        }

        void push_back(const T& value) {
            if (size_ == capacity_) {
                auto new_begin = new T[capacity_ << 1];
                std::copy(data_begin_, data_begin_ + capacity_, new_begin);
                delete[] data_begin_;
                data_begin_ = new_begin;
                capacity_ <<= 1;
            }
            data_begin_[size_] = value;
            ++size_;
        }

        void pop_back() {
            if (size_) {
                --size_;
            }
        }

        vector<T>& operator=(const vector<T>& other) {
            delete[] data_begin_;
            capacity_ = other.size_;
            size_ = other.size_;
            data_begin_ = new T[capacity_];
            std::copy(other.data_begin_, other.data_begin_ + other.size_, data_begin_);
            return *this;
        }

        vector<T>& operator=(vector<T>&& other) {
            if (*other == *this) { // or other order?, &other == this maybe
                return *this;
            }
            delete[] data_begin_;
            capacity_ = other.size_;
            size_ = other.size_;
            data_begin_ = new T[capacity_];
            std::copy(other.data_begin_, other.data_begin_ + other.size_, data_begin_);
            delete[] other.data_begin_;
            return *this;
        }

        T back() const {
            return data_begin_ + (size_ - 1);
        }

        T& operator[](size_t pos) const {
            return *(data_begin_ + pos);
        }

        // Memory

        bool empty() const {
            return size_ == 0;
        }

        size_t size() const {
            return size_;
        }

        size_t capacity() const {
            return capacity_;
        }

    private:
        size_t capacity_ = 0;
        size_t size_ = 0;
        T* data_begin_ = nullptr;
    };
}

#endif //MYSTL_VECTOR_H
