// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(test1, testOn) {
  Automata testMachine;
  testMachine.on();
  EXPECT_EQ(testMachine.getState(), Automata::WAIT);
}

TEST(test2, testOff) {
  Automata testMachine;
  testMachine.on();
  testMachine.off();
  EXPECT_EQ(testMachine.getState(), Automata::OFF);
}

TEST(test3, testCoin) {
  Automata testMachine;
  testMachine.on();
  testMachine.coin(100);
  EXPECT_EQ(testMachine.getState(), Automata::ACCEPT);
}

TEST(test4, testChoice) {
  Automata testMachine;
  testMachine.on();
  testMachine.coin(100);
  testMachine.choice(3);
  EXPECT_EQ(testMachine.getState(), Automata::WAIT);
}

TEST(test5, testChoice2) {
  Automata testMachine;
  testMachine.on();
  testMachine.coin(20);
  testMachine.choice(4);
  EXPECT_EQ(testMachine.getState(), Automata::WAIT);
}

TEST(test6, testFinish) {
  Automata testMachine;
  testMachine.on();
  testMachine.coin(20);
  testMachine.finish(5);
  EXPECT_EQ(testMachine.getState(), Automata::WAIT);
}

TEST(test7, testCheck) {
  Automata testMachine;
  testMachine.on();
  testMachine.check(3);
  EXPECT_EQ(testMachine.getState(), Automata::WAIT);
}
