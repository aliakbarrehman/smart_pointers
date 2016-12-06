#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class stringc
{
public:
	char* strBuffer;
	int strlen;
	int refCount;
	stringc()
	{	
		strBuffer = nullptr;
		strlen = 0;
		refCount = 1;
	};
};

class StringBuffer {

private:
	stringc*  str;

public:
	StringBuffer()
	{
		str = nullptr;
	};
	~StringBuffer()
	{
		if (str->refCount == 1)
		{
			delete[] str->strBuffer;
			delete str;
		}
		else
		{
			str->refCount -= 1;
		}
	};
	StringBuffer(const StringBuffer& newString)
	{
		str->strlen = newString.length();
		str->strBuffer = new char[str->strlen];
		for (int i = 0; i<str->strlen; i++)
		{
			str->strBuffer[i] = newString.charAt(i);
		}
	};
	StringBuffer(char* ptr, int length)
	{
		str = new stringc;
		str->strBuffer = new char[length];
		str->strlen = length;
		for (int i = 0; i < length - 1; i++)
		{
			str->strBuffer[i] = ptr[i];
		}
	};
	char charAt(int) const;
	int length() const;
	void reserve(int);
	void append(char);

	StringBuffer& operator = (const StringBuffer&);
};

char StringBuffer::charAt(int index) const
{
	if (index < str->strlen)
	{
		return *(str->strBuffer + index);
	}
	else 
	{
		//exception
	}

}

int StringBuffer::length() const
{
	return str->strlen;
}

void StringBuffer::reserve(int length)
{

	str = new stringc;
	str->strBuffer = new char[length];
}

void StringBuffer::append(char c)
{
	if (str->refCount > 1)
	{
		stringc* str1 = new stringc;
		str1->strlen = str->strlen + 1;
		str1->strBuffer = new char[str1->strlen];
		for (int i = 0; i < str->strlen; i++)
		{
			str1->strBuffer[i] = str->strBuffer[i];
		}
		str1->strBuffer[str->strlen] = c;
		str->refCount--;
		str = str1;
	}
	else
	{
		char* str1 = str->strBuffer;
		str->strlen++;
		str->strBuffer = new char[str->strlen];
		for (int i = 0; i < str->strlen - 1; i++)
		{
			str->strBuffer[i] = str1[i];
		}
		str->strBuffer[str->strlen - 1] = c;
		delete[] str1;
	}
}

StringBuffer& StringBuffer::operator = (const StringBuffer& str2)
{
	str = str2.str;
	str->refCount++;
	return *this;
}

int main() 
{
	char* hello = "hello";
	StringBuffer* str1 = new StringBuffer(hello, 5);
	StringBuffer* str2 = new StringBuffer();

	*str2 = *str1;
	cout << "object 1 length =" << str1->length() << endl;
	cout << "object 2 length =" << str2->length() <<endl;
	str1->append('y');
	str2->append('o');
	str2->append('u');
        cout<<"length after appending";
	cout << "object 1 length =" << str1->length() << endl;
	cout << "object 2 length =" << str2->length() <<endl;
	std::cout << "new charAt 5 = " << str1->charAt(5) << endl;

	return 0;
}