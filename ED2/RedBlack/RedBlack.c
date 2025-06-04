#include "RedBlack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Color:
// 0 - Black
// 1 - Red

RedBlack* RedBlack_createTree() {
    RedBlack* T = malloc(sizeof(RedBlack));
    T->nil = malloc(sizeof(Node));
    T->nil->color = 0;
    T->nil->left = T->nil;
    T->nil->right = T->nil;
    T->nil->p = T->nil;
    T->root = T->nil;
    return T;
}

Node* createNode(RedBlack* T, int key) {
    Node* node = malloc(sizeof(Node));
    if (node) {
        node->left = T->nil;
        node->right = T->nil;
        node->p = T->nil;
        node->color = 1;
        node->key = key;
    }
    return node;
}

void RedBlack_insert(RedBlack* T, int key) {
    Node* node = createNode(T, key);
    if (!node) {
        free(node);
        return;
    }

    Node* x = T->root, *y = T->nil;
    while (x != T->nil) {
        y = x;
        if (node->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }  
    node->p = y;

    if (y == T->nil) {
        T->root = node;
    } else if (node->key < y->key){
        y->left = node;
    } else {
        y->right = node;
    }
    node->left = T->nil;
    node->right = T->nil;
    node->color =  1; // Inserimos sempre vermelho para manter as propriedades da árvore da forma mais flexível e simples possível

    RedBlack_insertFixUp(T, node);
}

void RedBlack_insertFixUp(RedBlack* T, Node* z) {
    // Enquanto o pai de z for vermelho
    while (z->p->color == 1) {
        // Se o pai de z é filho à esquerda do avô
        if (z->p == z->p->p->left) {
            Node* y = z->p->p->right; // y é o tio de z (filho direito do avô)

            // Caso 1: o tio (y) é vermelho
            if (y->color == 1) { 
                // Recolorir o pai e o tio de preto
                z->p->color = 0; 
                y->color = 0;

                // Recolorir avô para vermelho
                z->p->p->color = 1;

                // Avança z para o avô (para continuar a verificação)
                z = z->p->p;
            } else { 
                // Caso 2: z é filho direito -> rotação para a esquerda
                if (z == z->p->right) {
                    z = z->p;
                    left_rotate(T, z);
                }

                // Caso 3: z é filho esquerdo -> rotação para a direita e recoloração
                z->p->color = 0; // Pinta o pai de preto
                z->p->p->color = 1; // Pinta o avô de vermelho
                right_rotate(T, z->p->p);
            }
        } else {
            // Mesmo que acima, mas simétrico (pai de z é filho à direita)
            Node* y = z->p->p->left;

            if (y->color == 1) {
                z->p->color = 0;
                y->color = 0;
                z->p->p->color = 1;
                z = z->p->p;
            } else {
                if (z == z->p->left) {
                    z = z->p;
                    right_rotate(T, z);
                }
                z->p->color = 0;
                z->p->p->color = 1;
                left_rotate(T, z->p->p);
            }
        }

        // Evita que z continue subindo além da raiz
        if (z == T->root)
            break;
    }

    // Garante que a raiz sempre seja preta
    T->root->color = 0;
}


void left_rotate(RedBlack* T, Node* x) {
    // y é o filho direito de x
    Node* y = x->right;

    // O filho esquerdo de y se torna o filho direito de x
    x->right = y->left;

    // Se o novo filho direito de x não é nil, atualiza o pai
    if (y->left != T->nil) {
        y->left->p = x;
    }

    // O pai de y passa a ser o pai de x 
    y->p = x->p;
    
    // Atualiza o pai de x para apontar para y
    if (x->p == T->nil) {
        T->root = y;
    } else if (x == x->p->left) {
        x->p->left = y;
    } else {
        x->p->right = y;
    }

    // x passa a ser o filho esquerdo de y
    y->left = x;
    x->p = y;
}

void right_rotate(RedBlack* T, Node* y) {
    // x é o filho esquerdo de y 
    Node* x = y->left;

    // O filho direito de x se torna o filho esquerdo de y
    y->left = x->right;

    // Se o novo filho direito de x for diferente de nil, atualiza o pai
    if (x->right != T->nil) {
        x->right->p = y;
    }

    // O pai de x passa a ser o pai de y
    x->p = y->p;

    // Atualiza o pai de y para apontar para x
    if (y->p == T->nil) {
        T->root = x;
    } else if (y == y->p->right) {
        y->p->right = x;
    } else {
        y->p->left = x;
    }

    // y passa a ser o filho direito de x
    x->right = y;
    y->p = x;
}

void RedBlack_pre(RedBlack* T, Node* root) {
    if (root != T->nil) {
        printf("%d  |  %d\n", root->key, root->color);
        RedBlack_pre(T, root->left);
        RedBlack_pre(T, root->right);
    }
}

void RedBlack_in(RedBlack* T, Node* root) {
    if (root != T->nil) {
        RedBlack_pre(T, root->left);
        printf("%d  |  %d\n", root->key, root->color);
        RedBlack_pre(T, root->right);
    }
}

int RedBlack_Height(RedBlack* T, Node* x) {
    if (x == T->nil || (x->left == T->nil && x->right == T->nil)) {
        return 0;
    }

    int hl = RedBlack_Height(T, x->left);
    int hr = RedBlack_Height(T, x->right);

    if (hl > hr) {
        return hl + 1;
    } else {
        return hr + 1;
    }
}

int RedBlack_height_start(RedBlack* T) {
    return RedBlack_Height(T, T->root);
}

Node* RedBlack_min(RedBlack* T, Node* x) {
    while (x->left != T->nil) {
        x = x->left;
    }
    return x;
}

void RedBlack_transplant(RedBlack* T, Node* u, Node* v) {
    if (u->p == T->nil) {
        T->root = v;
    } else if (u == u->p->left) {
        u->p->left = v;
    } else {
        u->p->right = v;
    }
    v->p = u->p;
}

void RedBlack_delete(RedBlack* T, Node* z) {
    Node* y = z, *x;
    int y_original_color = y->color;
    if (z->left == T->nil) {
        x = z->right;
        RedBlack_transplant(T, z, z->right);
    } else if (z->right == T->nil) {
        x = z->left;
        RedBlack_transplant(T, z, z->left);
    } else {
        y = RedBlack_min(T, z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->p != z) {
            RedBlack_transplant(T, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        RedBlack_transplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;
    }

    if (y_original_color == 0)
        RedBlack_delete_FixUp(T, x);
}

void RedBlack_delete_FixUp(RedBlack* T, Node* x) {
    Node* w;
    while (x != T->root && x->color == 0) {
        if (x == x->p->left) {
            w = x->p->right;

            if (w->color == 1) {
                w->color = 0;
                x->p->color = 1;
                left_rotate(T, x->p);
                w = x->p->right;
            }

            if (w->left->color == 0 && w->right->color == 0) {
                w->color = 1;
                x = x->p;
            } else {
                if (w->right->color == 0) {
                    w->left->color = 0;
                    w->color = 1;
                    right_rotate(T, w);
                    w = x->p->right;
                }
                w->color = x->p->color;
                x->p->color = 0;
                w->right->color = 0;
                left_rotate(T, x->p);
                x = T->root;
            }
        } else {
            w = x->p->left;

            if (w->color == 1) {
                w->color = 0;
                x->p->color = 1;
                right_rotate(T, x->p);
                w = x->p->left;
            }

            if (w->left->color == 0 && w->right->color == 0) {
                w->color = 1;
                x = x->p;
            } else {
                if (w->left->color == 0) {
                    w->right->color = 0;
                    w->color = 1;
                    left_rotate(T, w);
                    w = x->p->left;
                }
                w->color = x->p->color;
                x->p->color = 0;
                w->left->color = 0;
                right_rotate(T, x->p);
                x = T->root;
            }
        }
    }
    x->color = 0;
}