#include<iostream>
#include<vector>
#include<algorithm>

/**
 * Implementation of a QuickSort algorithm
*/

enum class comparisonOperator{ greater, smaller };

std::vector<int> filterArray(const std::vector<int>& unfilteredArray, int threshold, comparisonOperator greater_or_smaller_input ) {
    std::vector<int> filteredArray;

    std::copy_if(   unfilteredArray.begin(),
                    unfilteredArray.end(),
                    std::back_inserter(filteredArray),
                    [threshold, greater_or_smaller_input](int value) {
                        if ( greater_or_smaller_input == comparisonOperator::greater ) {
                            return value > threshold;
                        } else {
                            return value < threshold;
                        }
                    }
                );
    
    return filteredArray;
}

std::vector<int> quickSort( std::vector<int> unsortedVector ) {
    if ( unsortedVector.size() < 2 ) {
        return unsortedVector;
    } else {
        // partition array into, smaller than pivot, greater than pivot and pivot
        int pivot = unsortedVector[0];

        auto smaller = filterArray(unsortedVector, pivot, comparisonOperator::smaller);
        auto greater = filterArray(unsortedVector, pivot, comparisonOperator::greater);

        std::vector<int> sortedSmaller = quickSort(smaller); // recursion over smaller partitions
        std::vector<int> sortedGeater = quickSort(greater); // recursion over smaller partitions

        sortedSmaller.push_back(pivot);
        sortedSmaller.insert(sortedSmaller.end(), sortedGeater.begin(), sortedGeater.end());

        return sortedSmaller;
    }
    return std::vector<int> {1,2,3,4};
}


int main() {
    std::vector<int> unsortedVector = {1,15,2,64,13,4,12,6,14,23,16,31,43143,11};
    
    // print unsorted
    std::cout << std::endl << "Usorted" << std::endl;
    for ( const auto&  unsorted : unsortedVector ){
        std::cout << unsorted << " ";
    }
    
    std::vector<int> sortedVector = quickSort( unsortedVector );

    // print sorted
    std::cout << std::endl << "Sorted" << std::endl;
    for ( const auto&  sorted : sortedVector ){
        std::cout << sorted << " ";
    }



    

    return 0;
}