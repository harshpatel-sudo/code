# static

Static has different meanings in different contexts:
* **Global static in a file** - It is visible in the same compilation unit (cpp) only. It has no visibility outside that file.
  **Global statics are very risky**
  
 * **Static in a class** - All instances of the class share same copy of the static variables.
  ```C++
    struct A{
        static int x,y;
    };

    int A::x; //Mandatory 
    int A::y; //Mandatory 

    int main(){
        A obj;
        A::x=5; // valid -> direct access
        obj.y= 5; // valid ->access using object
    }
  ```
  
* **Static in local scope** : Initialized only once; visible in local scopt only.
    ```C++
    #include <stdio.h>

    void Func() {
    static int x = 0;
    // |x| is initialized only once across five calls of |Func| and the variable
    // will get incremented five times after these calls. The final value of |x|
    // will be 5.
    x++;
    printf("%d\n", x);  // outputs the value of |x|
    }

    int main() {
    Func();  // prints 1
    Func();  // prints 2
    Func();  // prints 3
    Func();  // prints 4
    Func();  // prints 5

    return 0;
    }
    ```
* **Static in Template** : Separate copy of static variable for each template class definition. 

## Points
* All static data memberes of the class are initialized to zero when first object of the class is created.
  
* All static data members have different visiblity **but** its lifetime is the entire program.
  
* Uninitialized static variables are stored in BSS segment.

* Initialized static variable are stored in Data Segment.

* C++11 guarantees thread-safe initialization of static variables. 
