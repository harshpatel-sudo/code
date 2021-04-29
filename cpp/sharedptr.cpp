#include <iostream>
#include<memory>
class Counter
{
    int mCounter;

public:
    Counter() : mCounter(0){};
    Counter(const Counter &) = delete;
    Counter &operator=(const Counter) = delete;

    int get() { return mCounter; }
    void reset() { mCounter = 0; }
    int operator++()
    {
        mCounter++;
        std::cout << "Post Counter " << mCounter << std::endl;
        return mCounter;
    }
    int operator++(int)
    {
        ++mCounter;
        std::cout << "Counter : " << mCounter << std::endl; 
        return mCounter;
    }

    int operator--() { return mCounter--; }
    int operator--(int) { return --mCounter; }

    int operator()() { return mCounter; }
};

template <typename T>
class Shared_ptr
{
private:
    T *ptr;
    Counter *refCount;

public:
    explicit Shared_ptr(T *ptr = nullptr) : ptr(ptr)
    {
        refCount = new Counter();
        if (ptr)
        {
            std::cout << "Init count" << std::endl;
            ++(*refCount);
        }

        std::cout << "Constructed -- count " << refCount->get() << std::endl;
    }

    Shared_ptr(const Shared_ptr<T> &rhs)
    {
        std::cout << "Copy Constructed -- count " << rhs.refCount->get() << std::endl;
        ptr = rhs.ptr;
        refCount = rhs.refCount;
        ++(*refCount);
        std::cout << "After Copy Constructed -- count " << refCount->get() << std::endl;
    }
    ~Shared_ptr()
    {
        std::cout << "Destructor Called -- Count " << refCount->get() << std::endl;
        (*refCount)--;
        if (!refCount->get())
        {
            delete ptr;
            delete refCount;
            std::cout << "Deleted" << std::endl;
        }
    }
    int ref_count() { return refCount->get(); }

    T &operator*() { return *ptr; }
    T *operator->() { return ptr; }
};

int main()
{
    //Shared_ptr<int> ptr1(new int(3));
    std::shared_ptr<int> ptr1(new int(4));
    //Shared_ptr<int>ptr4(new int(5));
    std::shared_ptr<int> ptr2(new int(5));

    ptr1=ptr2;

    std::cout<<*ptr1<<std::endl;
    return 0;
}