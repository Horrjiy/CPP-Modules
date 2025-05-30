#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "main.hpp"

class Contact
{
public:
	int getindex();
	std::string getfname(void);
	std::string getlname(void);
	std::string getphonenum(void);
	std::string getnick(void);
	std::string getsecret(void);
	void setindex(int index);
	void setcontact(void);

private:
	int index;
	std::string fname;
	std::string lname;
	std::string phonenum;
	std::string nick;
	std::string secret;
};

#endif