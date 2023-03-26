#pragma once
#include <iostream>
#include <string>

class Automata {
public:
    enum States { OFF, WAIT, ACCEPT, CHECK, COOK };
    States state;
    double cash;
    int linesInMenu;
    std::string* menu;
    double* prices;
public:
    Automata();
    void on();
    void off();
    void coin(int);
    void getMenu();
	States getState();
    void choice(int);
    void check(int);
    void cancel();
    void cook(int);
    void finish(double);
};
