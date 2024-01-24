#include "Laba3.h"

class Person
{
private:
	string name;
	string surname;
	int age;
	int salary;
public:
	Person(string name, string surname, int age, int salary)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->salary = salary;
	}
	Person()
	{
		this->name = "";
		this->surname = "";
		this->age = 0;
		this->salary = 0;
	}
	string GetName()
	{
		return this->name;
	}
	string GetSurname()
	{
		return this->surname;
	}
	int GetAge()
	{
		return this->age;
	}
	int GetSalary()
	{
		return this->salary;
	}
	friend std::ostream& operator<<(std::ostream& os, const Person& person) {
		os << "Name: " << person.name << ", Surname: " << person.surname << ", Age: " << person.age << ", Salary: " << person.salary;
		return os;
	}
};