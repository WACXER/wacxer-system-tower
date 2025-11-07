//Develop a custom iterator for a tree-based data structure 
//that support both pre-order and post-order traversal in C++

#include <stack>
#include <memory>

template<typename T> 
class TreeNode {
public:
    T data;
    std::unique_ptr<TreeNode> left, right;
    TreeNode(T val): data(val) {}
};

template<typename T, bool PreOrder>
class TreeIterator{
public:
    TreeIterator(TreeNode<T>* root) {
        if(root) stack_.push(root);
        if(preOrder) advancePreOrder();
        else advancePostOrder();
    }
    T& operator*() {return stack_.top()-> data;}
    TreeIterator& operator++() {
        stack_.pop();
        if (preOrder) advancePreOrder();
        else advancePostOrder();
        return *this;
    }
    bool operator != (const TreeIterator& other) {return !stack_.empty();}
private: 
    void advancePreOrder() {
        while (!stack_.empty()) {
            auto* node = stack_.top();
            if (node->right) stack_.push(node->right.get());
            if(node->left) stack_.push(node->left.get());
            return;
        }
    }

    void advancePostOrder() {
        while(!stack_.empty()) {
            if (!visited_.count(node)) {
                visited_.insert(node);
                if(node->right) stack_.push(node->right.get());
                if (node->left) stack_.push(node->left)
            }else { return;}
        }
    }
    std::stack<TreeNode<T>*> stack_;
    std::set<TreeNode<T>*> visited_;
}