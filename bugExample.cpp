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
  double avgOdd = 0.0;

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
      case 5:
    cout << "\nThe sum of odd numbers is: "
         << sumOddArray(quantity, SIZE);
    break;

  case 6:
    if (avgOddArray(quantity, SIZE, avgOdd)){
      cout << "\nThe average of odd numbers is: " << avgOdd;
    } else {
      cout << "\nThere are no odd numbers in the array.";
    }
    break;

  case 7:
    revertNumbers(quantity, SIZE);
    cout << "\nThe quantity array has been reverted.";
    break;

  case 0:
    break;

  default:
    cout << "\nUnexpected error: invalid menu option.";
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
    cout << "\n5) Sum odd numbers";
    cout << "\n6) Average odd numbers";
    cout << "\n7) Revert quantity array";
    cout << "\n0) Exit";

    cout << "\nEnter the choice: ";
    cin >> choice;

    if (choice < 0 || choice > 7){
      cout << "\nWrong choice, try again.";
    }
  } while (choice < 0 || choice > 7);
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

/**
 * <code>sumOddArray</code> sums all the odd numbers in the array.
 * <BR>
 * @param arr The source array.
 * @param size The size of the array.
 * @return The sum of all odd numbers in the array.
 */
int sumOddArray(const int arr[], const int size){
  assert(size > 0);
  int sumOdd = 0;
  for(int i = 0; i < size; i++){
    if(arr[i] % 2 != 0){
      sumOdd += arr[i];
    }
  }
  return sumOdd;
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


/**
 * <code>avgOddArray</code> finds the average of all odd numbers in the array
 * and stores the result in the reference argument.
 * <BR>
 * @param arr The source array.
 * @param size The size of the array.
 * @param avgOdd The average of the odd numbers in the array.
 * @return Returns true if the array contains odd numbers, false otherwise.
 */
bool avgOddArray(const int arr[], const int size, double& avgOdd){
  assert(size > 0);
  int sumOdd = 0, countOdd = 0;
  for(int i = 0; i < size; i++){
    if(arr[i] % 2 != 0){
      sumOdd += arr[i];
    }
  }
  if(countOdd == 0){
    return false;
  }
  avgOdd = static_cast<double>(sumOdd)/countOdd;
  return true;
}

/**
 * <code>revertNumbers</code> reverses the elements of the array in place.
 * <BR>
 * @param arr The array to be reversed.
 * @param size The size of the array.
 */
void revertNumbers(int arr[], const int size) {
  assert(size > 0);

  for(int i = 0; i < size/2; i++){
    int temp = arr[i];
    arr[i] = arr[size-i-1];
    arr[size-i-1] = temp;
  }
}
