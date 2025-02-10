#include <iostream>
#include <string>
//Ta dung ham de lam
std::string getNumberWord(int number) {
    if (number >= 11 && number <= 19) {
        switch (number) {
            case 11: return "eleven";
            case 12: return "twelve";
            case 13: return "thirteen";
            case 14: return "fourteen";
            case 15: return "fifteen";
            case 16: return "sixteen";
            case 17: return "seventeen";
            case 18: return "eighteen";
            case 19: return "nineteen";
        }
    } else {
        std::string tensWord = "";
        switch (number / 10) {
            case 2: tensWord = "twenty"; break;
            case 3: tensWord = "thirty"; break;
            case 4: tensWord = "forty"; break;
            case 5: tensWord = "fifty"; break;
            case 6: tensWord = "sixty"; break;
            case 7: tensWord = "seventy"; break;
            case 8: tensWord = "eighty"; break;
            case 9: tensWord = "ninety"; break;
        }

        std::string onesWord = "";
        switch (number % 10) {
            case 1: onesWord = "one"; break;
            case 2: onesWord = "two"; break;
            case 3: onesWord = "three"; break;
            case 4: onesWord = "four"; break;
            case 5: onesWord = "five"; break;
            case 6: onesWord = "six"; break;
            case 7: onesWord = "seven"; break;
            case 8: onesWord = "eight"; break;
            case 9: onesWord = "nine"; break;
        }

       return  tensWord + (onesWord.empty() ? "" : "-" + onesWord);
    }
}

int main() {
    int number;
    std::cout << "Enter a two-digit integer: ";
    std::cin >> number;

    std::cout << "The reading of " << number << " is " << getNumberWord(number) << std::endl;
    return 0;
}

