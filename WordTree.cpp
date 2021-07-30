/**
 * Queue.h
 *
 * Implementations for the WordTree class and nested struct WordNode.
 * The WordTree class initializes as an empty binary search tree
 * ADT but can be populated with WordNodes that contain words as
 * their respective items. 
 *
 * Joshua Scheck
 * 2020-12-07
 */

#include "WordTree.h"
#include <string>
#include <vector>

/**
 * Default constructor for WordTree class, which initializes an 
 * empty WordTree
 */
WordTree::WordTree() : root(nullptr) {}

/**
 * Destructor, which will to sequentially deallocate memory from
 * each WordNode existing in this WordTree. This destroys the 
 * object and frees up all the memory previously allocated by
 * this object. 
 * 
 * Calls the private recursive helper method 
 * removeWords(WordNode* root) to leverage recursive post-order
 * traversals to deallocate memory from each WordNode in this
 * WordTree
 */
WordTree::~WordTree() {
   removeWord(root);
   root = nullptr;
}

/**
 * Copy constructor for this WordTree class
 * 
 * Calls the private recursive helper method 
 * copyTree(WordNode* currNode) to leverage recursive pre-order 
 * traversals to deep copy individual WordNodes
 * 
 * @param   otherWordTree  reference to another WordTree object to 
 *                         be deep copied to this WordTree
 *
 */
WordTree::WordTree(const WordTree& otherWordTree) {
   if(otherWordTree.root == nullptr) {
      root = nullptr;
   }
   else {
      root = copyTree(otherWordTree.root);
   }
}

/**
 * Adds the provided word as a WordNode to this WordTree
 * 
 * Calls add(WordNode* root, std::string anEntry) method that
 * recursively adds words as WordNodes into this WordTree
 *
 * @pre              WordTree must be initialized, which will also
 *                   initialize class data member root
 *
 * @post             If anEntry does not exist in this WodTree, a 
 *                   new Node is added to this WordTree. If 
 *                   anEntry is already in this WordTree then the 
 *                   WordNode containing anEntry will have it's
 *                   count increase by 1.
 * 
 * @param   anEntry  word to add to this WordTree
 */
void WordTree::add(std::string anEntry) {
   // make string lower case
   for (int idx = 0; idx < anEntry.length(); idx++) {
      anEntry[idx] = std::tolower(anEntry[idx]);
   }

   root = add(root, anEntry);
}

/**
 * Retrieves the current number of WordNodes that exists in this
 * wordTree.
 * 
 * Calls the private recursive helper method 
 * numWords(WordNode* root) to leverage recursive pre-order 
 * traversals to count the total amount of WordNodes
 *
 * @pre     WordTree must be initialized with root WordNode
 *
 * @post    state of this WordTree does not change
 *
 * @return  total number of number of WordNodes
 */
int WordTree::numWords() const {
    return numWords(root);
}

/**
 * Private helper method that recursively checks anEntry against
 * item of the provided root and adds the anEntry accordingly.
 * 
 * @pre              WordTree must be initialized with root
 *                   WordNode
 * 
 * @post             Increments count of the provided WordNode
 *                   if that WordNode contains anEntry as its
 *                   item. Otherwise recursively adds to the 
 *                   left if less than the item or to the
 *                   right if more than the item.
 * 
 * @param   currNode Reference to the current WordNode
 * @param   anEntry  New word to compare against the item of
 *                   currNode
 * 
 * @return           Resulting current WordNode
 */
WordTree::WordNode* WordTree::add(WordNode* currNode, 
   std::string anEntry) {

   if (currNode == nullptr) {
      WordNode* currNode = new WordNode;
      currNode->item = anEntry;
      currNode->count = 1;
      currNode->left = nullptr;
      currNode->right = nullptr;
      return currNode;
   }

   std::string rootWord = currNode->item;

   if (rootWord.compare(anEntry) < 0) {
      currNode->right = add(currNode->right, anEntry);
   }
   else if (rootWord.compare(anEntry) > 0) {
      currNode->left = add(currNode->left, anEntry);
   } 
   else if (rootWord.compare(anEntry) == 0) {
      (currNode->count)++;
   }

   return currNode;
}

/**
 * Private helper method that leverages recursive post-order
 * traversals to remove WordNodes that exists in this WordTree.
 *
 * @pre              WordTree must be initialized with root
 *                   WordNode
 * 
 * @post             Recursively deallocates memory from the
 *                   left, right, or current WordNode
 * 
 * @param   currNode Reference to the current WordNode
 * 
 * @return           Resulting current WordNode
 */  
void WordTree::removeWord(WordNode* currNode) {
   if (currNode == nullptr) {
      return;
   }

   removeWord(currNode->left);
   removeWord(currNode->right);

   delete currNode;
   currNode = nullptr;
}

/**
 * Private helper method that leverages recursive in-order
 * traversals to print items and counts from the current
 * WordNode.
 *
 * @pre              WordTree must be initialized with root
 *                   WordNode
 * 
 * @post             Recursively prints out the values from
 *                   the referenced WordNode
 * 
 * @param   currNode Reference to the current WordNode
 * @param   output   Reference to output stream
 * 
 * @return           Resulting current WordNode
 */
void WordTree::printWords(WordNode* currNode, std::ostream& output) {
   if (currNode == nullptr) {
      return;
   }

   printWords(currNode->left, output);
   output << currNode->item << " " << currNode->count << "\n";
   printWords(currNode->right, output);
}

/**
 * Private helper method that leverages recursive pre-order
 * traversals to count WordNodes that are referenced from the
 * current WordNode.
 * 
 * @pre              WordTree must be initialized with root
 *                   WordNode
 * 
 * @post             Recursively counts referenced WordNodes
 *                   from the current WordNode. 
 * 
 * @param   currNode Reference to the current WordNode
 * 
 * @return           Current WordNode count
 */
int WordTree::numWords(WordNode* currNode) const {
   if (currNode == nullptr) {
      return 0;
   }

   int count = 1;

   count += numWords(currNode->left);
   count += numWords(currNode->right);

   return count;
}

/**
 * Private helper method that leverages recursive pre-order
 * traversals to deep copy WordNodes that are referenced from the
 * current WordNode.
 * 
 * @pre              WordTree must be initialized with root
 *                   WordNode
 * 
 * @post             Recursively creates new WordNodes with
 *                   deep copied values from the prior
 *                   WordTree
 * 
 * @param   currNode Reference to the current WordNode
 * 
 * @return           Current WordNode
 */
WordTree::WordNode* WordTree::copyTree(WordNode* currNode) const {
   if(currNode == nullptr) {
      return currNode;
   }

   WordNode* temp = new WordNode;
   temp->item = currNode->item;
   temp->count = currNode->count;
   temp->left = copyTree(currNode->left);
   temp->right = copyTree(currNode->right);
   return temp;
}

/**
 * Overloads the output stream operator for use with WordTree 
 * objects. Allows for outputting the values of this WordTree 
 * into the output stream.
 *
 * Calls the private recursive helper method 
 * printWords(WordNode* currNode, std::ostream& output) to
 * leverage recursive in-order traversals to print WordNode values
 * 
 * @pre              WordTree must be initialized with root WordNode
 *
 * @post             value of this WordTree is sent to output stream
 * 
 * @param   output   output to stream this WordTree to
 * 
 * @param   wordTree this WordTree object 
 *
 * @return           output stream
 */
std::ostream& operator<<(std::ostream& output, WordTree wordTree) {
   wordTree.printWords(wordTree.root, output);
   return output;
}

/**
 * Overloads the input stream operator for use with WordTree 
 * objects. Allows for input stream to stream words into this
 * WordTree. 
 *
 * @pre              WordTree must be initialized with root WordNode
 *
 * @post             Values from input stream are inputted into this
 *                   WordTree
 * 
 * @param   input    input to stream into this WordTree
 * 
 * @param   wordTree reference to this WordTree object 
 *
 * @return           input stream
 */
std::istream& operator>>(std::istream& input, WordTree& wordTree) {
   // skips any white space at the beginning of input stream
   input >> std::skipws;
   // vector containing chars that will be used as the word to
   // add to WordTree
   std::vector<char> wordVector;
   
   char currChar;
   while (input.get(currChar)) {

      // white space or a non single quotation mark special character
      // paired with a non empty char vector signals that a word
      // needs to be added
      if (wordVector.size() > 0 && (isspace(currChar) || 
         (!isalpha(currChar) && currChar !='\''))) {
         
         if (wordVector.size() > 1 && wordVector.back() =='\'') {
            wordVector.pop_back();
         }
         std::string word(wordVector.begin(), wordVector.end());
         wordTree.add(word);
         wordVector.clear();
      }
      // if word contains any numbers then assume its not a word and
      // clear whole character vector
      else if (isdigit(currChar)) {
         wordVector.clear();
      }
      // only add characters if alphabetical or if the current
      // character is an single quotation mark and is not the first
      // char in the word
      else if (isalpha(currChar) || (currChar =='\'' && 
         wordVector.size() > 0)) {
         wordVector.push_back(currChar);
      }
   }

   // add any left over words if any
   if (wordVector.size() > 0) {
      std::string word(wordVector.begin(), wordVector.end());
      wordTree.add(word);
      wordVector.clear();
   }

   return input;
} // end WordTree.cpp