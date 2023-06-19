//
// Created by yjs on 23-6-19.
//

#include <boost/noncopyable.hpp>
#include <muduo/base/Mutex.h>

using namespace muduo;



class Counter : boost::noncopyable {

public:
    Counter() : value_(0) {}
    int64_t value() const;
    int64_t getAndIncrease();
private:

    int64_t value_;
    mutable MutexLock mutex_;
};

int64_t  Counter::value() const {

    MutexLockGuard Lock(mutex_);
    return value_;
}

int64_t  Counter::getAndIncrease() {
    MutexLockGuard Lock(mutex_);
    int64_t  ret=value_++;
    return ret;

}


int main(){

    return 0;
}
