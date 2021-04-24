# union

Compact the data down

## Why?
- In some cases; only one situation out of many is suitable for any given time.
- Only One field is live at a time
- Space is allocated same as largest datatype

## Syntax
-same as struct

```C++
union my_union{
    int intField;
    float floatField;
    double stringField;
};
```