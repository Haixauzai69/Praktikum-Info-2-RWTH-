/*
 * smart_pointer.cpp
 *
 *  Created on: Oct 19, 2025
 *      Author: HaiPH
 */

#include <memory>
#include <vector>
#include <string>
#include <list>
#include <iostream>

class Person
{
	public:
	Person() = delete;
	Person(const std::string& name , std::shared_ptr<Person> father = nullptr , std::shared_ptr<Person> mother = nullptr);
	virtual ~Person();
	void setSibling(std::weak_ptr<Person> sibling);

	private:
	const std::string p_sName;
	std::shared_ptr<Person> p_father;
	std::shared_ptr<Person> p_mother;
	std::vector<std::weak_ptr<Person>> p_siblings;
};

Person::Person(const std::string& name, std::shared_ptr<Person> father, std::shared_ptr<Person> mother) :
p_sName(name), p_father(father), p_mother(mother)
{
}

void Person::setSibling(std::weak_ptr<Person> brosis)
{
p_siblings.push_back(brosis);
}

Person::~Person()
{
p_siblings.clear();
std::cout << "Geloescht: " << p_sName << std::endl;
}

void test1 ()
{
auto m1 = std::make_shared<Person>("Josef");
auto f1 = std::make_shared<Person>("Maria");
auto m2 = std::make_shared<Person>("Peter", m1 , f1 );
auto f2 = std::make_shared<Person>("Birgit", m1 , f1 );
m2->setSibling(f2);
f2->setSibling(m2);
}

//int main ()
//{
//std::cout << "Anfang" << std::endl;
//test1();
//std::cout << "Ende" << std::endl;
//return 0;
//}
