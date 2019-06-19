// Copyright 2018 Soumya Nag Suman soumya@bu.edu
// Copyright 2018 Rahul Rajaram rrajaram@bu.edu
// Copyright 2018 Jennifer Hong hongjt@bu.edu
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include "timer.h"
// add additional libraries if you need them
using std::cin;
using std::cout;

int i;
int j;

int dizzystep (int number, int base) {
  int sum = 0;
  int digit;
  // int base;
  while (number > 0) {
    digit = number % base;
    number = number / base;
    sum = (digit * digit) + sum;
  }
  return sum;
}

struct dizzyGenerator {
  std::vector<int> find_dizzy_up_to(int last, const int base = 10) {
    std::vector<int> v;
    for (int i = 1; i <= last; i++) {
      if (is_dizzy(i, base)) {
        v.push_back(i);
      }
    }
    return v;
  }

  std::vector<int> dizziness_cycle(int number, int base = 10) {
    std::vector<int> s;
    s.push_back(number);
    while (number != 1) {
      int d = number;
      number = 0;

      while (d > 0) {
        number = number + (d % base) * (d % base);
        d = d / base;
      }
      for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == number) {
          s.erase(s.begin(), s.begin() + i);
          return s;
        }
      }
      s.push_back(number);
    }
    s.clear();
    s.push_back(1);
    return s;
  }
  int convertbase(int num, const int tobase) {
    int numbs = 0;
    int factor = 1;
    int digit;
    while (num > 0) {
      digit = num % tobase;
      numbs = numbs + (digit * factor);
      factor = factor * 10;
      num = num / tobase;
    }
    return numbs;
  }


  bool is_dizzy(int number, int base = 10) {
    std::vector<int> previoussums;
    while (number != 1) {
      number = dizzystep(number, base);
      //stores each number in a vector to be checked
      //checks if the number is the same as a previously
      //tested number to find if it is an infinite loop AKA not dizzy
      for(i = previoussums.size() - 1; i >= 0; i--) {
        if (previoussums.at(i) == number) {
          return false;
        }
      }
      previoussums.push_back(number);
    }
    return true;
  }
};


// MAIN   leave this line and all below as is
//        when submitting


const double TLIMIT = 0.5;

void standard_tests();
void interactive_main();

int main(int argc, const char **argv) {
  //dizzyGenerator d;

  //vector<string> test = d.dizzy
  //int a = lol;

  //std::cout << d.is_dizzy(10, 10);
  if (argc > 1)
    interactive_main();
  else
    standard_tests();
  return 0;
}

void standard_tests() {



  double speed = computer_speed();
  std::cerr << "Your computers speed relative to server: " << speed << "\n";

  Timer tall, t0("setup"), t1("all100");
  Timer t3("lots_of_base_10"), t4("lots_of_bases");


  std::vector<std::pair<int, int>> res;

  t0.start();
  dizzyGenerator h;
  t0.stop();

  // Test case definitions.
  std::vector<int> dizzy_tests_one{1, 4, 7, 145, 91, 31435135};
  std::vector<std::vector<int>> dizzy_tests_two{{14500, 10}, {2, 3},
    {255, 2}, {255, 4}, {998, 998}, {4, 10}, {7, 3},
    {41, 100}, {234, 100}, {124, 100}, {22357, 1000}, {1049, 1000}};
  std::vector<std::vector<int>> find_upto_tests_two{{100, 3},
    {1000, 11}, {20, 2}};
  std::vector<int> find_upto_tests_one{10, 100};

  std::cout << "Testing is_dizzy (two parameters)\n";
  for (auto e : dizzy_tests_two) {
    std::cout << "is_dizzy(" << e.at(0) << "," << e.at(1) << ") = ";
    std::cout << h.is_dizzy(e.at(0), e.at(1)) << "\n";
  }

  std::cout << "Testing is_dizzy (one parameter)\n";
  for (auto e : dizzy_tests_one) {
    std::cout << "is_dizzy(" << e << ") = ";
    std::cout << h.is_dizzy(e) << "\n";
  }

  std::cout << "Testing dizziness_cycle (two parameters)\n";
  for (auto e : dizzy_tests_two) {
    std::cout << "dizziness_cycle(" << e.at(0) << "," << e.at(1) << ") = ";
    for (auto cyc_val : h.dizziness_cycle(e.at(0), e.at(1)))
      std::cout << cyc_val << " ";
    std::cout << "\n";
  }

  std::cout << "Testing dizziness_cycle (one parameter)\n";
  for (auto e : dizzy_tests_one) {
    std::cout << "dizziness_cycle(" << e << ") = ";
    for (auto cyc_val : h.dizziness_cycle(e))
      std::cout << cyc_val << " ";
    std::cout << "\n";
  }

  std::cout << "Testing find_dizzy_up_to (two parameters)\n";
  for (auto e : find_upto_tests_two) {
    std::cout << "find_dizzy_up_to(" << e.at(0) << "," << e.at(1) << ") = ";
    for (auto dizzyval : h.find_dizzy_up_to(e.at(0), e.at(1)))
      std::cout << dizzyval << " ";
    std::cout << "\n";
  }


  std::cout << "Testing find_dizzy_up_to (one parameter)\n";
  for (auto e : find_upto_tests_one) {
    std::cout << "find_dizzy_up_to(" << e << ") = ";
    for (auto dizzynum : h.find_dizzy_up_to(e))
      std::cout << dizzynum << " ";
    std::cout << "\n";
  }


  std::cout << "Finding the dizziest bases\n";

  t1.start();
  for (int i = 2; i < 100; i++) {
    auto v = h.find_dizzy_up_to(100, i);
    res.push_back(std::make_pair(v.size(), i));
  }
  t1.stop();

  std::sort(res.begin(), res.end());

  std::cout << "The ten dizziest bases (for 1 to 100) are \n";
  for (auto it = res.rbegin(); it != res.rbegin() + 10 ; it++)
    std::cout << "base "  << it -> second << " has "
              << it -> first << " dizzy\n";



  std::cout << "\nHow many dizzy can you find in 0.5 seconds, base 10?\n";
  int start_size = 100;
  while (t3.time() < TLIMIT) {
    t3.start();
    std::vector<int> res =  h.find_dizzy_up_to(start_size);
    t3.stop();
    std::vector<uint64_t> locs{0, res.size() / 3,
                               2 * res.size() / 3, res.size() - 1};
    for (auto i : locs) {
      std::cout << "ss:" << start_size << " i: " << i
                << " v: " << res.at(i) << "\n";
    }
    start_size *= 2;
  }



  std::cout << "\nHow many dizzy can you find in 0.5 seconds, all bases?\n";
  int base = 2;
  while (t4.time() < TLIMIT) {
    t4.start();
    std::vector<int> res =  h.find_dizzy_up_to(20000, base);
    t4.stop();
    std::vector<uint64_t> locs{0, res.size() / 3,
                               2 * res.size() / 3, res.size() - 1};
    for (auto i : locs) {
      std::cout << "base:" << base
                << " i: " << i << " v: " << res.at(i) << "\n";
    }
    base *= 2;
  }
}


void interactive_main() {
  std::string asktype;
  int number, parameters, base;
  dizzyGenerator h;

  while (true) {
    std::cin >> asktype;
    if (asktype == "quit") break;
    std::cin >> parameters >> number;
    if (parameters > 1) std::cin >> base;
    if (asktype == "i" and parameters == 2) {
      std::cout << "is_dizzy(" << number << "," << base << ") = ";
      std::cout << h.is_dizzy(number, base) << "\n";
    } else if (asktype == "i" and parameters == 1) {
      std::cout << "is_dizzy(" << number << ") = ";
      std::cout << h.is_dizzy(number) << "\n";
    } else if (asktype == "c" and parameters == 2) {
      std::cout << "dizziness_cycle(" << number << "," << base << ") = ";
      for (auto cyc_val : h.dizziness_cycle(number, base) )
        std::cout << cyc_val << " ";
      std::cout << "\n";
    } else if (asktype == "c" and parameters == 1) {
      std::cout << "dizziness_cycle(" << number << ") = ";
      for (auto cyc_val : h.dizziness_cycle(number))
        std::cout << cyc_val << " ";
      std::cout << "\n";
    } else if (asktype == "f" and parameters == 2) {
      std::cout << "find_dizzy_up_to(" << number << "," << base << ") = ";
      for (auto dizzyval : h.find_dizzy_up_to(number, base))
        std::cout << dizzyval << " ";
      std::cout << "\n";
    } else if (asktype == "f" and parameters == 1) {
      std::cout << "find_dizzy_up_to(" << number << ") = ";
      for (auto dizzynum : h.find_dizzy_up_to(number))
        std::cout << dizzynum << " ";
      std::cout << "\n";
    }
  }
}