#include <iostream>
#include <string>
#include <atomic>

using namespace std;

template <typename T>
class SharedPtr
{
public:
    SharedPtr(T* ptr = nullptr)
        : refCnt_(new atomic_int(1))
        , ptr_(ptr) {}

    SharedPtr(const SharedPtr& other)
    {
        refCnt_ = other.refCnt_;
        ptr_ = other.ptr_;
        ++(*refCnt_);
    }

    SharedPtr& operator=(const SharedPtr& other)
    {
        if (this != &other) {
            if (--(*refCnt) == 0) {
                delete refCnt_;
                delete ptr_;
            }

            refCnt_ = other.refCnt_;
            ptr_ = other.ptr_;
            ++(*refCnt_);
        }

        return *this;
    }

    T& operator*() const
    {
        return *ptr_;
    }

    T* operator->() const
    {
        return ptr_;
    }

    ~SharedPtr()
    {
        if (--(*refCnt_) == 0) {
            delete refCnt_;
            delete ptr_;
        }
    }

private:
    atomic_int* refCnt_;
    T* ptr_;
};

int main(int argc, char* argv[])
{
    

    return 0;
}