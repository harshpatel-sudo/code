# Maps
## unordered_map

- Container of <key,value> pair
- No Sorted
- Implemented using Hash Map

```C++
#include<unordered_map>

std::unordered_map<string,double> umap;
umap["PI"]=3.14;
umap.insert(make_pair("Zero",0));
```

## map

- Ordered map
- Implemented using Binary Tree
- Default sorting parameter is ```std::less```
