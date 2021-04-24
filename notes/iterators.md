# Iterators
- Forwad Iterator
- Input Iterator
- Output Iterator
- Reverse Iterator
- Random access Iterators

## Input Iterator

- Weakest and simplest
- Used in sequential input operations
- __readonly__
- Each value can be accessed only __once__ and then iterator is incremented
- can be used for comparison
- Copy-constructible, copy-assignable and destructible
- can be dereferenced as an __rvalue__
- can be used in __swap__ algorithm
- cannot be decremented
- useful in single-pass input algorithms
  
## Output Iterator
- Used in sequential output operations
- Each value can be accessed only __once__ and then iterator is incremented
- __cannot__ be used for comparison
- Copy-constructible, copy-assignable and destructible
- can be dereferenced as an __lvalue__ ; but only once
- can be used in __swap__ algorithm
- cannot be decremented
- useful in single-pass output algorithms

## Forward Iterator
- can be used to deference the element multiple times
- but can only be incremented, not decrement
- can be const/non-const
- can be derefereced as __lvalue__ and __rvalue__
- __lvalues__ are swappable

## Bidirectional Iterator
- can be decremented as well
- Rest same as Forward Iterator

## Random Iterator
- Inherits all properties of Bidirectional
- can be used with arithmatiec operators + and - with integers
- can be used with comparison opeartors like < > != etc.
- Supports compound assignments +=, -=
- Supports offset dereference operator []
