/**
 * Recursion is a function that calls itself to acomplish something
*/

#include <iostream>
void countdown( int starting_point )
{
    std::cout << "The current count is: " << std::to_string( starting_point ) << std::endl;

    if ( starting_point <= 0 ) 
    {
        return;
    } else
    {
        // Call the same function again with a decremented value of 'starting point'
        countdown( starting_point - 1 );
    }
}

int factorial_printed( int factorial )
{
    int value = 1;

    if ( factorial == 1 )
    {
        std::cout << "Current Value: " << std::to_string(value) << std::endl;
    } else
    {
        // Recursive Call
        value = factorial * factorial_printed( factorial - 1 );
        std::cout << "Current Value call: " << std::to_string(factorial) << std::endl;
    };
    return value;
}

int main()
{
    std::cout << "THIS IS A RECURSIVE COUNTDOWN from 10" << std::endl;

    countdown( 10 );
    std::cout << "THIS IS A RECURSIVE Factorial from 30" << std::endl;

    int value = factorial_printed( 30 );
    std::cout << "This is the result of the Factorial Function: " << std::to_string(value) << std::endl;
}