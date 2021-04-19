class Singleton
{
public:
    Singleton *Singleton::doubleCheckedInstance()
    {
        if (pInstance == 0)     // 1st test
        {
            Lock lock;          // In this, many threads will try to acquire the lock even if pInstance is initialized. Hence 1st test is added.
            if (pInstance == 0) // 2nd test
            {
                pInstance = new Singleton;
            }
        }
        return pInstance;
    }

private:
    Singleton(){};
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton &operator=(Singleton &&) = delete;
};

int main()
{
    Singleton &firstInstance = Singleton::getInstance();
    Singleton &secondInstance = Singleton::getInstance();
}