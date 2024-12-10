#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

void listed(string name, int size, string food[], float price[]) {
    cout << "----------------------------------------------" << endl;
    cout << "\t\t    " << name << endl;
    cout << "----------------------------------------------" << endl;
    if (price == NULL) {
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". " << food[i] << endl;
        }
        cout << "----------------------------------------------" << endl;
    } else {
        cout << "FOOD\t\t\t\t         PRICE" << endl;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". " << food[i] << " --------------------------------$ " << price[i] << endl;
        }
        cout << "\n----------------------------------------------" << endl;
    }
}

void choiceSelection(int &select) {
    cout << "Enter your choice [1-4]: ";
    cin >> select;
    cout << "----------------------------------------------" << endl;
    system("cls");
}

void listedCart(string orderedFood[], int orderedFoodCount, float orderedPrice[]) {
    float total = 0.0;
    cout << "FOOD\t\t\t\t         PRICE" << endl;
    for (int i = 0; i < orderedFoodCount; i++) {
        cout << orderedFood[i] << " -----------------------------------$ " << orderedPrice[i] << endl;
        total += orderedPrice[i];
    }
    cout << "\n----------------------------------------------" << endl;
    cout << "TOTAL-----------------------------------$" << total << endl;
    cout << "----------------------------------------------" << endl;
}

void reciept(string orderedFood[], int orderedFoodCount, float orderedPrice[]) {
    float total = 0.0;
    cout << "----------------------------------------------" << endl;
    cout << "\t\tHIRO RESTO" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "FOOD\t\t\t\t         PRICE" << endl;
    for (int i = 0; i < orderedFoodCount; i++) {
        cout << orderedFood[i] << " -----------------------------------$" << orderedPrice[i] << endl;
        total += orderedPrice[i];
    }
    cout << "\n----------------------------------------------" << endl;
    cout << "TOTAL-----------------------------------$" << total << endl;
    cout << "----------------------------------------------" << endl;
}

int main() {
    int choice, order;
    string orderedFood[20];
    float orderedPrice[20];
    int orderedFoodCount = 0;
    char yesNo;
    char dineTake;
    string menu[5]{
        "Main",
        "Drinks",
        "Sides",
        "Desert"
    };
    string main[4]{
        "BURG",
        "PIZZ",
        "PAST",
        "SAND"
    };
    float mainPrices[4] = {5.99, 7.49, 6.29, 4.99};
    string drinks[4]{
        "COKE",
        "PEPS",
        "SPRT",
        "FANT"
    };
    float drinksPrices[4] = {1.99, 1.99, 2.49, 2.49};
    string sides[4]{
        "FRIE",
        "ONIO",
        "MOZZ",
        "GARB"
    };
    float sidesPrices[4] = {2.99, 3.49, 4.29, 3.99};
    string desert[4]{
        "ICRM",
        "CAKE",
        "DNTT",
        "PUDD"
    };
    float desertPrices[4] = {3.49, 3.99, 2.99, 4.29};

    cout << "----------------------------------------------" << endl;
    cout << "\t   Welcome to Hiro Resto" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "\n\n\nPress any key to continue the order...";
    getch();
    system("cls");
    do {
        listed("Menu", 4, menu, NULL);

        choiceSelection(choice);

        switch (choice) {
            case 1:
                listed("Main", 4, main, mainPrices);
                choiceSelection(order);
                orderedFood[orderedFoodCount] = main[order - 1];
                orderedPrice[orderedFoodCount++] = mainPrices[order - 1];
                break;
            case 2:
                listed("Drinks", 4, drinks, drinksPrices);
                choiceSelection(order);
                orderedFood[orderedFoodCount] = drinks[order - 1];
                orderedPrice[orderedFoodCount++] = drinksPrices[order - 1];
                break;
            case 3:
                listed("Sides", 4, sides, sidesPrices);
                choiceSelection(order);
                orderedFood[orderedFoodCount] = sides[order - 1];
                orderedPrice[orderedFoodCount++] = sidesPrices[order - 1];
                break;
            case 4:
                listed("Desert", 4, desert, desertPrices);
                choiceSelection(order);
                orderedFood[orderedFoodCount] = desert[order - 1];
                orderedPrice[orderedFoodCount++] = desertPrices[order - 1];
                break;
        }
        cout << "----------------------------------------------" << endl;
        cout << "\t     Successfully added" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Cart: \n" << endl;
        listedCart(orderedFood, orderedFoodCount, orderedPrice);

        cout << "\n\nDo you want to make another order [y/n]? ";
        cin >> yesNo;
        system("cls");
    } while (yesNo == 'y');

    cout << "----------------------------------------------" << endl;
    cout << "\t\t     To Pay" << endl;
    cout << "----------------------------------------------" << endl;
    listedCart(orderedFood, orderedFoodCount, orderedPrice);
    cout << "\n\nDine or Take out [d/t]: ";
    cin >> dineTake;
    system("cls");

    cout << "Please proceed to counter to pay your order" << endl;
    cout << "Paying order...";
    Sleep(5000);
    system("cls");
    cout << "Payment complete";
    getch();
    system("cls");

    reciept(orderedFood, orderedFoodCount, orderedPrice);

    return 0;
}