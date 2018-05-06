# rationalThinking
C++ representation of arbitrarily large integers, and implementing it to create a representation of rational numbers as well.


# Problem Description
Fundamental number types like int and double are limited in both the range of values
they can hold, and the precision with which they can represent fractional values –
1/10 , for example, has no exact floating point representation. This situation can be improved
in two steps – firstly creating a representation for arbitrarily large integers; then
using these integers to implement rational numbers (fractions). This has, of course,
been done many times and some languages (such as Python) support exact integers
automatically. In the time-honoured tradition of reinventing the wheel, we’re asking
you to implement firstly large integers, then rationals. 

This is also an étude about modularity, encapsulation, reuse, and algorithm choice.
You should consider your choice of algorithms and data structures carefully.
While we are not expecting elaborate optimisations or convoluted algorithms, we
do expect your implementation to be reasonably efficient.


* COSC326 Etude 9, pair.
* @author Nikolah Pearce and Finn Luxton


Compile using: 
* g++ *.cpp  - o main or
* g++ Integer.cpp Main.cpp -o testIntegerOnly 
* Main.cpp is available for testing purposes.
