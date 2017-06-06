#pragma once

#include <cstdlib>
#include <unordered_map>
#include <list>
#include <iostream>

namespace vralex {

template <class Key, class Value>
class LRUCache {
public:
    LRUCache(size_t capacity)
        : capacity_(capacity)
    {
    }

    const Value& get(const Key& key) const {
        update(key);
        debug();
        return (*positions_.at(key))->value;
    }

    Value& get(const Key& key) {
        update(key);
        debug();
        return (*positions_.at(key))->value;
    }

    void put(const Key& key, Value&& value) {
        if (contains(key)) {
            (*positions_.at(key))->value = std::move(value);
        } else {
            ensureHasEnoughCapacity();
            doPut(key, std::move(value));
        }
        debug();
    }

    void put(const Key& key, const Value& value) {
        if (contains(key)) {
            update(key);
            (*positions_.at(key))->value = value;
        } else {
            ensureHasEnoughCapacity();
            doPut(key, value);
        }
        debug();
    }
    bool contains(const Key& key) const {
        auto it = positions_.find(key);
        if (it != positions_.end()) {
            update(key);
            debug();
            return true;
        } else {
            return false;
        }
    }

private:
    struct CacheItem {
        CacheItem(const Key& key, const Value& value)
            : key(key)
            , value(value)
        {
        }

        CacheItem(const Key& key, Value&& value)
            : key(key)
            , value(std::move(value))
        {
        }

        Key key;
        Value value;
    };

    using CacheIterator = typename std::list<std::unique_ptr<CacheItem>>::iterator;

    void update(const Key& key) const {
        auto iterator = positions_.at(key);
        auto item = std::move(*iterator);

        positions_.erase(key);
        cache_.erase(iterator);

        cache_.push_front(std::move(item));
        positions_[cache_.front()->key] = cache_.begin();
    }

    void ensureHasEnoughCapacity() {
        if (cache_.size() < capacity_) {
            return;
        }

        positions_.erase(cache_.back()->key);
        cache_.pop_back();
    }

    void doPut(const Key& key, Value&& value) {
        cache_.push_front(std::make_unique<CacheItem>(key, std::move(value)));
        positions_[key] = cache_.begin();
    }

    void doPut(const Key& key, const Value& value) {
        cache_.push_front(std::make_unique<CacheItem>(key, value));
        positions_[key] = cache_.begin();
    }

    void debug() const {
        std::cout << "Cache size = " << cache_.size() << std::endl;
        std::cout << "Positions size = " << positions_.size() << std::endl;
        std::cout << "Cache elements = {" << std::endl;
        for (auto& item : cache_) {
            std::cout << "\t{ " << item->key << ", " << item->value << " }," << std::endl;
        }
        std::cout << "}" << std::endl;
    }

    size_t capacity_;

    mutable std::list<std::unique_ptr<CacheItem>> cache_;
    mutable std::unordered_map<Key, CacheIterator> positions_;
};

} // namespace vralex

