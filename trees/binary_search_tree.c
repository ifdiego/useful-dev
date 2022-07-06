#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node* left;
  struct node* right;
};

struct node* insert(struct node* root, int number) {
  if (root == NULL) {
    root = (struct node*)malloc(sizeof(struct node));
    root->value = number;
    root->left = NULL;
    root->right = NULL;
  } else if (number < root->value) {
    root->left = insert(root->left, number);
  } else {
    root->right = insert(root->right, number);
  }

  return root;
}

struct node* search(struct node* root, int number) {
  if (root == NULL) return NULL;

  if (root->value > number) {
    return search(root->left, number);
  }

  if (root->value < number) {
    return search(root->right, number);
  }

  return root;
}

void inorder(struct node* root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
  }
}

void preorder(struct node* root) {
  if (root != NULL) {
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct node* root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
  }
}

struct node* minvalue(struct node* root) {
  if (root->left != NULL) {
    return minvalue(root->left);
  }

  return root;
}

struct node* maxvalue(struct node* root) {
  if (root->right != NULL) {
    return maxvalue(root->right);
  }

  return root;
}

struct node* delete(struct node* root, int number) {
  if (root == NULL) return root;

  if (number < root->value) {
    root->left = delete(root->left, number);
  } else if (number > root->value) {
    root->right = delete(root->right, number);
  } else {
    if (root->left == NULL) {
      struct node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node* temp = root->left;
      free(root);
      return temp;
    }

    struct node* temp = minvalue(root->right);
    root->value = temp->value;
    root->right = delete(root->right, temp->value);
  }

  return root;
}

int main(void) {
  int num;
  struct node* root = NULL;

  do {
    printf("enter a number (zero to stop): ");
    scanf("%d", &num);
    if (num != 0) {
      root = insert(root, num);
    }
  } while (num != 0);

  printf("printing in order: ");
  inorder(root);

  printf("\nprinting in preorder: ");
  preorder(root);

  printf("\nprinting in postorder: ");
  postorder(root);

  struct node* min = minvalue(root);
  struct node* max = maxvalue(root);
  printf("\nmin value: %d\n", min->value);
  printf("max value: %d\n", max->value);

  int exists;
  printf("enter a number to search: ");
  scanf("%d", &exists);
  if (search(root, exists)) {
    printf("%d exists in tree\n", exists);
  } else {
    printf("%d don't exist in tree\n", exists);
  }

  int remove;
  printf("enter a number to remove: ");
  scanf("%d", &remove);
  if (search(root, remove)) {
    root = delete(root, remove);
    printf("%d removed from tree\n", remove);

    printf("printing in order: ");
    inorder(root);

    printf("\nprinting in preorder: ");
    preorder(root);

    printf("\nprinting in postorder: ");
    postorder(root);
  } else {
    printf("%d not found\n", remove);
  }

  return 0;
}
