#include <bits/stdc++.h>
using namespace std;

struct Node {
    int rating;
    string name;
    int hp;
    Node* left;
    Node* right;
    Node* parent;
    int size;

    Node(int r, string n, int h) {
        rating = r;
        name = n;
        hp = h;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        size = 1;
    }
};

class BST {
private:
    Node* root;
    void update_size(Node* node) {
        if (!node) {
            return;
        }
        node->size = 1;
        if (node->left) {
            node->size += node->left->size;
        }
        if (node->right) {
            node->size += node->right->size;
        }
    }
    void update_sizes_up(Node* node) {
        while (node) {
            update_size(node);
            node = node->parent;
        }
    }
    void transplant(Node* u, Node* v) {
        if (!u->parent) {
            root = v;
        } 
        else if (u == u->parent->left) {
            u->parent->left = v;
        } 
        else {
            u->parent->right = v;
        }
        if (v) {
            v->parent = u->parent;
        }
    }
    Node* minimum(Node* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
    Node* maximum(Node* node) {
        while (node->right) {
            node = node->right;
        }
        return node;
    }
    Node* successor(Node* node) {
        if (node->right) {
            return minimum(node->right);
        }
        Node* p = node->parent;
        while (p && node == p->right) {
            node = p;
            p = p->parent;
        }
        return p;
    }
    Node* predecessor(Node* node) {
        if (node->left) {
            return maximum(node->left);
        }
        Node* p = node->parent;
        while (p && node == p->left) {
            node = p;
            p = p->parent;
        }
        return p;
    }
    int get_rank(Node* node, int x) {
        if (!node) {
            return 0;
        }
        if (node->rating < x) {
            return 1 + (node->left ? node->left->size : 0) + get_rank(node->right, x);
        } else {
            return get_rank(node->left, x);
        }
    }
    Node* get_kth(Node* node, int k) {
        if (!node) {
            return nullptr;
        }
        int left_size = node->left ? node->left->size : 0;
        if (k == left_size + 1) {
            return node;
        }
        if (k <= left_size) {
            return get_kth(node->left, k);
        }
        return get_kth(node->right, k - left_size - 1);
    }
    void in_order_range(Node* node, int L, int R, vector<Node*>& res) {
        if (!node) {
            return;
        }
        if (node->rating >= L) {
            in_order_range(node->left, L, R, res);
        }
        if (node->rating >= L && node->rating <= R) {
            res.push_back(node);
        }
        if (node->rating <= R) {
            in_order_range(node->right, L, R, res);
        }
    }
    int get_height(Node* node) {
        if (!node) {
            return -1;
        }
        return 1 + max(get_height(node->left), get_height(node->right));
    }
    int get_leaves(Node* node) {
        if (!node) {
            return 0;
        }
        if (!node->left && !node->right) {
            return 1;
        }
        return get_leaves(node->left) + get_leaves(node->right);
    }
    int get_depth(Node* node) {
        int d = 0;
        while (node->parent) {
            d++;
            node = node->parent;
        }
        return d;
    }
    Node* lca(Node* a, Node* b) {
        int da = get_depth(a), db = get_depth(b);
        while (da > db) {
            a = a->parent;
            da--;
        }
        while (db > da) {
            b = b->parent;
            db--;
        }
        while (a != b) {
            a = a->parent;
            b = b->parent;
        }
        return a;
    }
public:
    BST() {
        root = nullptr;
    }
    Node* find(int rating) {
        Node* cur = root;
        while (cur) {
            if (cur->rating == rating) {
                return cur;
            }
            if (rating < cur->rating) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return nullptr;
    }
    bool insert(int rating, string name, int hp) {
        Node* newnode = new Node(rating, name, hp);
        if (!root) {
            root = newnode;
            return true;
        }
        Node* cur = root;
        Node* par = nullptr;
        while (cur) {
            par = cur;
            if (rating < cur->rating) {
                cur = cur->left;
            } else if (rating > cur->rating) {
                cur = cur->right;
            } else {
                delete newnode;
                return false;
            }
        }
        newnode->parent = par;
        if (rating < par->rating) {
            par->left = newnode;
        } else {
            par->right = newnode;
        }
        update_sizes_up(newnode);
        return true;
    }
    bool remove(int rating) {
        Node* node = find(rating);
        if (!node) {
            return false;
        }
        if (!node->left) {
            transplant(node, node->right);
            update_sizes_up(node->parent);
        } else if (!node->right) {
            transplant(node, node->left);
            update_sizes_up(node->parent);
        } else {
            Node* y = minimum(node->right);
            if (y->parent != node) {
                transplant(y, y->right);
                update_sizes_up(y);
                y->right = node->right;
                if (y->right) {
                    y->right->parent = y;
                }
                update_sizes_up(y);
            }
            transplant(node, y);
            update_sizes_up(y);
            y->left = node->left;
            if (y->left) {
                y->left->parent = y;
            }
            update_sizes_up(y);
        }
        delete node;
        return true;
    }
    void damage(int rating, int amount) {
        Node* node = find(rating);
        if (!node) {
            cout << "NOT FOUND" << endl;
            return;
        }
        if (node->hp - amount < 0) {
            node->hp = 0;
        } else {
            node->hp = node->hp - amount;
        }
        cout << "DAMAGED " << node->hp << endl;
    }
    void heal(int rating, int amount) {
        Node* node = find(rating);
        if (!node) {
            cout << "NOT FOUND" << endl;
            return;
        }
        node->hp += amount;
        cout << "HEALED " << node->hp << endl;
    }
    void match(int X) {
        if (!root) {
            cout << "EMPTY" << endl;
            return;
        }
        Node* cur = root;
        Node* pred = nullptr;
        Node* succ = nullptr;
        while (cur) {
            if (cur->rating < X) {
                pred = cur;
                cur = cur->right;
            } else {
                succ = cur;
                cur = cur->left;
            }
        }
        if (!pred && !succ) {
            cout << "EMPTY" << endl;
            return;
        }
        if (!pred) {
            cout << succ->rating << " " << succ->name << " " << succ->hp << endl;
            return;
        }
        if (!succ) {
            cout << pred->rating << " " << pred->name << " " << pred->hp << endl;
            return;
        }
        int d1 = X - pred->rating;
        int d2 = succ->rating - X;
        if (d1 <= d2) {
            cout << pred->rating << " " << pred->name << " " << pred->hp << endl;
        } else {
            cout << succ->rating << " " << succ->name << " " << succ->hp << endl;
        }
    }
    void next(int X) {
        Node* cur = root;
        Node* res = nullptr;
        while (cur) {
            if (cur->rating > X) {
                res = cur;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (!res) {
            cout << "NONE" << endl;
        } else {
            cout << res->rating << " " << res->name << " " << res->hp << endl;
        }
    }
    void prev(int X) {
        Node* cur = root;
        Node* res = nullptr;
        while (cur) {
            if (cur->rating < X) {
                res = cur;
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        if (!res) {
            cout << "NONE" << endl;
        } else {
            cout << res->rating << " " << res->name << " " << res->hp << endl;
        }
    }
    void range(int L, int R) {
        vector<Node*> res;
        in_order_range(root, L, R, res);
        if (res.empty()) {
            cout << "EMPTY" << endl;
        } else {
            for (size_t i = 0; i < res.size(); i++) {
                cout << res[i]->rating << " " << res[i]->name << " " << res[i]->hp << endl;
            }
        }
    }
    void rank(int X) {
        cout << get_rank(root, X) << endl;
    }
    void kth(int k) {
        Node* node = get_kth(root, k);
        if (!node) {
            cout << "OUT OF RANGE" << endl;
        } else {
            cout << node->rating << " " << node->name << " " << node->hp << endl;
        }
    }
    void duel(int A, int B) {
        Node* na = find(A);
        Node* nb = find(B);
        if (!na || !nb) {
            cout << "NOT FOUND" << endl;
            return;
        }
        if (na == nb) {
            cout << "DIST 0" << endl;
            return;
        }
        Node* l = lca(na, nb);
        int da = get_depth(na);
        int db = get_depth(nb);
        int dl = get_depth(l);
        int dist = da + db - 2 * dl;
        cout << "DIST " << dist << endl;
    }
    void stats() {
        int n = root ? root->size : 0;
        cout << "PLAYERS " << n << endl;
        if (!root) {
            cout << "MIN NONE" << endl;
            cout << "MAX NONE" << endl;
        } else {
            Node* minn = minimum(root);
            Node* maxx = maximum(root);
            cout << "MIN " << minn->rating << endl;
            cout << "MAX " << maxx->rating << endl;
        }
        cout << "HEIGHT " << get_height(root) << endl;
        cout << "LEAVES " << get_leaves(root) << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    BST bst;
    for (int i = 0; i < Q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "JOIN") {
            int rating, hp;
            string name;
            cin >> rating >> name >> hp;
            if (bst.insert(rating, name, hp)) {
                cout << "JOINED" << endl;
            } else {
                cout << "DUPLICATE" << endl;
            }
        } else if (cmd == "LEAVE") {
            int rating;
            cin >> rating;
            if (bst.remove(rating)) {
                cout << "LEFT" << endl;
            } else {
                cout << "NOT FOUND" << endl;
            }
        } else if (cmd == "STATUS") {
            int rating;
            cin >> rating;
            Node* node = bst.find(rating);
            if (node) {
                cout << node->rating << " " << node->name << " " << node->hp << endl;
            } else {
                cout << "NOT FOUND" << endl;
            }
        } else if (cmd == "DAMAGE") {
            int rating, amount;
            cin >> rating >> amount;
            bst.damage(rating, amount);
        } else if (cmd == "HEAL") {
            int rating, amount;
            cin >> rating >> amount;
            bst.heal(rating, amount);
        } else if (cmd == "MATCH") {
            int X;
            cin >> X;
            bst.match(X);
        } else if (cmd == "NEXT") {
            int X;
            cin >> X;
            bst.next(X);
        } else if (cmd == "PREV") {
            int X;
            cin >> X;
            bst.prev(X);
        } else if (cmd == "RANGE") {
            int L, R;
            cin >> L >> R;
            bst.range(L, R);
        } else if (cmd == "RANK") {
            int X;
            cin >> X;
            bst.rank(X);
        } else if (cmd == "KTH") {
            int k;
            cin >> k;
            bst.kth(k);
        } else if (cmd == "DUEL") {
            int A, B;
            cin >> A >> B;
            bst.duel(A, B);
        } else if (cmd == "STATS") {
            bst.stats();
        }
    }
    return 0;
}
