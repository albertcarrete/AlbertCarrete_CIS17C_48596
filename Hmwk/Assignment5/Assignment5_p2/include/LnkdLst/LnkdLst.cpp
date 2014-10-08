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
	newNode->next = NULL;

	std::cout << "+ APPEND [" << num << "]" << std::endl;

	// If there are no new nodes in the list
	// make newNode the first node.

	if(!head){
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
void LnkdLst::prepend(int num){
	Node *newNode; // Holds the newly added value
	Node *movedNode; //Holds the moved head

	movedNode = head;
	// Allocate a new node and store num here
	newNode = new Node;
	newNode->data = num;
	std::cout << "+ PREPEND VALUE [" << num << "] "<< std::endl;
	newNode->next = movedNode;

	if(!head){
		std::cout << "Cannot prepend while only head exists" << std::endl;
	}
	else{
		head = newNode;
	}
}

void LnkdLst::first(){
	Node *nodePtr;
	nodePtr = head;
	std::cout << "> FIRST VALUE [" << nodePtr->data << "]"<<std::endl;

}
void LnkdLst::last(){
	Node *nodePtr;
	nodePtr = head;

	while(nodePtr->next){
		nodePtr = nodePtr->next;
	}
	std::cout << "> LAST VALUE [" << nodePtr->data << "]"<<std::endl;

}
void LnkdLst::insertBefore(int item,int num){
	
	std::cout << "+ INSERT [" << num << "] BEFORE [" << item << "]" << std::endl;
	
	Node *travelNode;	

	/* ===================
	=  Insertable Node 
	====================*/
	Node *newNode;
	newNode = new Node;
	newNode->data = num;

	travelNode = head;

	for(int i = 0; i < item-2; i++){
		travelNode = travelNode->next;
	}
	newNode->next = travelNode->next;
	travelNode->next = newNode;

}
void LnkdLst::insertAfter(int item,int num){
	std::cout << "+ INSERT [" << num << "] AFTER [" << item << "]" << std::endl;

	Node *travelNode;	

	/* ===================
	=  Insertable Node 
	====================*/
	Node *newNode;
	newNode = new Node;
	newNode->data = num;

	travelNode = head;

	for(int i = 0; i < item-1; i++){
		travelNode = travelNode->next;
	}
	newNode->next = travelNode->next;
	travelNode->next = newNode;
}

std::string LnkdLst::toString(){
	Node *nodePtrx;
	nodePtrx = head;

	bool loop = true;
	int counter = 1;
	std::string list = "";
	do{
		if(nodePtrx->next){
			std::cout << "[ NODE "  << counter <<" | " << nodePtrx->data << " ] " << std::endl;
			// list = list + nodePtrx->data;
			nodePtrx = nodePtrx->next;
		}
		else{
			std::cout << "[ NODE "  << counter <<" | " << nodePtrx->data << " ]" << std::endl;
			// list += nodePtrx->data;
			loop = false;
		}
		counter++;	
	}while(loop);
	
	return list;
}
