#include<iostream>

template<typename T>
class BinaryTree {
    public:
        T value;
        BinaryTree<T>* left;
        BinaryTree<T>* right;
 
    BinaryTree<T>(T value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }
 
    void add(T value) {
        if(left && value < left->value) {
            left->add(value);
        }
        else if(right && value > right->value) {
            right->add(value);
        }
        else {
            if(this->value < value) {
                if(left) left->add(this->value);
                else     left = new BinaryTree<T>(this->value);
            }
            else {
                if(right) right->add(this->value);
                else      right = new BinaryTree<T>(this->value);
            }
            this->value = value;
        }
    }
    
    bool find(T value, BinaryTree<T>* a) {
        if(value > this->value && right) {
            return right->find(value, a);
        }
        else if(value < this->value && left) {
            return left->find(value, a);
        }
        else {
            if(value == this->value) {
                *a = *this;
                return true;
            }
            else {
                return false;
            }
        }
    }
 
    void display() {
        display(0);
    }
 
    void display(int depth) {
        display_offset(depth);
        std::cout << value << "\n";
        if(right) {
            right->display(depth + 1);
        }
        if(left) {
            left->display(depth + 1);
        }
    }
 
 
    private: 
 
    void display_offset(int depth) {
        for(int i = 0; i < depth; i++) {
            std::cout << ' ';
        }
    }
};
 
int main() {
    BinaryTree<float> b = BinaryTree<float>(2.2);
    b.display();
    b.add(2.4);
    b.display();
    
    b.add(4.8);
    b.display();
    b.add(-2.2);
    b.display();
    BinaryTree<float>* f = new BinaryTree<float>(0.0);
    if(b.find(2.4, f)){f->display();}
    else{std::cout << "NULL\n";}
}

