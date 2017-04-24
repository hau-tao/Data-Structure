
#ifndef SET_H
#define SET_H

// Set.h - an implementation of Set using Node and Set_iterator

using namespace std;

template <class T> class Set;
template <class T> class Set_iterator;

template <class T>
class Node {
public:
	Node(): value(0), parent(0), leftChild(0), rightChild(0) { }
	Node(const T & x, Node * p, Node * lc, Node * rc):value(x), parent(p), leftChild(lc), rightChild(rc) { }
        // here copy constructor and assignment op don't make too much sense!
    Node(const Node & n): value(n.value), parent(0), leftChild(0), rightChild(0) { }
    Node & operator=(const Node & n) { value = n.value; return *this; }
	~Node() { delete leftChild; delete rightChild; } // this is very recursive, delete also calls the destructor of the object it is deleting
	void insert(Node<T> * newNode); // this is a helper func for Set::insert()
	Node * find(const T & x);
	Node * merge(Node<T> * left, Node<T> * right);
protected:
	T value;
	Node * parent;
	Node * leftChild;
	Node * rightChild;

friend class Set<T>;
friend class Set_iterator<T>;
};
template <class T>
void Node<T>::insert(Node<T> * newNode)
{
	if((newNode -> value) < value)
		if(leftChild)
			leftChild -> insert(newNode);
		else
		{
			newNode -> parent = this;
			leftChild = newNode;
		}

	else
		if(rightChild)
			rightChild -> insert(newNode);
		else
		{
			newNode -> parent = this;
			rightChild = newNode;
		}

}

template <class T>
Node<T> * Node<T>::find(const T & x)
{
	if(x == value)
		return this;
	
	if(x < value)
	{
		if( leftChild == 0)
			return 0;
		return leftChild -> find(x);
	}
	else{

		if( rightChild == 0)
			return 0;
		return rightChild -> find(x);

	}

}
template <class T>
Node<T> * Node<T>::merge(Node<T> * left, Node<T> * right)
{
	if(left == 0)
		return right;
	if(right == 0)
		return left;
	
	Node<T> * child = merge(left, right -> leftChild);

	child -> parent = right;
	right -> leftChild = child;

	return right;
			
}

template <class T>
class Set {
public:
	typedef Set_iterator<T> iterator;

	Set(): root(0), my_size(0) { }

	// the big three
	Set(const Set<T> & );
	~Set() { delete root; }
	Set operator=(const Set & );

	bool empty() const { return root == 0; }
	unsigned int size() const { return my_size; }
	//void insert(const T & x);
	iterator insert(const T & x); // return an iterator to x if it already exists, otherwise insert and return an iterator to x
	void erase(const iterator & it);
	void erase(const T & x) { root = remove(root, x); }
	unsigned int count(const T & x) const; // returns 1 or 0 because this is a set, not a multi-set
	iterator find(const T & x) const { return root -> find(x); }
	iterator begin() const; // for in-order traversal
	iterator end() const { return iterator(0); }
protected:
	Node<T> * root;
	unsigned int my_size;
	Node<T> * remove(Node<T> *, const T &);
};
template <class T>
Node<T> * Set<T>::remove(Node<T> * current, const T &testElement)
{
	if(current!=0){
		Node<T> *pa = current->parent;
		if(testElement < current->value)
			current->leftChild = remove(current->leftChild, testElement);
		else if(current ->value < testElement)
			current->rightChild = remove(current->rightChild, testElement);
		else 
		{
            Node<T> * result = current->merge(remove(current->leftChild, testElement), current->rightChild);
            current->leftChild = current->rightChild = 0;
            delete current;
            if (result)
                result->parent = pa;
            return result;
        }
	}
	return current;
}


template <class T>
Set<T>::Set(const Set<T> & op)
{
      root = 0;
      for (iterator i = op.begin(); i != op.end(); ++i)
              insert(*i);
}

template <class T>
Set<T> Set<T>::operator=(const Set<T> & op)
{
      delete root;
      root = 0;
      for (iterator i = op.begin(); i != op.end(); ++i)
              insert(*i);
      return *this;
}
template <class T>
typename Set<T>::iterator Set<T>::insert(const T & x)
{

	if( count(x))
		return 0; 
	
	Node<T> * newNode = new Node<T>(x,0,0,0);

	if(root == 0)
		root = newNode;
	else
		root -> insert(newNode);

	my_size++;
	return newNode;
}

template <class T>
void Set<T>::erase(const iterator & it)
{
	if (root != 0 and it != end()) {
		Node<T> * p = it.n;
		Node<T> * left = p ->leftChild;
		Node<T> * right = p -> rightChild;
		if (right != 0) {
			// left slide
			Node<T> * left_slide = right;
			while (left_slide -> leftChild)
				left_slide = left_slide -> leftChild;
			// connect the subtrees after left slide
			left_slide -> leftChild = left;
			if (left != 0)
				left -> parent = left_slide;
			// now connect right subtree to by pass p
			right -> parent = p -> parent;
			if (p -> parent)
				if (p -> parent -> leftChild == p)
					p -> parent -> leftChild = right;
				else p -> parent -> rightChild = right;
			else // p was root
				root = right;
		} else {
			if (left == 0) {
				if (p -> parent)
					if (p -> parent -> leftChild == p)
						p -> parent -> leftChild = 0;
					else p -> parent -> rightChild = 0;
				else // p was root
					root = 0; 
			} else {
				left -> parent = p -> parent;
				if (p -> parent)
					if (p -> parent -> leftChild == p)
						p -> parent -> leftChild = left;
					else p -> parent -> rightChild = left;
				else // p was root
					root = left;
			}
		}
		p -> leftChild = 0;
		p -> rightChild = 0;
		delete p;
		my_size--;
	}
}

template <class T>
unsigned int Set<T>::count(const T & element) const
{
	iterator it = begin();
    int count = 0;
    
    for( ; it != end();  it++){
        if(*it == element )
        {
        	++count;
            break;
        }
        count = 0;

    }
    return count;
}



template <class T>
typename Set<T>::iterator Set<T>::begin() const
{
	Node<T> * current = root;
	while (current && current -> leftChild)
		current = current -> leftChild;

	return iterator(current); 
}


// More code for Set goes here ...


template <class T>
class Set_iterator {
public:
	Set_iterator(): n(0) { }
	Set_iterator(Node<T> * newNode): n(newNode) { }

	bool operator==(Set_iterator it) const { return n == it.n; }
	bool operator!=(Set_iterator it) const { return n != it.n; }
	Set_iterator & operator++(); // inorder traversal, pre-increment
	Set_iterator operator++(int); // inorder traversal, post-increment
	T & operator*() { return n->value; }
	Set_iterator & operator=(Set_iterator<T> it) { n = it.n; return *this; }
protected:
	Node<T> * n;
friend class Set<T>;
};

// More code for Set_iterator goes here ...
template <class T>
Set_iterator<T> & Set_iterator<T>::operator++()
{
	if(n -> rightChild)
	{
		n = n -> rightChild;

		while( n -> leftChild)
			n = n -> leftChild;
	}
	else
	{
		Node<T> * child = n;
		n = n -> parent;
		
		while( n && n -> rightChild == child)
		 {
			 child = n;
			 n = n -> parent;
		 }
	}
	return *this;
}

template <class T>
Set_iterator<T> Set_iterator<T>::operator++(int)
{
	Set_iterator<T> clone(n);
	operator++();
	return clone;
}

#endif 

