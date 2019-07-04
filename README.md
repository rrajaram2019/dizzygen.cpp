2) Background on dizzy numbers

In other bases, dizzy numbers are those whose sum of digits squared becomes 1.

Any number which does not do this will necessarily enter into a “dizzy sequence”

Here is an example in base 3: the number 2 is undizzy, because

2 base 3 squared is 4 in base 10, which is 11 in base 3. take the digits of 11, square and add them.

1 squared + 1 squared is 2 base 3.

Thus we have a cycle (alternating between 2 base 3 and 11 base 3)

and so the number is undizzy. However, if the cycle stops at 1 at any point the number is dizzy.

3) The assignment: dizzyGenerator class

Write a program dizzygen.cpp with a struct dizzyGenerator which has several methods as shown below:

struct dizzyGenerator {

   vector<int> find_dizzy_up_to(int last,const int base=10);

   vector<int> dizziness_cycle(int number, int base=10);

   bool is_dizzy(int number,int base=10);

};

You may add other methods and data structures to the class as necessary to solve the problem.

3.1 Specifications for find_dizzy_up_to

Finds all the dizzy numbers up to and including last in the specified base.

The default base is 10.

3.2 Specifications for is_dizzy

Determine whether a number is dizzy in a specified base.

The default base is 10.

3.3 Specifications for dizziness_cycle

vector<int> dizziness_cycle(int number, int base=10);
Find the cycle of numbers that number ends up in for the specified base base.

The default base is 10.

4) Main
The main program tests different numbers.
