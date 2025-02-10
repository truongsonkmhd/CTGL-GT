#include <iostream>
using namespace std;

int main() {
    char color;
    cout << "CHON MAU: ";
    cin >> color;
    
    switch (color) {
        case 'R':
        case 'r':
            cout << "RED" << endl;
            break;
        case 'G':
        case 'g':
            cout << "GREEN" << endl;
            break;
        case 'B':
        case 'b':
            cout << "BLUE" << endl;
            break;
        default:
            cout << "BLACK" << endl;
            break;
    }
    return 0;
}
