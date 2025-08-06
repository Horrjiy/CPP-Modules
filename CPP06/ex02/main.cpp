#include "Base.hpp"

Base *generate(void)
{
	auto timenow = std::chrono::system_clock::now().time_since_epoch();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(timenow).count();
	std::cout << "\033[33m-~-~-~  num  ~-~-~-\033[0m\n"
			  << ms << std::endl;
	ms = ms % 3;
	std::cout << ms << std::endl;
	switch (ms)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	default:
		return (nullptr);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
	}
	catch (std::exception &e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
		}
		catch (std::exception &e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
			}
			catch (std::exception &e)
			{
				return;
			}
			std::cout << "C\n";
			return;
		}
		std::cout << "B\n";
		return;
	}
	std::cout << "A\n";
	return;
}

int main(void)
{
	Base *test = generate();
	std::cout << "\033[33m-~-~-~  pointer  ~-~-~-\033[0m\n";
	identify(test);
	std::cout << "\033[33m-~-~-~ reference ~-~-~-\033[0m\n";
	identify(*test);
	delete test;
}