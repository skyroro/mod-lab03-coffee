#include "Automata.h"

Automata::Automata() {
    state = OFF;
    cash = 0;
    linesInMenu = 5;
    menu = new std::string[linesInMenu] { "Espresso", "Americano", "Cappuccino", "Latte", "Cocoa" };
    prices = new double[linesInMenu] {50, 45, 60, 60, 40};
}

void Automata::on() {
    state = WAIT;
}

void Automata::off() {
    if (state == WAIT) state = OFF;
}

void Automata::coin(int sum) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += sum;
    }
}

void Automata::getMenu() {
    for (int i = 0; i < linesInMenu; i++) {
        std::cout << i + 1 << "  " << menu[i] << ": " << prices[i] << " \n";
    }
}

Automata::States Automata::getState() {
    return state;
}

void Automata::choice(int beverageNumber) {
    if (beverageNumber < 1 || beverageNumber > linesInMenu) {
        std::cout << "A non-existent drink has been selected";
        cancel();
    } else {
        std::cout << "Selected " << menu[beverageNumber] << " \n";
        state = CHECK;
        check(beverageNumber);
    }          
}

void Automata::check(int beverageNumber) {
    if (prices[beverageNumber - 1] > cash) {
        std::cout << "Not enough " << (prices[beverageNumber - 1] - cash) << " \n";
        cancel();
    } else {
        cook(beverageNumber);
    }
}

void Automata::cancel() {
    if (state == ACCEPT) state = WAIT;
    if (state == CHECK) state = WAIT;
}

void Automata::cook(int beverageNumber) {
    state = COOK;
    std::cout << "Thanks for the purchase! Prepare your " << menu[beverageNumber] << " \n";
    double change = cash - prices[beverageNumber - 1];
    finish(change);
}

void Automata::finish(double change) {
    state = WAIT;
    std::cout << "Your drink is ready! Delivery: " << change << "\n";
}
