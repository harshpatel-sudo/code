# Cache

Cache is just a concept of effectively storing data in faster memory.

CPU caches:
- L1 - Separate for each core
- L2 - Shared/separate between cores
- L3 - Shared among all cores

## Write cache-friendly code - [MeetingCpp](https://www.youtube.com/watch?v=Nz9SiF0QVKY&ab_channel=MeetingCpp)

### Takeaway 1: 6:20
  - Memory access is slow, so used memory is cached.
  - Multiple level of cache with varying size and speed

### Takeaway 2: 8:10
 - Entire cache lines are accessed, not individual bytes.
 - Those cache lines always start on specific addresses

### Takeaway 3: 9:30

CPU tries to predict which memory you're going to need next:
 - temporal locality: you probably want to access it again.
 - spatial locality: you probably want neighboring bytes as well

Cache prefetching

### Takeaway 4: 12:00

 - Some caches are not shared between CPUs.
 - False sharing can create unnecessary slowdown.

### Points
-  code is also cached
- Linear, simple code is best
   - No branches
   - No function calls, especially virtual or function pointer
   - No jumps
- Put hot code closely together with other hot code - spacial locality:
  - Rearrange branches
  - Avoid function pointers/Virtual
  - hot/cold like likely/unlikely attributes(C++20)
- Consider alignment of hot code
- Group data that will be accessed together
- Structure the program by following flow of data
- Group data based on how it is actually going to be used
- Implement the common task, not the special case
- Eliminate booleans and object states by making them explicit
- OOP : Arrays of structs(AoS)
- CPU friendly: Struct of arrays(SoA)

- Main Memory Access is Slow
    - Improve locality: use simple, contiguous memory layout
    - Don't waste cache space: Group data based on access patterns
    - Take care of the instruction cache - put cold code away from hot code

- Use benchmarks and profiling tools.

## Cache Associativiy

### DM : Direct Map
- Elements will be stored at their hash index only. If there exist any element already, it will be replaced
- It will not check whether other indexes are empty or not.
- While reading; element will be checked at Hashed index -> if not found (cache miss) it will go to memory
  
### FA : Fully Associative
- Element can be stored at any position based on LRU like algorithms.
- While reading; whole cache line is taken and then all values are compared one by one.
  
### SA : Set Associative
- Combination of both : Memory will be separated in sets.
- Hash will determine the set index
- If first position in set is already filled (cache miss) then it will be stored at next position in the set.
- While Reading; whole set is taken based on Hash and elements are compared one by one.

## Terms:

- Cache hit
- Cache miss
- Writing policies
  - Write-thourgh
  - Write back
- Policies
  - Time aware least recently used (TLRU)
  - Least frequent recently used (LFRU)
