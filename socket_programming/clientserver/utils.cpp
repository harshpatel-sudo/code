#include"utils"



template <typename T> 
// Comparator function 
bool comp::operator()(const T& l,const T& r) const
{ 
    if (l.second != r.second)
    { 
        return l.second < r.second; 
    } 
    return l.first < r.first; 
} 


void sort(map<int, long>& M) 
{ 
    // Declare set of pairs and insert 
    // pairs according to the comparator 
    // function comp() 
    set<pair<int, long>, comp> S(M.begin(), 
                                   M.end()); 
    // Print the sorted value 
    for (auto& it : S) { 
        cout << it.first << ' '
             << it.second << endl; 
    } 
}
