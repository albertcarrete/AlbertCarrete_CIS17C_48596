/* ========================================
 * File:   	LinkdList.h
 * Author: 	Albert Carrete
 * Date: 	October, 8th 2014
 
 * Notes: 	Built using Data Structures and 
 			Algorithms with Object-Oriented 
 			Design Patterns in C++
=========================================== */

#ifndef LNKDLST_H
#define	LNKDLST_H

template <class T>
 class LinkedList;

 template<class T>
 class ListElement{
 	T datum;
 	ListElement* next;

 	ListElement (T const&, ListElement*);

 public:
 		T const& Datum () const;
 		ListElement const* Next () const;

 		friend LinkedList<T>;
 };

template <class T>
 class LinkedList{
 	ListElement<T>* head;
 	ListElement<T>* tail;

 public:
 	LinkedList();
 	~LinkedList();

 	LinkedList (LinkedList const&);
 	LinkedList& operator = (LinkedList const&);

	ListElement<T> const* Head () const;
	ListElement<T> const* Tail () const;
	bool IsEmpty () const;
	T const& First () const;
	T const& Last() const;

	void Prepend (T const&);
	void Append (T const&);
	void Extract (T const&);
	void Purge();
	void InsertAfter (ListElement<T> const*, T const&);
	void InsertBefore (ListElement<T> const*, T const&);
 };

// Constructor
template <class T>
LinkedList<T>::LinkedList(): head(0),tail(0){}

/* ===============================================
Destructor and Purge Member Functions
 ================================================= */
template <class T>
void LinkedList<T>::Purge(){
	while(head != 0){
		ListElement<T>* const tmp = head;
		head = head->next;
		delete tmp;
	}
	tail = 0;
}
template <class T>
LinkedList<T>::~LinkedList(){
	Purge();
}
/* ===============================================
	List Elements
 ================================================= */
 template <class T>
 ListElement<T>::ListElement(
	T const& _datum, ListElement<T>* _next) :
 	datum (_datum), next (_next)
 	{}

template <class T>
 	T const& ListElement<T>::Datum() const
 	{return datum; }

template <class T>
ListElement<T> const* ListElement<T>::Next() const
{return next; }

/* ===============================================
	HEAD, TAIL, IS EMPTY - - ACCESSORS
 ================================================= */
template <class T>
ListElement<T> const* LinkedList<T>::Head () const
{ return head;}

template <class T>
ListElement<T> const* LinkedList<T>::Tail () const
{return tail;}

template <class T>
bool LinkedList<T>::IsEmpty () const
{return head == 0;}

/* ===============================================
	FIRST AND LAST FUNCTIONS
 ================================================= */
template <class T>
T const& LinkedList<T>::First () const{
	if (head == 0)
		throw domain_error ("list is empty");
	return head->datum;
}
template <class T>
T const& LinkedList<T>::Last () const{
	if (tail == 0){
		throw domain_error("list is empty");
	}
	return tail->datum;
}
/* ===============================================
	PREPEND FUNCTION
 ================================================= */
template <class T>
	void LinkedList<T>::Prepend (T const& item){
		ListElement<T>* const tmp = new ListElement<T>(item, head);
		if(head == 0){
			tail = tmp;
		}
		head = tmp;
	}
/* ===============================================
	APPEND FUNCTION
 ================================================= */
template <class T>
	void LinkedList<T>::Append (T const& item){
		ListElement<T>* const tmp = new ListElement<T> (item, 0);
		if(head == 0){
			head = tmp;
		}
		else{
			tail->next = tmp;
		}
		tail = tmp;
	}
template <class T>
	LinkedList<T>::LinkedList(LinkedList<T> const& linkedList) : head(0),tail(0)
	{
		ListElement<T> const* ptr;
		for(ptr = linkedList.head; ptr != 0; ptr = ptr->next){
			Append (ptr->datum);
		}
	}
template <class T>
	LinkedList<T>& LinkedList<T>::operator = (LinkedList<T> const& linkedList){
		if (&linkedList != this){
			Purge();
			ListElement<T> const* ptr;
			for(ptr = linkedList.head; ptr != 0; ptr = ptr->next){
				Append (ptr->datum);
			}
		}
		return *this;
	}
/* ===============================================
	EXTRACT FUNCTION
 ================================================= */
template <class T>
	void LinkedList<T>::Extract (T const& item){
		ListElement<T>* ptr = head;
		ListElement<T>* prevPtr = 0;
		while (ptr != 0 && ptr->datum != item){
			prevPtr = ptr;
			ptr = ptr->next;
		}
		if(ptr == 0){
			throw invalid_argument ("item not found");
		}
		if(ptr == head){
			head = ptr->next;
		}
		else{
			prevPtr->next = ptr->next;
		}
		if(ptr == tail){
			tail = prevPtr;
		}
		delete ptr;
	}
template <class T>
	void LinkedList<T>::InsertAfter(ListElement<T> const* arg, T const& item){
		ListElement<T>* ptr = const_cast<ListElement<T>*> (arg);
		if(ptr == 0){
			throw invalid_argument ("invalid position");
		}
		ListElement<T>* const tmp = new ListElement<T>(item, ptr->next);
		ptr->next = tmp;
		if(tail == ptr){
			tail = tmp;
		}
	}
template <class T>
	void LinkedList<T>::InsertBefore(ListElement<T> const* arg, T const& item){
		ListElement<T>* ptr = const_cast<ListElement<T>*> (arg);
		if(ptr == 0){
			throw invalid_argument ("invalid position");
		}
		ListElement<T>* const tmp = new ListElement<T> (item, ptr);
		if (head == ptr){
			head = tmp;
		}
		else{
			ListElement<T>* prevPtr = head;
			while(prevPtr != 0 && prevPtr->next != ptr){
				prevPtr = prevPtr->next;
			}
			if(prevPtr == 0){
				throw invalid_argument ("invalid position");
			}
			prevPtr->next = tmp;
		}
	}

 #endif	/* LNKDLST_H */

