/**
 * WordTreeTest.cpp
 *
 * Unit test file for WordTree class
 *
 * Joshua Scheck
 * 2020-12-07
 */

#include <iostream>
#include <cassert>
#include "WordTree.h"


/**
 * Tests WordTree constructor
 */ 
void testWordTreeConstructor() {
   WordTree testWordTree;
   assert(testWordTree.numWords() == 0);
}

/**
 * Tests WordTree add single node
 */ 
void testWordTreeAddSingleNode() {
   WordTree testWordTree;
   
   testWordTree.add("test");
   assert(testWordTree.numWords() == 1);
   
   testWordTree.add("test");
   assert(testWordTree.numWords() == 1);

   testWordTree.add("Test");
   assert(testWordTree.numWords() == 1);
   
   testWordTree.add("teSt");
   assert(testWordTree.numWords() == 1);
}

/**
 * Tests WordTree add multiple nodes
 */ 
void testWordTreeAddMultipleNode() {
   WordTree testWordTree;
   testWordTree.add("test");
   assert(testWordTree.numWords() == 1);

   testWordTree.add("another");
   assert(testWordTree.numWords() == 2);

   testWordTree.add("again");
   assert(testWordTree.numWords() == 3);

   testWordTree.add("another");
   assert(testWordTree.numWords() == 3);
}

/**
 * Tests WordTree output
 */
void testWordTreeOutput() {
   WordTree testWordTree;
   testWordTree.add("test");
   testWordTree.add("another");
   testWordTree.add("again");
   testWordTree.add("another");

   std::cout << testWordTree;
}

/**
 * Tests WordTree input
 */ 
void testWordTreeInput() {
   WordTree testWordTree;
   std::cin >> testWordTree;
}

/**
 * A single method with all of the tests used to assess structure
 * and feature requirements of Queue classes
 */ 
void runAllTests() {
   testWordTreeConstructor();
   testWordTreeAddSingleNode();
   testWordTreeAddMultipleNode();
   testWordTreeOutput();
   testWordTreeInput();
}

int main() {
   runAllTests();
} // end WordTreeTest.cpp