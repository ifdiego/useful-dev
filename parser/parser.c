#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *file = fopen("ratings.csv", "r");
  if (!file) {
    fprintf(stderr, "cannot open csv file\n");
    return 1;
  }

  while (!feof(file)) {
    char player[30];
    char rating[5];
    char country[20];

    int items = fscanf(file, "%29[^,],%4[^,],%19[^,],\n",
        player, rating, country
    );

    if (items != 3)
      break;

    printf("%s, %s, %s\n", player, rating, country);
  }

  fclose(file);

  return 0;
}
