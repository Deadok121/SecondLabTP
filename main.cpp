#include <iostream>
#include "Stack.h"
#include "StackElement.h"
#include "Сoordinate.h"

using namespace std;

void firstTask();

void secondTask();

int main() {
    firstTask();
    secondTask();
    return 0;
}

void firstTask() {
    Coordinate coordinate;
    coordinate.display();
    coordinate++;
    coordinate.display();
    ++coordinate;
    coordinate.display();
    coordinate--;
    coordinate.display();
    --coordinate;
    coordinate.display();
    cout << endl << endl;
}

void secondTask() {
    cout << "Count first stack random elements: " << endl;
    int count;
    cin >> count;
    auto *first = new Stack(count);
    cout << "Count second stack random elements: " << endl;
    cin >> count;
    auto *second = new Stack(count);
    cout << "1.Display first stack" << endl;
    cout << "2.Display second stack" << endl;
    cout << "3.Compare two stacks" << endl;
    cout << "4.Peek first stack" << endl;
    cout << "5.Peek second stack" << endl;
    int choice;
    do {
        cout << "Enter your choice : " << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                first->display();
                break;
            case 2:
                second->display();
                break;
            case 3: {
                string result = (*first == *second) ? "equals" : "not equals";
                cout << "Compare : " << result;
                result = (*first != *second) ? "equals" : "not equals";
                cout << endl;
                cout << "Compare with negation :" << result;
                cout << endl;
            }
            case 4:
                cout << first->peek() << endl;
                break;
            case 5:
                cout << second->peek() << endl;
                break;
            default:
                break;
        }
    } while (choice != 6);
}
