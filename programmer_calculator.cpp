// programmer_calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <cmath> // For pow()
#include <limits> //for user error handeling std::numeric_limits
using namespace std;

int binaryToDecimal(string binary);
string decimalToBinary(int Decimal);
int hexToDecimal(string hex);

//programmer_calculator_project

// Tips for Getting Started: 
//This app does all operations on binary and output results in binary and decimal
//Negative binary outputs are representes by sign magnitude

int main()
{
    string condition = "n"; // app will quit when condition = y

    //starting the program
    cout << "\033[35m\n'This app was developed by AbdElrhman Mohamed; FCIS ASU'\033[0m\n\n";
    cout << "\033[36m10101010101010101010101010101010101010101010101\033[0m\n";
    cout << "01010101010 Programmer's Calculator 01010101010\n";
    cout << "\033[36m10101010101010101010101010101010101010101010101\033[0m\n\n";
    cout << "//Tips for Getting Started:\n";
    cout << "This app does all operations on binary and output results in binary and decimal\n";
    cout << "Negative binary outputs are representes by sign magnitude\n\n";

    do
    {
        //choosing a plan
        string plan;
        do
        {
            cout << "\033[36mPlease choose your plan:\n\033[0m";
            cout << "a(Binary to Decimal)\nb(Decimal to Binary)\nc(Operations on Binary)\nd(Hex to Decimal)\ne(Hex to Binary)\n";
            cin >> plan;
        } while (plan != "a" && plan != "A" && plan != "b" && plan != "B" && plan != "c" && plan != "C" && plan != "d" && plan != "D" && plan != "e" && plan != "E");
        cout << '\n';

        if (plan == "c" || plan == "C")
        {
            // getting the first input with handeling user errors
            bool input1_valid;
            string x;
            do {
                cout << "Please enter the first binary number: ";
                input1_valid = true;  // Assume input is valid initially
                cin >> x;

                // Check if the input contains only '0' or '1'
                for (char c : x) {
                    if (c != '0' && c != '1') {
                        input1_valid = false;
                        cout << "\033[35m\nA binary number consists of zeros and ones only, your input is not valid\033[0m\n";
                        break;  // Exit loop on the first invalid character
                    }
                }
            } while (!input1_valid);  // Repeat until the input is valid

            // getting the second input with handeling user errors
            bool input2_valid;
            string y;
            do {
                cout << "Please enter the second binary number: ";
                input2_valid = true;  // Assume input is valid initially
                cin >> y;

                // Check if the input contains only '0' or '1'
                for (char c : y) {
                    if (c != '0' && c != '1') {
                        input2_valid = false;
                        cout << "\033[35m\nA binary number consists of zeros and ones only, Your input is not valid\033[0m\n";
                        break;  // Exit loop on the first invalid character
                    }
                }
            } while (!input2_valid);  // Repeat until the input is valid


            // Convert binary number to decimal values
            int decimal1 = binaryToDecimal(x);
            int decimal2 = binaryToDecimal(y);

            // Ask the user about the operation to perform
            string operation; // Declare a char to hold the operation

            do {
                cout << "What operation do you need to perform: ";
                cin >> operation;

                // Ensure valid operations are entered
                if (operation != "+" && operation != "-" && operation != "*" && operation != "/")
                {
                    cout << "\033[35mPlease enter a valid operation!\033[0m" << endl;
                }
            } while (operation != "+" && operation != "-" && operation != "*" && operation != "/");

            cout << endl;

            // Perform the selected operation
            if (operation == "+")
            {
                int answer = decimal1 + decimal2;
                cout << "The result is: " << decimalToBinary(answer) << ", which is equivalent to: " << answer << " in decimal.\n";
            }
            else if (operation == "-")
            {
                if (decimal1 >= decimal2)
                {
                    int answer = decimal1 - decimal2;
                    cout << "The result is: " << decimalToBinary(answer) << ", which is equivalent to: " << answer << " in decimal.\n";
                }
                // 2's complement answers
                else if (decimal2 > decimal1) // Handle negative result in binary
                {
                    //i need to get the 2's of the second number then add it on the first one
                    int decimal_answer = decimal1 - decimal2;

                    int decimal_answer_for_binary = -1 * decimal_answer;
                    string binary_for_sign_magnitude = decimalToBinary(decimal_answer_for_binary);
                    string sign_magnitude_binary = "";
                    //put 1 for sign
                    sign_magnitude_binary += '1';
                    for (int i = 0; i < binary_for_sign_magnitude.length(); i++)
                    {
                        sign_magnitude_binary += binary_for_sign_magnitude[i];
                    }

                    //now i have the binary answer in sign magnitude recorded in sign_magnitude_binary
                    cout << "The result is: " << sign_magnitude_binary << ", which is equivalent to: " << decimal_answer << " in decimal.\n";
                    //cout << "Note: the previous answer was represented with sign magnitude!\n";
                    cout << "\033[35mNote: the previous answer was represented by sign magnitude!\033[0m\n";

                }//interior else if close

            }
            else if (operation == "*")
            {
                int answer = decimal1 * decimal2;
                cout << "The result is: " << decimalToBinary(answer) << ", which is equivalent to: " << answer << " in decimal.\n";
            }
            else if (operation == "/")
            {
                if (decimal2 != 0)
                {
                    int answer = decimal1 / decimal2;
                    cout << "The result is: " << decimalToBinary(answer) << ", which is equivalent to: " << answer << " in decimal.\n";
                }
                else
                {
                    cout << "\033[35mError: Division by zero is undefined.\033[0m" << endl;
                }
            }
        }
        else if (plan == "a" || plan == "A")
        {
            string binary;
            bool input_valid;

            // getting input with handeling users error
            do {
                cout << "Please enter a binary number: ";
                input_valid = true;  // Assume input is valid initially
                cin >> binary;

                // Check if the input contains only '0' or '1'
                for (char c : binary) {
                    if (c != '0' && c != '1') {
                        input_valid = false;
                        cout << "\033[35m\nA binary number consists of zeros and ones only, your input is not valid\033[0m\n";
                        break;  // Exit loop on the first invalid character
                    }
                }
            } while (!input_valid);  // Repeat until the input is valid
            cout << "The result is: " << binaryToDecimal(binary);
        }

        else if (plan == "b" || plan == "B")
        {
            cout << "Please enter the a decimal number: ";

            // check for user error first
            bool fail; // initialize error case = 0 (no error yet)
            fail = false;

            long long decimal;
            do
            {
                cin >> decimal;
                if (cin.fail())
                {
                    cin.clear(); // clear error case
                    cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // discard the invalid user input
                    fail = true; // set error value to true (error detected!)
                    cout << "\033[35mInvalid input! Please enter a valid integer:\033[0m ";
                }
                else {
                    fail = false;
                }
            } while (fail == true);
            cout << "The result is: " << decimalToBinary(decimal);
        }
        else if (plan == "d" || plan == "D")
        {
           // getting input and checking for user error of non-hex inputs
           int fail;
           string hex;
           do
           {
               fail = false;
               cout << "Please enter HexaDecimal number: ";
               cin >> hex;

               // checking user error
               for (char c : hex)
               {
                   std::string hexDigits = "0123456789ABCDEFabcdef";
                   if (hexDigits.find(c) == std::string::npos)
                   {
                       cout << "\033[35mInvalid hex value, HexaDecimal numbers containts only numbers from 0 to 9 and letters from A to F\033[0m\n";
                       fail = true;
                       break;
                   }
               }

           } while (fail == true);
           cout << "The result is: " << hexToDecimal(hex);
        }
        else if (plan == "e" || plan == "E")
        {
            //hex to binary
            // getting input and checking for user error of non-hex inputs
            int fail;
            string hex;
            do
            {
                fail = false;
                cout << "Please enter a HexaDecimal number: ";
                cin >> hex;

                // checking user error
                for (char c : hex)
                {
                    std::string hexDigits = "0123456789ABCDEFabcdef";
                    if (hexDigits.find(c) == std::string::npos)
                    {
                        cout << "\033[35mInvalid hex value, HexaDecimal numbers containts only numbers from 0 to 9 and letters from A to F\033[0m\n";
                        fail = true;
                        break;
                    }
                }

            } while (fail == true);
            // first i will convert hex to decimal then convert it to binary using my functions
            int decimal = hexToDecimal(hex);
            string binary = decimalToBinary(decimal);
            cout << "The answer is: " << binary;
        }
        else
        {
            return 1;
        }

        cout << "\n";
        cout << "Do you want to quit the program, (y/n)? ";
        cin >> condition;
        if (condition == "Y" || condition == "y")
        {
            //cout << "Program closed!\n";
            cout << "\033[35mProgram closed!\n\033[0m";
        }
        else if (condition != "Y" && condition != "y" && condition != "N" && condition != "n")
        {
            do
            {
                cout << "Please enter one of the two characters only (y, n): ";
                cin >> condition;
                if (condition == "Y" || condition == "y")
                {
                    cout << "Program closed!\n";
                }
            } while (condition != "Y" && condition != "y" && condition != "N" && condition != "n");
        }
        cout << '\n';

    } while (condition == "n" || condition == "N");

    return 0; // code excuted with no errors!
}

// Function to convert binary values to decimal
int binaryToDecimal(string binary)
{
    int Decimal = 0; // Accumulate the decimal value step by step
    for (int i = 0; i < binary.length(); i++)
    {
        if (binary[i] == '1')
        {
            // Calculate the power of 2 for the corresponding bit position
            int j = binary.length() - i - 1;
            Decimal += pow(2, j);
        }
    }
    return Decimal; // Return the converted value
}

// Function to convert the resulting decimal to binary
string decimalToBinary(int decimal) {
    if (decimal == 0) {
        return "0"; // Handle edge case for 0
    }
    string binary = ""; // Initialize binary string

    while (decimal > 0) {
        int remainder = decimal % 2; // Step 1: Get the remainder
        binary += to_string(remainder); // Append remainder as a string
        decimal = decimal / 2; // Divide by 2 for the next iteration
    }

    // Reverse the string to get the correct binary representation
    string rearranged_binary = "";
    for (int i = binary.length() - 1; i >= 0; i--) {
        rearranged_binary += binary[i]; // Append characters in reverse order
    }

    return rearranged_binary; // Return the rearranged binary string
}

//Function to convert the hex to decimal
int hexToDecimal(string hex) {
    if (hex == "0") {
        return 0;
    }

    int decimal = 0; // Accumulate the decimal value step by step
    for (int i = 0; i < hex.length(); i++) {
        int j = hex.length() - i - 1; // Position from right for power calculation

        if (hex[i] >= '0' && hex[i] <= '9') {
            // If it's a digit, subtract '0' to get its numerical value
            decimal += (pow(16, j) * (hex[i] - '0'));
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            // If it's an uppercase letter (A-F), subtract 'A' and add 10
            decimal += (pow(16, j) * (hex[i] - 'A' + 10));
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            // If it's a lowercase letter (a-f), subtract 'a' and add 10
            decimal += (pow(16, j) * (hex[i] - 'a' + 10));
        }
    }
    return decimal; // Return the converted value
}