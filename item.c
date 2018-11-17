
typedef char* String;

struct node {
    int sku;
    String name;
    float price;

    struct node *left;
    struct node *right;
};
