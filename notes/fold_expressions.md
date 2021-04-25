# Fold Expressions

- Unary right fold: (E op ...) becomes (E op (... op (E N-1 op E N)))
- Unary left fold: (... op E) becomes (((E1 op E3) op ...) op EN)
- Binary right fold: (E op ... op I) becomes (E1 op (... op (EN−1 op (EN op I))))
- Binary left fold (I op ... op E) becomes ((((I op E1) op E2) op ...) op EN)


```C++

template<typename ... Arg>
void print(Arg& ... args){
    cout << ... << args; // Unary Left Fold
    ((cout<< args << '\n'), ...); // this will print each word on new line -> Research more
}

template<typename ... Arg>
auto sum(Arg& ... args) {
    return (args + ...); // Fold expression
}

int main(){
    print(1,"Hello",3.14, "World!");
    int value = sum(1,3,4,5,6,9);
}
```