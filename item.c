typedef *char String;

typedef struct node{
  int sku;
  String product;
  float price;

  struct node *next
};
