# Init Condition Statements - C++17

It allows to add initialization statement inside if statement.
<br>
Useful for preventing scope-leak

## Syntax
if(_initialize statement_; _condition_) {_code_}
```C++

if(int a=somefunc(); a!=0){}

```