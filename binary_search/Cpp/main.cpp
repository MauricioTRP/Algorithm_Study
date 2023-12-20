#include <iostream>
#include <algorithm>
#include "math.h"
#include <vector>

/**
 * This make use of math class and vector class
 * to write a basic binary search over numbers
*/

int binarySearch( std::vector<int> array,  int lookedElement )
{
    int low = 0;
    int high = array.size() - 1;

    while (low <= high)
    {
        int mid = floor((high + low)/2);

        int guess = array[mid];

        if (guess == lookedElement) return mid;

        if (guess > lookedElement) {
            high = mid - 1;
        } else
        {
            low = mid + 1;
        }
    }

    std::cout << "No está el elemento " << lookedElement << std::endl;
    return 0;
}

std::string print_array( std::vector<int> array )
{   
    std::string result = "[ ";
    for ( const auto element : array )
    {
        result += " " + std::to_string(element) + ",";
    }
    result +=  "]";
    return result;
}
int main()
{
    std::vector<int> sorted_list;
    std::string array_to_print;
    int random;

    for ( int counter = 0; counter < 10; counter++ )
    {
        random = rand() % 20;
        std::cout << "Elemento raandom " << random << std::endl;
        
        sorted_list.push_back( random );
    }

    std::sort(sorted_list.begin(), sorted_list.end());

    array_to_print = print_array(sorted_list);

    std::cout << "Arreglo definido " << std::endl;
    std::cout << array_to_print << std::endl;
    int pos = binarySearch( sorted_list, 5 );

    std::cout << "El elemento se encontró en la posición: " << pos << std::endl;

    return 0;
}