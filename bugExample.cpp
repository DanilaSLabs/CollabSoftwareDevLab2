/** \file bugExample.cpp
 *  \brief     A little with logical bugs in it
 *  \details   This program is littered with logical bugs. Your task is the
 *              following:
 *                1) Compile and run the program.
 *                2) For each bug you find you must fix the bug then commit
 *                   the code with a comment on the fix you did
 *                3) There are a four functions that are not completed, you need to
 *                   complete them and also update the menu and the main function
 *  \author    Harald Gjermundrod
 *  \version   0.1
 *  \date      20/10/2025
 *  \bug       Many logical bugs
 *  \copyright University of Nicosia.
 */

#include <iostream>
#include <cassert>
using namespace std;

// Function prototypes
int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const int[], int[], const int);
void displayArray(const int[], const int);
int sumOddArray(const int[], const int);
bool isAllPositive(const int[], const int);
bool avgOddArray(const int[], const int, double&);
void revertNumbers(int arr[], const int size);

/**
 * <code>main</code> is the main function of this program.
 * <BR>
 * @return Returns 0 if success, any other value otherwise.
 */
int main() {
  int choice;
  const int SIZE = 10;

  // Initialize array price
  int price[SIZE] = {12, 4, 8, 1, 17, 2, 4, 2, 9, 1};
  // Declare array quantity and total
  int quantity[SIZE], total[SIZE];

  // Interactive menu
  do {
    choice = printMenu();

    switch (choice){
      // Enter quantity
      case 1:
        fillInArray(quantity, SIZE);
        break;
      // Calculate total
      case 2:
        multArrays(quantity, price, total, SIZE);
        break;
      // Print total
      case 3:
        displayArray(total, SIZE);
        break;
      case 4:
        if (isAllPositive(quantity, SIZE)){
          cout << "\nAll elements of array is positive.";
        } else {
          cout << "\nAt least one elements is not positive.";
        } 
        break;
      // Exit
      case 0:
        // No code needed
        break;
      default:
        assert(true);
    }
  } while (choice != 0);

  cout << "\nHave a nice day:)" << endl;
  return 0;
}

/**
 * <code>printMenu</code> shows a menu and accepts the choice
 * from the user which is returned.
 * <BR>
 * @return Returns the menu choice
 */
int printMenu(){
  int choice;

  do {
    cout << "\n == MENU ==";
    cout << "\n1) Enter quantity";
    cout << "\n2) Calculate total";
    cout << "\n3) Print total";
    cout << "\n4) All positive?";
    cout << "\n0) Exit";

    cout << "\nEnter the choice: ";
    cin >> choice;

    if (choice < 0 || choice > 4){
      cout << "\nWrong choice, try again.";
    }
  } while (choice < 0 || choice > 4);
  return choice;
}

/**
 * <code>fillInArray</code> is a function that will
 * fill in the elements of an array.
 * <BR>
 * @param arr The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size){
  assert (size > 1);

  for (int i = 0; i < size; ++i){
    cout << "\nEnter an element for the array at " << i << ": ";
    cin >> arr[i];
  }
}

/**
 * <code>multArrays</code> multiplies the value of elements of two source arrays
 * and stores the result in the destination array.
 * NOTE: precondition is that the arrays have the same size.
 * <BR>
 * @param arrQuantity The array containing the quantity values (source).
 * @param arrPrice The array containing the price values (source).
 * @param arrTotal The array where the result will be stored (destination).
 * @param size The size of the arrays. 
 */
void multArrays(const int arrQuantity[], const int arrPrice[], int arrTotal[], const int size){
  assert (size > 0);

  for (int i = 0; i < size; ++i){
    arrTotal[i] = arrQuantity[i] * arrPrice[i];
  }
}

/**
 * <code>displayArray</code> prints the value of each of the elements of the
 * array. In addition the function sums up the value of all the elements and
 * print the total.
 * <BR>
 * @param ar The array containing the values
 * @param size The size of the array.
 */
void displayArray(const int arr[], int size){
  int sum = 0;

  for (int i = 0; i < size; ++i){
    cout << "\nValue at " << i << ": " << arr[i];
    sum += arr[i];
  }

  cout << "\nThe total is: " << sum;
}

// Sums the odd numbers in the array and returns the result
int sumOddArray(const int arr[], const int size){
//@TODO: You will need to complete this. Including making the appropriate comment header
  return 0;
}

// If all the values in the array are positive return true
// Returns false for any element that is zero or negative
bool isAllPositive(const int arr[], const int size){
  bool res = true;
  for(int i = 0; i < size; i++){
    if (arr[i] <= 0){
      res = false;
      break;
    }
  }
  return res;
}

// Finds the average of all the odd numbers in the array and stores this in the last argument
// returns false if there are no odd numbers in the array, true otherwise.
bool avgOddArray(const int arr[], const int size, int& avgOdd){
  //@TODO: You will need to complete this. Including making the appropriate comment header
  return false;
}

// You revert the numbers (in place) of the array. I.e. if your array have the values [1, 3, 4, 7, 11] then
// after calling this function the values in the array should be [11, 7, 4, 3, 1]
void revertNumbers(int arr[], const int size) {
  //@TODO: You will need to complete this. Including making the appropriate comment header
}
