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
    StringBuffer(StringBuffer& str)
    {
        this->strlen = str.strlen;
	this->strBuffer = str.strBuffer;
        
        str.strlen = 0;
        str.strBuffer = NULL;
    };
    
    StringBuffer(char* ptr, int len)
    {
        this->strBuffer = ptr;
	ptr = NULL;
	this->strlen = len;
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
    StringBuffer* str1 = new StringBuffer("hello", 5);
    StringBuffer* str2 = new StringBuffer(*str1);
    
    cout << "String 1 length: " << str1->length();
    cout << "\nString 1 Char At index 0: " << str1->charAt(0);
    
    cout << "\n\nString 2 has taken ownership of memory of String 1 and to avoid dangling pointer NULLED the String 1";
    
    cout << "\nString 2 length: " << str2->length();
    cout << "\nString 2 Char At index 0: " << str2->charAt(0);
    delete str1;
    delete str2;
    return 0;
}

