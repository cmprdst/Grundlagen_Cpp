#include "utils.hpp"

#include <iostream>
#include <limits>
#include <sstream>
#include <string>

/* todo:
 *      * read doubles from cin and put them into an array until something that
 *        is not a number is entered. (std::cin.fail() is true)
 *      * increase the array's size if necessary
 *      * reset cin (see clear() and ignore())
 *      * read in the same amount of integers
 *      * implement functions in utils.cpp
 *      * test given input with isPermutation() and isSorted()
 *      * clean up all dynamically allocated memory
 */

using namespace std;

double *twiceSize(double *doubleArray, const int length) {
    double *resized = new double[2 * length];
    for (int i = 0; i < length; i++) resized[i] = doubleArray[i];
    delete[] doubleArray;
    return resized;
}

int main(int, char**) {
    cout << "Please list double values! If you are done, end by typing something that is not a number!" << endl;

    double dInput = 0;
    int values = 0;
    double *doubles = new double[8];
    int length = 8;

    while (true) {
        cin >> dInput;
        if (cin.fail()) {
            cout << "Process was stopped due to input not being a (decimal) number!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), ' ');
            break;
        }
        if (values == length) {
            doubles = twiceSize(doubles, length);
            length *= 2;
        }
        doubles[values++] = dInput;
        printf("In total %d %s added to the double array.\n", values, values == 1 ? "value was" : "values were");
    }

    if (values == 0) {
        cout << "No double values were given. Program will exit prematurely!" << endl;
        delete[] doubles;
        return 0;
    }

    printf("Now input the same amount of indexes (in this case %d integer values) that could describe a new valid"
           " sequence (permutation) of the data!\n", values);

    int iInput = 0;
    int *indexes = new int[values];

    for (int i = 0; i < values;) {
        cin >> iInput;
        if (cin.fail()) {
            cout << "Please input an integer!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), ' ');
            continue;
        }
        indexes[i++] = iInput;
        if (i != values) printf("%d %s left.\n", values - i, values - i == 1 ? "value" : "values");
    }

    cout << "Testing if resulting index array functions as a permutation..." << endl;

    if (isPermutation(indexes, values)) cout << "... It does!" << endl;
    else {
        cout << "... It does not." << endl;
        delete[] doubles;
        delete[] indexes;
        return 0;
    }

    cout << "Testing if permutation results in double values being sorted in ascending order..." << endl;

    if (isSorted(doubles, values, indexes)) {
        cout << "... It does!" << endl;
        delete[] doubles;
        delete[] indexes;
        return 0;
    }

    cout << "...It does not." << endl;
    delete[] doubles;
    delete[] indexes;
    return 0;
}
