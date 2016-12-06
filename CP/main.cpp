/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ali
 *
 * Created on 03 December 2016, 18:34
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

/*
 * 
 */


class StringBuffer 
{	

private:
	char* strBuffer;
	int strlen;

public:
	StringBuffer()
	{
		this->strBuffer = nullptr;	
		this->strlen = 0;	
	};
        
	~StringBuffer()
	{
		delete[] this->strBuffer;
	}; 

	StringBuffer(const StringBuffer& str)
	{
		this->strlen = str.length(); 
		this->strBuffer = new char[strlen];
		for (int i = 0; i < this->strlen; i++)
		{
			this->strBuffer[i] = str.charAt(i); 
		}
	};
        
	StringBuffer(char* str, int len)
	{
		this->strBuffer = new char[len];
		this->strlen = len;
		for (int i = 0; i < this->strlen - 1; i++)
		{
			strBuffer[i] = str[i];
		}
	};

	char charAt(int) const;
	int length() const;
	void reserve(int);
	void append(char);
};

char StringBuffer::charAt(int i) const
{
    if (i < this->strlen)
    {
            return *(this->strBuffer + i);
    }
    else 
    {
        //exception;
    }
}

int StringBuffer::length() const 
{
    return this->strlen;
}

void StringBuffer::reserve(int len)
{
    this->strBuffer = new char[len];
}

void StringBuffer::append(char ch)
{
	char* temp = this->strBuffer;
	this->strlen++;
	this->strBuffer = new char[this->strlen];
	for (int i = 0; i < this->strlen - 1; i++)
	{
		this->strBuffer[i] = temp[i];
	}
	this->strBuffer[this->strlen - 1] = ch;
	delete[] temp;
}


int main(int argc, char** argv) 
{
    StringBuffer* str = new StringBuffer("hello", 5);
    str->append('a');
    cout << "String length: " << str->length();
    cout << "\nChar At index 0: " << str->charAt(0);
    delete str;
    return 0;
}

