#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "------- DEFAULT CONSTRUCTOR -------" << std::endl;
    Bureaucrat test;
    std::cout << test << std::endl << std::endl;


    std::cout << std::endl << "------- NAME+GRADE CONSTRUCTOR -------" << std::endl;
    Bureaucrat bob("bob", 1);
    std::cout << bob << std::endl << std::endl;

    
    std::cout << std::endl << "------- EXCEPTION CATCH IN CONSTRUCTOR -------" << std::endl;
    Bureaucrat di("di", 333);
    std::cout << di << std::endl << std::endl;
    

    std::cout << std::endl << "------- DECREMENT MEMBER FUNCTION -------" << std::endl;
    try
    {
        di.decreaseGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << di << std::endl << std::endl;


    std::cout << std::endl << "------- INCREMENT MEMBER FUNCTION -------" << std::endl;
    try
    {
        bob.increaseGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << bob << std::endl << std::endl;

    return (0);
}