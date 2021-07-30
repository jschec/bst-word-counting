/**
 * Queue.h
 *
 * Declarations for the WordTree class and nested struct WordNode.
 * The WordTree class initializes as an empty binary search tree
 * ADT but can be populated with WordNodes that contain words as
 * their respective items. 
 *
 * Joshua Scheck
 * 2020-12-07
 */

#pragma once
#include <iostream>
#include <string>

class WordTree {

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
friend std::ostream& operator<<(std::ostream& output,
   WordTree wordTree);

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
friend std::istream& operator>>(std::istream& input,
   WordTree& wordTree);

public:

   /**
    * Default constructor for WordTree class, which initializes an 
    * empty WordTree
    */
   WordTree();

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
   ~WordTree();

   /**
    * Copy constructor for this WordTree class
    * 
    * Calls the private recursive helper method 
    * copyTree(WordNode* currNode) to leverage recursive pre-order 
    * traversals to deep copy individual WordNodes
    * 
    * @param   otherWordTree  reference to another WordTree object to 
    *                         be deep copied to this WordTree
    */ 
   WordTree(const WordTree& otherWordTree);

   /**
    * WordNode structure which represents nodes that compose this
    * WordTree
    */ 
   struct WordNode {
      
      /** Word stored in this WordNode */
      std::string item;
      /** Frequency, in which the stored word in this WordNode is
          * encountered */
      int count;
      /** reference in memory to the left WordNode for this 
       * WordNode */
      WordNode* left;
      /** reference in memory to the right WordNode for this 
       * WordNode */
      WordNode* right;
   };

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
   void add(std::string anEntry);

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
   int numWords() const;

private:
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
   WordNode* add(WordNode* currNode, std::string anEntry);

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
   void removeWord(WordNode* currNode);

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
   void printWords(WordNode* currNode, std::ostream& output);

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
   int numWords(WordNode* root) const;

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
   WordTree::WordNode* copyTree(WordNode* currNode) const;

   /** reference in memory to the root WordNode in this WordTree */
   WordNode* root;
};

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
std::ostream& operator<<(std::ostream& output, WordTree rhs);

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
std::istream& operator>>(std::istream& input, WordTree& wordTree);
// end WordTree.h