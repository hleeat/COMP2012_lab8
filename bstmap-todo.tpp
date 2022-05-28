//TODO: Return reference to value in this map corresponding to the provided key. 
//If the provided key does not exist, print an error message "Key is not in BSTMap" to std::cerr and terminate program using exit(-1).
// In practice, one should check if the map contains the key before calling this operator[]
template <typename K, typename V>
V& BSTMap<K, V>::operator[] (const K& k) {
	if (this->contains(k) == false)
	{
		std::cerr << "Key is not in BSTMap" << endl;
		exit(-1);
	}
	else {
		if(root == nullptr || root->data.key == k)
			return (root->data.value);

		// Key is greater than root's key
		if (root->data.key < k)
			return root->right.operator[](k);

		// Key is smaller than root's key
		return root->left.operator[](k);
	}
}


//TODO: Return value in this map corresponding to the provided key. 
//If the provided key does not exist, print an error message "Key is not in BSTMap" to std::cerr and terminate program using exit(-1).
// In practice, one should check if the map contains the key before calling this operator[]
template <typename K, typename V>
V BSTMap<K, V>::operator[](const K& k) const {
	if (this->contains(k) == false)
	{
		std::cerr << "Key is not in BSTMap" << endl;
		exit(-1);
	}
	else {
		if (root == nullptr || root->data.key == k)
			return root->data.value;

		// Key is greater than root's key
		if (root->data.key < k)
			return root->right.operator[](k);

		// Key is smaller than root's key
		return root->left.operator[](k);
	}

} 


//TODO: Assignment constructor, pay attention to memory leak
//Before doing assignment, you need to first check whether this != &bst, 
//if the two pointers are equal then you need to do nothing. 
//You also need to clear the original Map before doing assignment, we will check memory leak in this lab.
template <typename K, typename V>
BSTMap<K, V>& BSTMap<K, V>::operator=(const BSTMap& bst) {             
	if (this != &bst)
	{
		this->clear();
        this->root=new MapItem(*bst.root);
    }
    return *this;
}


//TODO: Return number of items in this map
template <typename K, typename V>
int BSTMap<K, V>::size() const {
	if (root == nullptr)
		return 0;
	else return (root->left.size() + 1 + root->right.size());
}


//TODO: Clear all items in BSTMap
template <typename K, typename V>
void BSTMap<K, V>::clear() {
	if(root==nullptr) return;
    root->left.clear();
    root->right.clear();
	delete root;
    root=nullptr;
}


//TODO: In-Order Traversal
template <typename K, typename V>
ostream &operator<<(ostream &os, const BSTMap<K, V> &bst)
{
    if (bst.root != nullptr)
    {
        operator<<(os, bst.root->left);
        if (bst.root->left.root != nullptr) os<<" , ";
        os << "{" << bst.root->data.key << ":" << bst.root->data.value << "}";
        if (bst.root->right.root != nullptr) os<<" , ";
        operator<<(os, bst.root->right);
       
    }
    return os;
}
