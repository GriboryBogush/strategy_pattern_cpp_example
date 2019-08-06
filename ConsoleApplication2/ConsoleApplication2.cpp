// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>

/* Strategy Pattern Example */


// Sadly, not a super smart compiler since
// I've got to order stuff around to make it to work

// strategy.h
class Strategy {
public:
	virtual void alogrithm() = 0;
};

// strategy.cpp
class ConcreteStrategy1 : Strategy {
	void alogrithm() override {
		std::cout << "Strategy Implementation1" << std::endl;
	}
};


class ConcreteStrategy2 : Strategy {
	void alogrithm() override {
		std::cout << "Strategy Implementation2" << std::endl;
	}
};

// context.h
class Context {
private: 
	Strategy* s1;
public:
	Context();
	~Context();
	void doSmth();
};

// context.cpp
Context::Context() {
	// classic c++ :)
	const float flag = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	// scary c style cast, my my..
	Context::s1 = flag > 0.5 ? (Strategy*) new ConcreteStrategy1() : (Strategy*) new ConcreteStrategy2();
}

Context::~Context() {
	delete Context::s1;
}

void Context::doSmth() {
	Context::s1->alogrithm();
}

int main()
{
	// I need to look more into random number generation
	srand(time(NULL));

	Context* c1 = new Context();
	c1->doSmth();
	delete c1;
}