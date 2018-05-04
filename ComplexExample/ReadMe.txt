This is an example of operator overloading to define mathematical classes.
The example is a partial implementation of complex numbers, and provides
the following operators:

= to assign one Complex number to another
+ to add two Complex numbers 
* to multiply two Complex numbers
<< and >> to make it easy to read and write Complex numbers to/from files 
  or the console with C++'s standard IO system

The code comes with a CMakeLists.txt file, which you can use to set up whatever
build environment (Makefiles, XCode, etc.) you want to use. However, a simple
Makefile is provided as well. You should be able to build and run the code on the
lab OS X machines from the terminal with 
  make
  ./complexTest
  
Complex numbers may be familiar to you, but it not (or if it's been a while),
the motivation for them is usually the problem of taking the square root of 
negative numbers. This isn't possible with normal (real) numbers, but complex
numbers introduce the idea of an imaginary number, i, which is the square root
of -1. So i*i = -1.

A complex number then has a real part and an imaginary part, such as 3+2i or 
-1+3i. We add complex numbers by adding the real and imaginary parts separately:
  (3+2i) + (-1+3i) = (3 + (-1)) + (2i + 3i) 
                   = 2+5i
Multiplication is slightly trickier, but works by the usual rules of algebra:
  (3+2i) * (-1+3i) = 3*(-1+3i) + 2i(-1+3i) 
                   = -3 + 9i -2i + 6i*i 
				   = -3 + 7i - 6 
				   = -9+7i
the only real trick here is to remember that i*i = -i

These details don't concern us too much for the etude though - they only matter
for the details of what the operator overloading has to do, not how it works
more generally. We'll discuss the details in the Town Hall, but basically we can 
view an operation like 3 + 2 as a function (+) that takes two parameters (3 and 
2). C++ lets us define such functions, so the addition operator function for 
Complex numbers is declared as
  Complex& operator+(const Complex& c1, const Complex& c2);
The & on the end of Complex& means we are passing references to the function, 
which avoids copying larger data types, and the 'const' means that the function
guarantees not to modify the objects.

The compiler can then convert code like:
  c1 + c2; // c1, c2 are instances of Complex
to a call to the overloaded function:
  operator+(c1, c2)
 
