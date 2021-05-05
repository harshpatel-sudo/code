# Effective C++ - Scott Mayers

## Item 1: C++ as a federation of Languages
1. C
2. Object Oriented C++
3. Template C++
4. STL
   
## Item 2: Prefer const, enums and inline over #defines
- Compiler can't see the macro name while compiling; it will see only literal constant value
- This can cause problems while dubugging and problem crashing scenarios
- You'll never find the name associated with the value shown in the program
- Object will have mupltiple copies of the constants defined by #define (one for each time it was used in program)
- When variable is created using const; it will have only one copy in the memory. hence smaller object code size
- use __static const__ to make sure there is only one copy of the variable per class. _if it is const, anyways all the objects will be having same value. so better make only one copy._
  ```C++
  class A{
      private:
        static const int i=5;
        int Arr[i];
  };
  ```
  Here, There is no need to define this static in implementation file unless we want to use its address
- #define macros can't be interited/encapsulated
  
## Item 3: Use const wherever possible