#pragma once
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class Employee
{
public:
    string name;
    int salary, age;

};


vector<Employee> read_from_file();

void showEmpl(vector<Employee>);
