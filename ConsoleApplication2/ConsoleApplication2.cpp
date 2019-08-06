#include "pch.h"
#include <iostream>
#include <random>

/* Strategy Pattern Example */

// Fancy rnd generator :)
float get_random()
{	
	std::random_device rd;
	static std::default_random_engine e(rd());
	static std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1
	return dis(e);
}

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
	const float flag = get_random();

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

	Context* c1 = new Context();
	c1->doSmth();
	delete c1;

	// bloody windows
	char ch;
	std::cin >> ch;
}