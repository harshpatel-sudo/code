# Modern CPP - [Youtube](https://www.youtube.com/watch?v=9TFV2JxX7L0&list=PLrR3oTpJZ9ThOhTOBEvwrUZC5aVxj4WSI&index=2&ab_channel=CppNow)

Modern CPP is all about moving majority things at compile time.

## Functor

A functor is a function object OR it is an object that we can treat as if it is callable.

### Why?
- Objects can contain state
- e.g. You can execute some code on an object. and then you can use that object as a function call.
### How do we make an object callable?
- Overload function call operator

_return-type_ operator() _(argument)_ {}

```C++
struct mod {
    mod(int m) : m_(m){} // Constructor

    int operator()(int i){ return i%m;}

    int m_;
}

mod f(4); //Constructed object with some data
cout<<f(42)<<endl; //Used store information using functor (with Function syntax)
```

## RAII
- Invented by Strostrup to handle resource deallocation
- Essential for writing exception-safe code
- Resources are deallocated when destructor is called
- Make RAII objects non-copyable. (__research more__)

## Run-time Policy (Legacy) | Policy class(Modern)
A Policy allows us to specialized behaviour

### Legacy

_done_'s value is evaluated at Run-time

```C++

template<typename T>
void fill(vector<int>&v, T done) {
    // Here 'done' is Lambda. Condition is checked each time.
    int i=0;
    while(!done()) {
        v.push_back(i++);
    }
}

//Use
vector<int> stuff;
fill(stuff,
    [&]{return stuff.size()>=8;}); // Passing lambda as "done's" value
```

### Modern : Policy Class

A _Policy Class_ is a template parameter that specializes behaviour and is selected at compile time.

```C++

std::basic_string < charT, traits, Alloc>

namespace std{
    typedef basic_string<char> string; //We are using this _typedef_ed string object in practice.
}

```

#### Example
```C++

struct NoChecking {
    template<typename T>
    static bool check_pointer(T*){return true;}
};

struct NullChecking {
    template<typename T>
    static bool check_pointer(T*p){return (p!=0);}
};

struct BadPointerDoNothing {
    template<typename T>
    static T* handle_bad_pointer(T*p) {
        std::cout<<"Bad Pointer"<<std::endl;
        return p;
    }
};

template<typename T
        ,typename CheckingPolicy=NoChecking
        ,typename BadPointerPolicy=BadPointerDoNothing
        >
class pointer_wrapper {
    public:
    pointer_wrapper() : value_(0) {};//Constructor
    explicit pointer_wrapper(T* p) : value_(p) {} // Constructor

    operator T*() {
        if(! CheckingPolicy::check_pointer(value_)) {
            return BadPointerPolicy::handle_bad_pointer(value_);
        }
        else {
            return value_;
        }
    }

    private:
    T* value_;

};


int main(){
    pointer_wrapper<int> ptr(new int);
    *ptr=42;
    cout<<*ptr<<endl;

    pointer_wrapper<int> ptr2;
    *ptr2=20; // Segamantation Fault -> Because Default checking policy is NoChecking
    cout<<*ptr2<<endl;

    pointer_wrapper<int,NullChecking> ptr3; // This will print "Bad Pointer"  because compile checks policy at compile time
    *ptr3 = 30;

}
```

## CRTP : Curiously Recurring Template Pattern

### Static Polimorphism
```C++

template<class Derived>
struct base {
    void interface() {
        static_cast<Derived*>(this)->implementation();
    }
};
// Correctly calls correct derived class implementation();


struct derived : base<derived> {
    void implementation();
};
```

### Inject Behaviour

## Type Traits
- Boost.TypeTraits
- C++11 : <type_traits>
### Query charecteristics about types
### Template specialization is pattern matching
```C++

template<typename T>
struct is_int{
    static const bool value =false;
};

template<>
struct is_int<int> { // Template specialization for <int>
    static const bool value = true;
}
```

## Tag Dispatching

## SFINAE : Substitution Failure is not an Error

## Default Template Argument

