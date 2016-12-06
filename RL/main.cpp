#include <memory>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;


class link;
class stringc;
class StringBuffer;

class link
{
public:
    StringBuffer* str;
    link* next;
};

class stringc
{
public:
    char* strBuffer;
    int strlen;
    int refCount;
    link* link;
    
    stringc()
    {
        strBuffer = nullptr;
        strlen = 0;
        refCount = 1;
        link = NULL;
    };
};

class StringBuffer {
private:
	stringc* str;
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
		delete str->link;
		delete str;
            }
            else
            {
		str->refCount -= 1;
		if (str->link->str == this)
		{
                    link* temp = str->link;
                    str->link = str->link->next;
                    delete temp;
		}
		else 
                {
                    link* ptr = str->link;
                    link* prev = NULL;
                    while (ptr)
                    {
                        if (ptr->str == this)
                        {
                            prev->next = ptr->next;
                            delete ptr;
                            break;
                        }
                        prev = ptr;
                        ptr = ptr->next;
                    }
		}
            }
        };
	StringBuffer(const StringBuffer& newString)
        {
            str->strlen = newString.length();
            str->strBuffer = new char[str->strlen];
            for (int i = 0; i < str->strlen; i++)
            {
		        str->strBuffer[i] = newString.charAt(i);
            }
            link* newLink = new link;
            newLink->str = this;
            newLink->next = NULL;
            if (str->link == NULL)
            {
            	str->link = newLink;
            }
            else
            {
		link* ptr = str->link;
		link*  prev = NULL;
		while (ptr)
		{
                    prev = ptr;
                    ptr = ptr->next;
		}
		prev->next = newLink;
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
            link* newLink = new link;
            newLink->str = this;
            newLink->next = NULL;

            if (str->link == NULL)
            {
		str->link = newLink;
            }
            else
            {
		link* ptr = str->link;
		link* prev = NULL;
		while (ptr)
		{
                    prev = ptr;
                    ptr = ptr->next;
		}
		prev->next = newLink;
            }
        };
	char charAt(int) const;
	int length() const;
	void reserve(int);
	void append(char);
        
	link* get_link();
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
    return this->str->strlen;
}

void StringBuffer::reserve(int length)
{
    str = new stringc;
    str->strBuffer = new char[length];
    link* newLink = new link;
    newLink->str = this;
    newLink->next = NULL;
    if (str->link == NULL)
    {
        str->link = newLink;
    }
    else
    {
        link* ptr = str->link;
        link*  prev = NULL;
	while (ptr)
	{
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = newLink;
    }
}

void StringBuffer::append(char c)
{
    if (this->str->refCount > 1)
    {
	stringc* str1 = new stringc;
	str1->strlen = str->strlen + 1;
	str1->strBuffer = new char[str1->strlen];
        for (int i = 0; i < str->strlen; i++)
        {
            str1->strBuffer[i] = str->strBuffer[i];
        }
        str1->strBuffer[str->strlen] = c;
        str->refCount -= 1;
        if (str->link->str == this)
	{
            link* str1 = str->link;
            str->link = str->link->next;
            delete str1;
	}
	else
        {
            link* ptr = str->link;
            link* prev = NULL;
            while (ptr)
            {
                if (ptr->str == this)
                {
                    prev->next = ptr->next;
                    delete ptr;
                    break;
                }
                prev = ptr;
                ptr = ptr->next;
            }

        }
        str = str1;
        link* newLink = new link;
        newLink->str = this;
        newLink->next = NULL;
        if (str->link == NULL)
        {
            str->link = newLink;
        }
        else
        {
            link* ptr = str->link;
            link*  prev = NULL;
            while (ptr)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = newLink;
        }

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

link* StringBuffer::get_link() 
{
    return this->str->link;
}

StringBuffer& StringBuffer::operator = (const StringBuffer& newString)
{
	str = newString.str;
	str->refCount++;
	link* newLink = new link;
	newLink->str = this;
	newLink->next = NULL;
	if (str->link == NULL)
	{
            str->link = newLink;
	}
	else
	{
		link* ptr = str->link;
		link*  prev = NULL;
		while (ptr)
		{
                    prev = ptr;
                    ptr = ptr->next;
		}
		prev->next = newLink;
	}
	return *this;
}

int main(int argc, char** argv) {
	
	char* hello = "hello";

	StringBuffer* str1 = new StringBuffer(hello, 5);
	StringBuffer* str2 = new StringBuffer();
	*str2 = *str1;
	
	cout << "length of object 1 is=" << str1->length() << std::endl;
	cout << "length of object 2 is =" << str2->length() << std::endl;
        
	str1->append('a');
	str2->append('i');

    cout<<"length after appending\n";cout << "length of object 1 is=" << str1->length() << std::endl;
	cout << "length of object 2 is =" << str2->length() << std::endl;
	return 0;
}