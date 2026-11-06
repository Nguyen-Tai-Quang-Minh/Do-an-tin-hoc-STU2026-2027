#include "AVLTree.h"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    destroyTree(root);
}

void AVLTree::destroyTree(AVLNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

int AVLTree::height(AVLNode* node) {
    return node ? node->height : 0;
}

int AVLTree::getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode* AVLTree::RightRotate(AVLNode *node) {
    AVLNode* x = node->left;
    AVLNode* T2 = x->right;

    // Thực hiện xoay
    x->right = node;
    node->left = T2;

    // Cập nhật chiều cao
    node->height = max(height(node->left), height(node->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::LeftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Thực hiện xoay
    y->left = x;
    x->right = T2;

    // Cập nhật chiều cao
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode* AVLTree::insertNode(AVLNode* node, Sach Sach) {
    // 1. BST insertion thông thường
    if (!node) return new AVLNode(Sach);

    if (Sach.ISBN < node->Data.ISBN)
        node->left = insertNode(node->left, Sach);
    else if (Sach.ISBN > node->Data.ISBN)
        node->right = insertNode(node->right, Sach);
    else
        return node; // Không cho phép trùng ISBN

    // 2. Cập nhật chiều cao node hiện tại
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Kiểm tra cân bằng và xử lý 4 trường hợp (LL, RR, LR, RL)
    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && Sach.ISBN < node->left->Data.ISBN)
        return RightRotate(node);

    // Right Right
    if (balance < -1 && Sach.ISBN > node->right->Data.ISBN)
        return LeftRotate(node);

    // Left Right
    if (balance > 1 && Sach.ISBN > node->left->Data.ISBN) {
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }

    // Right Left
    if (balance < -1 && Sach.ISBN < node->right->Data.ISBN) {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
}

void AVLTree::insert(Sach Sach) {
    root = insertNode(root, Sach);
}

bool AVLTree::search(string ISBN) {
    return searchNode(root, ISBN) != nullptr;
}



// Tìm node có giá trị ISBN nhỏ nhất (dùng cho xóa node có 2 con)
AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// 2. CHỨC NĂNG XÓA SÁCH THEO ISBN
AVLNode* AVLTree::deleteNode(AVLNode* node, string isbn) {
    if (!node) return node;

    // Tìm kiếm node cần xóa theo BST
    if (isbn < node->Data.ISBN)
        node->left = deleteNode(node->left, isbn);
    else if (isbn > node->Data.ISBN)
        node->right = deleteNode(node->right, isbn);
    else {
        // Node có 0 hoặc 1 con
        if ((node->left == nullptr) || (node->right == nullptr)) {
            AVLNode* temp = node->left ? node->left : node->right;

            if (!temp) { // Không có con nào
                temp = node;
                node = nullptr;
            } else // Có 1 con
                *node = *temp; 

            delete temp;
        } else {
            // Node có 2 con: Lấy node nhỏ nhất ở cây con phải
            AVLNode* temp = minValueNode(node->right);

            // Chép dữ liệu sang
            node->Data = temp->Data;

            // Xóa node nhỏ nhất ở cây con phải
            node->right = deleteNode(node->right, temp->Data.ISBN);
        }
    }

    if (!node) return node;

    // Cập nhật chiều cao và cân bằng lại cây sau khi xóa
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Các trường hợp mất cân bằng khi xóa
    if (balance > 1 && getBalance(node->left) >= 0)
        return RightRotate(node);
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0)
        return LeftRotate(node);
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
}

bool AVLTree::xoa(string isbn) {
    if (!search(isbn)) return false;
    root = deleteNode(root, isbn);
    return true;
}

// 3. CHỨC NĂNG SỬA THÔNG TIN SÁCH
bool AVLTree::update(string& isbn, Sach& newInfo) {
    AVLNode* bookPtr = searchNode(root, isbn);
    if (!bookPtr) return false; // Không tìm thấy sách để sửa

    // Cập nhật các thông tin (giữ nguyên ISBN làm khóa chính)
    bookPtr->Data.ten = newInfo.ten;
    bookPtr->Data.tacgia = newInfo.tacgia;
    bookPtr->Data.namXB = newInfo.namXB;
    bookPtr->Data.soluong = newInfo.soluong;
    bookPtr->Data.theloai = newInfo.theloai;
    return true;
}




AVLNode* AVLTree::searchNode(AVLNode* node, string ISBN) {
    if (!node || node->Data.ISBN == ISBN) return node;
    if (ISBN < node->Data.ISBN) return searchNode(node->left, ISBN);
    return searchNode(node->right, ISBN);
}

void AVLTree::NLR(AVLNode* node) {
    if (node) {
        cout << "ISBN: " << node->Data.ISBN << " - Tên: " << node->Data.ten << endl;
        NLR(node->left);
        NLR(node->right);
    }
}

void AVLTree::xuatNLR() {
    NLR(root);
}

