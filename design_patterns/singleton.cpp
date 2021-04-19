class Singleton
{
public:
    static Singleton &getInstance()
    {
        static Singleton instance; // before C++11, this was not thread safe
        return instance;
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