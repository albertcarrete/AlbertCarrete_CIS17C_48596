/* ===============================================
 * File:        LnkdLst.cpp
 * Developer:   Albert Carrete
 * Date:        September 23, 2014
 * ==============================================*/
#include "LnkdLst.h"

LnkdLst::LnkdLst(int s){
	head = NULL;
}
LnkdLst::~LnkdLst(){

}
void LnkdLst::append(int num){

	Node *newNode; // points to a new node
	Node *nodePtr; // Used to move through the list

	// Allocate a new node and store num here
	newNode = new Node;
	newNode->data = num;
	std::cout << "[Add Node] = " << num << std::endl;
	newNode->next = NULL;

	// If there are no new nodes in the list
	// make newNode the first node.

	if(!head){
		std::cout << "<First node!>" << std::endl;
		head = newNode;
	}
	else{ // Otherwise enter new node at end of the list
		// Initialize nodePtr at the head of list
		nodePtr = head;

		// Find the last node in the list
		while(nodePtr->next){
			nodePtr = nodePtr->next;
		}

		// Insert newNode as the last node
		nodePtr->next = newNode;
	}
}

std::string LnkdLst::toString(){
	Node *nodePtrx;
	nodePtrx = head;

	bool loop = true;
	int counter = 1;
	std::string list = "";
	do{
		if(nodePtrx->next){
			std::cout << "{NODE "  << counter <<"} = " << nodePtrx->data << std::endl;
			// list = list + nodePtrx->data;
			nodePtrx = nodePtrx->next;
		}
		else{
			std::cout << "{NODE "  << counter <<"} = " << nodePtrx->data << std::endl;
			// list += nodePtrx->data;
			loop = false;
		}
		counter++;	
	}while(loop);
	
	return list;
}
