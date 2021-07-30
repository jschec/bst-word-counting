/**
 * CountWords.cpp
 *
 * Entry point for program that uses the WordTree class (a binary 
 * search tree implementation) to count words and their frequencies
 * in the provided text.
 *
 * Joshua Scheck
 * 2020-12-07
 */

#include <iostream>
#include "WordTree.h"

/**
 * Entry point for this program.
 */ 
int main() {
   WordTree wordTree;
   std::cin >> wordTree;
   std::cout << wordTree;
   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << "total number of words in the text : " 
      << wordTree.numWords() << std::endl;
} // end CountWords.cpp