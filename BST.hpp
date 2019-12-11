    #ifndef BST_HPP
    #define BST_HPP

    #include <iostream>

    #include "BSTNode.hpp"

    template <class T>
    class BST {
    public: // DO NOT CHANGE THIS PART.
        BST();
        BST(const BST<T> &obj);

        ~BST();

        BSTNode<T> *getRoot();

        void insert(const T &data);
        void remove(const T &data);
        BSTNode<T> *find(const T &data);
        void printInorder();

        BST<T> &operator=(const BST<T> &rhs);

    private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
        void printInorder(BSTNode<T> *node);
        BSTNode<T> *findparent(const T &data);
        BSTNode<T> *getmin(BSTNode<T> *node);
        void makeEmpty(BSTNode<T>* &node);
        BSTNode<T> *copy(BSTNode<T> *node) const;

    private: // DO NOT CHANGE THIS PART.
        BSTNode<T> *root;
    };

    #endif //BST_HPP

    template <class T>
    BST<T>::BST() {
        root = NULL;
    }

    template <class T>
    BST<T>::BST(const BST<T> &obj) {
        root = NULL;
        *this = obj;
    }

    template <class T>
    BST<T>::~BST() {
    makeEmpty(root);
    root = NULL;
    }

    template <class T>
    BSTNode<T> *BST<T>::getRoot() {
        if(root == NULL){
            return NULL;
        }
        else{
            return root;
        }
    }

    template <class T>
    void BST<T>::insert(const T &data) {
        BSTNode<T> *newnode = new BSTNode<T>(data, NULL, NULL);
        if(root == NULL){
            root = newnode;
        }
        else{
            BSTNode<T> *current;
            BSTNode<T>* temp;
            current = root;
            temp = current;
            while(current!=NULL){
                if(data > current->data){
                    temp = current;
                    current = current->right;
                }
                else if(data < current->data){
                    temp = current;
                    current = current->left;
                }
            }
            if(data > temp->data){
                temp->right = newnode;
            }
            else{
                temp->left = newnode;
            }
        }
    }


    template <class T>
    void BST<T>::remove(const T &data) {
        BSTNode<T> *removenode;
        BSTNode<T> *parentnode;
        removenode = find(data);
        parentnode = findparent(data);

        if(parentnode!=removenode && removenode!= NULL){
            if(removenode->left == NULL && removenode->right == NULL){
                if(parentnode->data < removenode->data){
                    parentnode->right = NULL;
                    delete removenode;
                }
                else if(parentnode->data > removenode->data){
                    parentnode->left = NULL;
                    delete removenode;
                }
            }

            else if(removenode->left != NULL && removenode->right == NULL){
                if(parentnode->data < removenode->data){
                    parentnode->right = removenode->left;
                    delete removenode;
                }
                else if(parentnode->data > removenode->data){
                    parentnode->left = removenode->left;
                    delete removenode;
                }
            }

            else if(removenode->left == NULL && removenode->right != NULL){
                if(parentnode->data < removenode->data){
                    parentnode->right = removenode->right;
                    delete removenode;
                }
                else if(parentnode->data > removenode->data){
                    parentnode->left = removenode->right;
                    delete removenode;
                }
            }
            else if(removenode->left != NULL && removenode->right != NULL){
                BSTNode<T> *newroot = new BSTNode<T>();
                T x = getmin(removenode->right)->data;
                newroot->left = removenode->left;
                newroot->right = removenode->right;
                if(parentnode->data > data){
                    parentnode->left = newroot;
                }
                else if(parentnode->data < data){
                    parentnode->right = newroot;
                }
                remove(x);
                delete removenode;
                newroot->data = x;
            }
        }

        else if(parentnode == root && parentnode == removenode && removenode != NULL){
            if(removenode->left == NULL && removenode->right == NULL){
                delete removenode;
                root = NULL;
            }
            else if(removenode->left != NULL && removenode->right == NULL){
                root = removenode->left;
                delete removenode;
            }
            else if(removenode->left == NULL && removenode->right != NULL){
                root = removenode->right;
                delete removenode;
            }
            else if(removenode->left != NULL && removenode->right != NULL){
                BSTNode<T> *newroot = new BSTNode<T>();
                T x = getmin(removenode->right)->data;
                remove(x);
                newroot->right = root->right;
                newroot->left = root->left;
                delete removenode;
                newroot->data = x;
                root = newroot;
            }
        }

    }

    template <class T>
    BSTNode<T> *BST<T>::find(const T &data) {
        if(root == NULL){
            return NULL;
        }
        else{
            BSTNode<T> *current;
            current = root;
            while(current!=NULL){
                if(data > current->data){
                    current = current->right;
                }
                else if(data < current->data){
                    current = current->left;
                }
                else if(data == current->data){
                    return current;
                }
            }
            return NULL;
        }
    }


    template <class T>
    BSTNode<T> *BST<T>::findparent(const T &data) {
        if(root == NULL){
            return NULL;
        }
        else{
            BSTNode<T> *current;
            BSTNode<T>* temp;
            current = root;
            temp = current;
            while(current!=NULL){
                if(data > current->data){
                    temp = current;
                    current = current->right;
                }
                else if(data < current->data){
                    temp = current;
                    current = current->left;
                }
                else if(data == current->data){
                    return temp;
                }
            }
            if(current==NULL){
                return NULL;
            }
        }
        return NULL;
    }


    template <class T>
    void BST<T>::makeEmpty(BSTNode<T> * & node) {
        if(node!=NULL){
            makeEmpty(node->left);
            makeEmpty(node->right);
            delete node;
        }
        node = NULL;
    }


    template <class T>
    BSTNode<T> *BST<T>::getmin(BSTNode<T> *node) {
        if(node == NULL){
            return NULL;
        }
        else if(node->left == NULL){
            return node;
        }
        else{
            return getmin(node->left);
        }
        
    }

    template <class T>
    BSTNode<T> *BST<T>::copy(BSTNode<T> *node) const{
        if(node == NULL){
            return NULL;
        }
        return new BSTNode<T>(node->data, copy(node->left), copy(node->right));
    }

    template <class T>
    void BST<T>::printInorder() {

        if (root == NULL) {
            std::cout << "{}" << std::endl;
        } else {
            std::cout << "{" << std::endl;
            printInorder(root);
            std::cout << std::endl << "}" << std::endl;
        }
    }


    template <class T>
    void BST<T>::printInorder(BSTNode<T> *node) {

        if (node == NULL)
            return;

        printInorder(node->left);
        if (node->left) {
            std::cout << "," << std::endl;
        }
        std::cout << "\t" << node->data;
        if (node->right) {
            std::cout << "," << std::endl;
        }
        printInorder(node->right);
    }

    template <class T>
    BST<T> &BST<T>::operator=(const BST<T> &rhs) {
        if(this!=&rhs){
            makeEmpty(root);
            root = copy(rhs.root);
        }
        return *this;
    }
