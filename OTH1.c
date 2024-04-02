#include <stdio.h>

struct Stone {
    char* alphabet;
    struct Stone* link;
};

void initialize(struct Stone* stone, char* letter) {
    stone->link = NULL;
    stone->alphabet = letter;
}

int main() {
    struct Stone stone1, stone2, stone3, stone4, stone5, stone6, stone7, stone8, stone9;

    initialize(&stone1, "F");
    initialize(&stone2, "M");
    initialize(&stone3, "A");
    initialize(&stone4, "I");
    initialize(&stone5, "K");
    initialize(&stone6, "T");
    initialize(&stone7, "N");
    initialize(&stone8, "O");
    initialize(&stone9, "R");

    stone3.link = &stone6;
    stone6.link = &stone9;
    stone9.link = &stone4;
    stone4.link = &stone7;
    stone7.link = &stone1;
    stone1.link = &stone8;
    stone8.link = &stone2;
    stone2.link = &stone5;
    stone5.link = &stone3;

    printf("%s", stone3.link->link->link->alphabet);
    printf("%s", stone3.link->link->link->link->alphabet);
    printf("%s", stone3.link->link->link->link->link->alphabet);
    printf("%s", stone3.link->link->link->link->link->link->alphabet);
    printf("%s", stone3.link->link->alphabet);
    printf("%s", stone3.link->link->link->link->link->link->link->alphabet);
    printf("%s", stone3.alphabet);
    printf("%s", stone3.link->alphabet);
    printf("%s", stone3.link->link->link->alphabet);
    printf("%s", stone3.link->link->link->link->link->link->link->link->alphabet);
    printf("%s", stone3.alphabet);

    printf("\n\nStack Visualization:\n");

    struct Stone* current = &stone3;

    return 0;
}
