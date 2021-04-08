struct S{};

void f1(S s); // Pass by Value
void f2(S & s); // Pass by lvalue reference
void f3(S const & s) // Pass by const reference
void f4(S && s) // Pass by rvalue reference C++11

/* Wy such thing is needed?
Why would someone modify the temporary object as rvalue ref?
This is because caller want to make implicit call of destructor based on the processing done on the temp object.
*/

int main(){
S x; // lvalue

f1(x); // lvalue OK
f1(S()); // rvalue OK -> Anyway argument will be copied into lvalue

f2(x); // lvalue OK
f2(S()); // rvalue ERROR -> You can only take CONST reference of temporary object.

f3(x); // lvalue OK
f3(S()); // rvalue OK -> We are taking const reference to temporary object

f4(x); // ERROR -> Can pass only rvalue (notice const)
f4(S()); // OK -> we are passing rvalue (in the form of Temporary object)

}

/*

Move Semantics:

    This is to enable us to make use of temporary variables.
    Whenever object is being constructed/copied/assigned from temporary; temporary's values can be shifted insted of COPYing members

*/