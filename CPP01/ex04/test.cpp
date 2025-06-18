#include "replace.hpp"

void test1(void)
{
	int retval;
	std::ofstream testfile("test1fruit.txt");
	testfile << "apple\nbanana\norange\ncherry\napple strawberry\norangebananablueberry\n";
	testfile.close();
	std::string *strarr = new std::string[4];
	if (!strarr)
		return (std::cerr << "'new' failed." << std::endl, (void)0);
	strarr[0] = "test1";
	strarr[1] = "test1fruit.txt";
	strarr[2] = "banana";
	strarr[3] = "airplane";
	retval = replace_in_file(4, strarr);
	if (retval == 0)
		std::cout << std::endl << "replaced 'banana' with 'airplane'" << std::endl << std::endl;
	delete[] strarr;
}

void test2(void)
{
	int retval;
	std::ofstream testfile("test2spam.txt");
	testfile << "Lorem ipsum dolor sit amet, consectetur adipiscing elit. \nQuisque purus dui, molestie non pharetra vel, egestas et justo. In elementum enim ex, in ultricies tellus vestibulum porttitor. Aliquam gravida, enim non maximus accumsan, mauris arcu luctus purus, eget ultricies lectus orci vitae orci. \nQuisque non lacus sed dui egestas convallis. Vivamus nec mattis tortor. Aenean metus sapien, vestibulum eu nibh ac, placerat semper neque. \nQuisque fringilla, dolor vitae blandit maximus, turpis dui egestas est, vel laoreet velit odio in mauris. Suspendisse at consectetur massa. Fusce porta diam vitae sem commodo mattis.";
	testfile.close();
	std::string *strarr = new std::string[4];
	if (!strarr)
		return (std::cerr << "'new' failed." << std::endl, (void)0);
	strarr[0] = "test2";
	strarr[1] = "test2spam.txt";
	strarr[2] = "o";
	strarr[3] = "5";
	retval = replace_in_file(4, strarr);
	if (retval == 0)
		std::cout << std::endl << "replaced 'o' with '5'" << std::endl << std::endl;
	delete[] strarr;
}

void test3(void)
{
	int retval;
	std::ofstream testfile("test3talk.txt");
	testfile << "hey whats up\nhey man, how are you today?\nthanks bro, I'm fine\nthats nice.";
	testfile.close();
	std::string *strarr = new std::string[4];
	if (!strarr)
		return (std::cerr << "'new' failed." << std::endl, (void)0);
	strarr[0] = "test3";
	strarr[1] = "test3talk.txt";
	strarr[2] = "hey";
	strarr[3] = "heyheyhey";
	retval = replace_in_file(4, strarr);
	if (retval == 0)
		std::cout << std::endl << "replaced 'hey' with 'heyheyhey'" << std::endl << std::endl;
	delete[] strarr;
}
