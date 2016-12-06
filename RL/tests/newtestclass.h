/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.h
 * Author: Ali
 *
 * Created on 06-Dec-2016, 10:36:13
 */

#ifndef NEWTESTCLASS_H
#define NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testStringBuffer);
    CPPUNIT_TEST(testStringBuffer2);
    CPPUNIT_TEST(testCharAt);
    CPPUNIT_TEST(testLength);
    CPPUNIT_TEST(testReserve);
    CPPUNIT_TEST(testAppend);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testStringBuffer();
    void testStringBuffer2();
    void testCharAt();
    void testLength();
    void testReserve();
    void testAppend();

};

#endif /* NEWTESTCLASS_H */

