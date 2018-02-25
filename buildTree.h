#ifndef BUILDTREE_H
#define BUILDTREE_H

#include <stdint.h>
#include "pqueue.h"
#include "binaryTree.h"
#include "frequencyAnalysis.h"

#define BRANCH_VALUE 120

struct label {
	uint8_t c;
	int frq;
};

/* Function qPriorityFunc
 * Input: two treeNode pointers to compare
 * Output: int signifying relation between the inspected values
 */
int qPriorityFunc(void *n0, void *n1);


/* Function createNodeArray
 * Input: array of int from frequencyAnalysis function in frequencyAnalysis.c
 * Output: array of pointers to created treeNodes
 */
treeNode **createNodeArray(int *iArr);
/* Function addLabels
 * Input: node created by joinSubTrees in binaryTrees.c
 * Output:
 * Creates a new label and sets the frequency value to the sum of its childrens'
 * frequency values 
 */
label *addedLabel(treeNode *n0, treeNode *n1);

/* Function buildQueue
 * Input: array of label pointers from createLabelArray
 * Output: priority queue with labels with frequency in rising order
 */
pqueue *buildQueue(treeNode **nArr);

/* Function buildHuffmanTree
 * Input: pqueue from buildQueue
 * Output: treeNode now root of huffman tree
 * Will go through newly created queue of nodes and join the two nodes with 
 * lowest frequency, and use addLabel to give the new created root node a 
 * label with frequency value set to the sum of child nodes using addLabel
 */
treeNode *buildHuffmanTree(int *iArr);

#endif