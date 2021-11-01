#ifndef MYSTL_VECTOR_H
#define MYSTL_VECTOR_H

#include <algorithm>

namespace MySTD {
    template<typename T>
    class vector {
    public:
        vector() {
            capacity_ = 1;
            size_ = 0;
            begin_ = new T[capacity_];
        }

        vector(const size_t size, const T& value) {
            capacity_ = size;
            size_ = size;
            begin_ = new T[capacity_];
            std::fill(begin_, begin_ + size_, value);
        }

        vector(const vector<T>& other) {
            capacity_ = other.size_;
            size_ = other.size_;
            begin_ = new T[capacity_];
            std::copy(other.begin_, other.begin_ + other.size_, begin_);
        }

        vector(vector<T>&& other) {
            delete[] begin_;
            capacity_ = other.size_;
            size_ = other.size_;
            begin_ = new T[capacity_];
            std::copy(other.begin_, other.begin_ + other.size_, begin_);
            delete[] other.begin_;
        }

        vector<T>& operator=(const vector<T>& other) {
            delete[] begin_;
            capacity_ = other.size_;
            size_ = other.size_;
            begin_ = new T[capacity_];
            std::copy(other.begin_, other.begin_ + other.size_, begin_);
            return *this;
        }

        vector<T>& operator=(vector<T>&& other) {
            if (*other == *this) { // or other order?, &other == this maybe
                return *this;
            }
            delete[] begin_;
            capacity_ = other.size_;
            size_ = other.size_;
            begin_ = new T[capacity_];
            std::copy(other.begin_, other.begin_ + other.size_, begin_);
            delete[] other.begin_;
            return *this;
        }

        void push_back(const T& value) {
            if (size_ == capacity_) {
                auto new_begin = new T[capacity_ << 1];
                std::copy(begin_, begin_ + capacity_, new_begin);
                delete[] begin_;
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
            return begin_ + (size_ - 1);
        }

        T& operator[](size_t pos) const {
            return *(begin_ + pos);
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
