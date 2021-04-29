# SOLID Design Principles

- Coined by Robert C Martin
  
## Single Responsibility Principle
Class should have only one responsibility

## Open-close Principle
Class should be __open for extension__ and __close for modification__.

## Liskov Substitution Principle
Object of a class should be replacable with one of it derived classes without changing correctness of the program

## Interface Segregation Principle
- Many client spectific interface are better than one general purpose interface
- Users should not inherit features which they do not need

## Dependency Inversion Principle
Dependenceis should be abstract, not concrete. i.e. Dependency should be on TV(abstract), not __Philips__ TV(concrete).
