#include <iostream>
#include <string>
#include "Automata.h"

int main()
{
    Automata testMachine;
    testMachine.on();
    testMachine.getMenu();   
    testMachine.coin(100);
    testMachine.choice(3);
}
