#pragma once
#include <iostream>
namespace JMP
{
	class string
	{
	public:
		string();
		string(char* word);
		char* word;
		uint32_t Lenght();
		bool Contains(char* word);
		string* Split(const char delimiter);


		operator char*() const;
		string& operator=(const char*& other);
		string& operator+=(const char*& other);
	
	private:
		uint32_t count;
		uint32_t Count();
	};
	string operator+(const string left, const char*& other);
	std::ostream& operator<<(std::ostream& output, const string& obj);
	std::istream& operator>>(std::istream& input, const string& obj);
}