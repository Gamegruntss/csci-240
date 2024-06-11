#include <iostream>
#ifndef TEST_H
#define TEST_H

#define RED_ON "\033[1;31m"
#define GREEN_ON "\033[1;32m"
#define COLOR_OFF "\033[0m"



void testTrue(bool predicate, const std::string& msg)
{
if(predicate) std::cout << GREEN_ON << "PASS: " << msg << COLOR_OFF <<  std::endl;
else std::cout << RED_ON << "FAIL: " << msg << std::endl;
}
void testFalse(bool predicate, const std::string& msg)
{
testTrue(!predicate, msg);
}
void testPass(const std::string& msg)
{
std::cout << GREEN_ON << "PASS: " << msg << COLOR_OFF << std::endl;
}
void testFail(const std::string msg)
{
std::cout << RED_ON << "FAIL: " << msg << COLOR_OFF << std::endl;
}

#endif
