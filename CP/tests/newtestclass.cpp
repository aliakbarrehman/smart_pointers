/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.cpp
 * Author: Ali
 *
 * Created on 06-Dec-2016, 10:36:14
 */

#include <stdio.h>
#include <stdlib.h>
#include "newtestclass.h"
#include "C:/distr/CUnit-2.1-2/CUnit/Headers/Basic.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

StringBuffer::StringBuffer(StringBuffer& str);

void newtestclass::testStringBuffer() {
    StringBuffer& str;
    StringBuffer stringBuffer(str);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

StringBuffer::StringBuffer(char* ptr, int len);

void newtestclass::testStringBuffer2() {
    char* ptr;
    int len;
    StringBuffer stringBuffer(ptr, len);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

char StringBuffer::charAt(int);

void newtestclass::testCharAt() {
    int p0;
    StringBuffer stringBuffer;
    char result = stringBuffer.charAt(p0);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

int StringBuffer::length();

void newtestclass::testLength() {
    StringBuffer stringBuffer;
    int result = stringBuffer.length();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void StringBuffer::reserve(int);

void newtestclass::testReserve() {
    int p0;
    StringBuffer stringBuffer;
    stringBuffer.reserve(p0);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void StringBuffer::append(char);

void newtestclass::testAppend() {
    char p0;
    StringBuffer stringBuffer;
    stringBuffer.append(p0);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

