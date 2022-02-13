#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node* left;
  struct node* right;
};

struct node *insert_tree(struct node* root, int number) {
  if (root == NULL) {
    root = (struct node*)malloc(sizeof(struct node));
    root->value = number;
    root->left = NULL;
    root->right = NULL;
  } else if (number < root->value) {
    root->left = insert_tree(root->left, number);
  } else {
    root->right = insert_tree(root->right, number);
  }

  return root;
}

struct node* search_tree(struct node* root, int number) {
  if (root == NULL) return NULL;

  if (root->value > number) {
    return search_tree(root->left, number);
  }

  if (root->value < number) {
    return search_tree(root->right, number);
  }

  return root;
}

void print_in_order(struct node* root) {
  if (root != NULL) {
    print_in_order(root->left);
    printf("%d ", root->value);
    print_in_order(root->right);
  }
}

void print_pre_order(struct node* root) {
  if (root != NULL) {
    printf("%d ", root->value);
    print_pre_order(root->left);
    print_pre_order(root->right);
  }
}

void print_post_order(struct node* root) {
  if (root != NULL) {
    print_post_order(root->left);
    print_post_order(root->right);
    printf("%d ", root->value);
  }
}

int main(void) {
  int num;
  struct node* root = NULL;

  do {
    printf("Enter value: (negative integer to stop)\n");
    scanf("%d", &num);

    if (num >= 0) {
      root = insert_tree(root, num);
    }

  } while (num >= 0);

  printf("Printing in order:\n");
  print_in_order(root);

  printf("\nPrinting in preorder:\n");
  print_pre_order(root);

  printf("\nPrinting in postorder:\n");
  print_post_order(root);

  return 0;
}
