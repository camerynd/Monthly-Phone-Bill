#include<iostream>
using namespace std;
//function prototypes
void display_menu(char&, int&);
void monthly_bill(char&, int&);
//main function
int main()
{
    //variables to be used in both functions
    char packagePurchased;
    int gigabytesUsed;
    //function calls
    display_menu(packagePurchased, gigabytesUsed);
    monthly_bill(packagePurchased, gigabytesUsed);
    return 0;
}
//function to display the menu
void display_menu(char& purchase, int& gigabytes)
{
    cout << "Data Plans" << endl;
    cout << "Package A: 4 gigabytes for $39.99/month." << endl;
    cout << "           Additional data $10/gigabyte." << endl;
    cout << "Package B: 8 gigabytes for $59.99/month." << endl;
    cout << "           Additional data $5/gigabyte." << endl;
    cout << "Package C: Unlimited data for $69.99/month." << endl;
    cout << "Which package did you purchase?: ";
    cin >> purchase;
    cout << "How many gigabytes did you use?: ";
    cin >> gigabytes;
    //input validation, user cannot enter negative numbers
    while (gigabytes < 0)
    {
        cout << "Error: positive values only. Try again: ";
        cin >> gigabytes;
    }
}
//function to determine monthly bill based on user input
void monthly_bill(char& purchase, int& gigabytes)
{
    //variables that are only used within the function
    double additionalData = 0,
           monthlyBill = 0;
    //switch to determine monthly bill depending on which package the user bought and how 
    //much data was used
    switch (purchase)
    {
        //if the user used more than the given amount of data, determine the cost of
        //the extra data
        case 'A': if (gigabytes > 4)
                  {
                      additionalData = 10 * (gigabytes - 4);
                      monthlyBill = additionalData + 39.99;
                      cout << "Your monthly bill is $" << monthlyBill << "." << endl;
                  }
        //if the user used the given amount of data or less, no additional fees apply
                  else
                  {
                      cout << "Your monthly bill is $39.99." << endl;
                  }
                  break;
        case 'B': if (gigabytes > 8)
                  {
                      additionalData = 5 * (gigabytes - 8);
                      monthlyBill = additionalData + 59.99;
                      cout << "Your monthly bill is $" << monthlyBill << "." << endl;
                  }
                  else
                  {
                      cout << "Your monthly bill is $59.99." << endl;
                  }
                  break;
        //package C will always be $69.99 bc unlimited data
        case 'C': cout << "Your monthly bill is $69.99." << endl;
                  break;
        //input validation, if A B or C was not entered, default case stating issue with the user's input
        default: cout << "You did not enter A, B, or C. Run program again" << endl;
                 cout << "and try using capital letters for your selection." << endl;
                 break;
    }
}