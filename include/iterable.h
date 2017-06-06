#pragma once

#include <memory>

namespace vralex {

template <class T>
class TBaseIterator {
public:
    virtual ~TBaseIterator() = default;

    // TODO: add const version
    virtual T& operator*() = 0;

    virtual void decrement() = 0;
    virtual void increment() = 0;

    virtual std::unique_ptr<TBaseIterator> clone() = 0;
};

template <class Iterator, class T>
class TIteratorImpl : public TBaseIterator<T> {
public:
    TIteratorImpl(Iterator iterator)
        : iterator_(iterator)
    {
    }

    T& operator*() override {
        return *iterator_;
    }

    void increment() override {
        ++iterator_;
    }

    void decrement() override {
        --iterator_;
    }

    std::unique_ptr<TBaseIterator<T>> clone() override {
        return std::make_unique<TIteratorImpl>(iterator_);
    }

private:
    Iterator iterator_;
};

template <class T>
class TIterator {
public:
    template <class Iterator>
    TIterator(Iterator iterator)
        : iterator_(std::make_unique<TIteratorImpl<Iterator, T>>(iterator))
    {
    }

    T& operator*() {
        return iterator_->operator*();
    }

    TIterator& operator++(int) {
        iterator_->increment();
        return *this;
    }

    TIterator& operator--(int) {
        iterator_->decrement();
        return *this;
    }

    TIterator operator++() {
        auto copy = clone();
        iterator_->increment();
        return copy;
    }

    TIterator operator--() {
        auto copy = clone();
        iterator_->decrement();
        return copy;
    }

private:
    TIterator(std::unique_ptr<TBaseIterator<T>> iterator)
        : iterator_(std::move(iterator))
    {
    }

    TIterator clone() {
        return iterator_->clone();
    }

    std::unique_ptr<TBaseIterator<T>> iterator_;
};

} // namespace vralex
