# pragma once

#include<iostream>
#include<climits>
#include<bits/stdc++.h>

using namespace std;


class Person
{
  string name;
  int age;
  public:
    Person(string name , int age)
    {
      this->name = name;
      this->age = age;
    }

    int getAge()
    {
      return this->age;
    }

    string getName()
    {
      return this->name;
    }
};

// Below class is required in order to decide priority based on the age of person.
class Comparison
{
  public:
  bool operator()( Person &p1 , Person &p2)
  {
    return p1.getAge() < p2.getAge();
  }
};

