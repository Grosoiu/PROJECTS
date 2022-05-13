#include "Employee.h"


vector<Employee> read_from_file()
{

    ifstream f("employees.txt");
    vector<Employee> vect;
    Employee temp;
    while (f >> temp.name >> temp.age >> temp.salary) {
        vect.push_back(temp);
    }
    return vect;
}

 void showEmpl(vector<Employee> aux)
{
     ofstream f("test.txt", ios::app);
    for (const auto& x : aux) {
        f << "Angajatul " << x.name << " varsta:" << x.age<< " salariul: " << x.salary << endl;
    }
} 
