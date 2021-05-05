# Const
It is a committment to the compiler that you will not change anything
- non-member function cannot have const qualifier
- Read declaration from right to left
  ```C++
  char greeting[] = "Hello";
  char *p = greeting;       // non-const pointer|| non-const data
  const char *p = greeting;// non-const pointer || const data     || Pointer to cosnt char
  char* const p = greeting;// const pointer     || non-const data || const pointer to char
  const char* const p = greeting// both const   || const pointer to const char
  ```
- const ref participate in _function overloading_
  ```C++
  int foo(int &a);
  int foo(const int &a);
  ```
  These two are overloaded functions
- const member functions __can modify static__ members
- const member functions __can modify mutable__ members
- make function type const while returning references from a function
- all captures inside lambda are implictly const
