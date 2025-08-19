#include <iostream>
using namespace std;

class Person {
public:
	string name;
	int age;

	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}

	virtual void call() const {
		cout << name << endl;
	}
};

class Husband : public Person {
public:
	Husband(string name, int age) : Person(name, age) {
	}

	void call() const override {
		cout << "Askimmm" << endl;
	}
};

class Father : public Person {
public:
	Father(string name, int age) : Person(name, age) {
	}

	void call() const override {
		cout << "Bubaaa" << endl;
	}
};

class Employee : public Person {
public:
	Employee(string name, int age) : Person(name, age) {
	}

	void call() const override {
		cout << name << " Bey" << endl;
	}
};

/* --- Main Function --- */
int main() {

	Person arda("Arda", 21);
	Husband theHusbandOfAyda("Arda", 21);
	Father theFatherOfBaldos("Arda", 21);
	Employee ardaAtWork("Arda", 21);

	arda.call();
	theHusbandOfAyda.call();
	theFatherOfBaldos.call();
	ardaAtWork.call();
	
	return 0;
}