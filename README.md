# dizzygen.cpp
Assignment 6
Dizzy Numbers in Multiple Bases

EC327 Summer 2019

1 Introduction
1.1 Assignment Goals
1.2 Group Size
1.3 Due Date
1.4 Assignment Value
1.5 Late policy
1.6 Submission Link
2 Background on dizzy numbers
3 The assignment: dizzyGenerator class
3.1 Specifications for find_dizzy_up_to
3.2 Specifications for is_dizzy
3.3 Specifications for dizziness_cycle
4 Main
4.1 Restrictions
4.2 Downloads
5 Grading Scheme
6 Important Restrictions
1 Introduction
1.1 Assignment Goals
The assignment goals are to help you learn about

class methods
memoization (storing helpful results)
default parameters for functions
1.2 Group Size
The maximum group size is 3 students.

1.3 Due Date
This assignment is due 2018-06-14 at 11:59pm (just before midnight) (extended 3 days).

1.4 Assignment Value
This assignment is worth 10 points.

1.5 Late policy
Late assignments will be accepted until the beginning of the lecture immediately following the due date (lectures are Monday through Thursday afternoons.)

If the natural grade on the assignment is 
g
, the number of hours late is 
h
, and the number of hours between the assignment due time and the next class is 
H
, the new grade will be

(h > H) ? 0 : g * (1- h/(2*H))
If the same assignment is submitted ontime and late, the grade for that component will be the maximum of the ontime submission grade and the scaled late submission grade.

1.6 Submission Link
You can submit here: dizzygen submit link

2 Background on dizzy numbers
In other bases, dizzy numbers are those whose sum of digits squared becomes 1.

Any number which does not do this will necessarily enter into a “dizzy sequence”

Here is an example in base 3: the number 2 is undizzy, because

2
2
 is 
4
10
, which is 
11
3
. 
11
3
 gives 
1
2
 + 
1
2
 which is 
2
3

Thus we have a cycle 
2
3
 -> 
11
3
 -> 
2
3
 -> 
11
3
 and so the number is undizzy.

3 The assignment: dizzyGenerator class
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

Example: take the number 
12
10
. The dizziness cycle for this number in base 3 is the vector of integers {2,4}.

12
=
9
+
3
, so 
12
=
110
3

The number of the squares of digits is 
2
10
=
2
3
.

The next number is 
2
2
=
4
10
=
11
3

The next number is 
1
2
+
1
2
=
2
10
=
2
3

We have a cycle! The cycle is 2 then 4.

The default base is 10.

4 Main
The main program is provided in dizzygen_original.cpp

4.1 Restrictions
You must include the following libraries

<algorithm>
<cstdint>
<iostream>
<string>
<vector>
"timer.h"
You may also include the following:

<array>
<tuple>
<map>,<unordered_map>
<set>,<unordered_set>
No other includes are permitted.

4.2 Downloads
dizzy_answers.txt this is the output of main() when run with no arguments
dizzygen_original.cpp this is the template file
timer.h you will need this in your directory to compile
dizzygen_checker.py this is the checker.
5 Grading Scheme
Out of 100 total points, the grade is determined as follows:

15 points for passing the standard_tests in main() (this is all or nothing)
15 points for passing the specifications of is_dizzy
15 points for passing the specifications of dizziness_cycle
15 points for passing the specifications of find_dizzy_up_to
30 points for program speed (your program must pass the standard_tests to get credit for this)
5 points for astyle (% file unchanged by astyle)
5 points for cpplint, -1 deduction for each problem
6 Important Restrictions
Your program must not be longer than 20,000 characters.

You may not use brackets: []. Instead, use the .at method.
