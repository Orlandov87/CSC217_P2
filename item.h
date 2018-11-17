typedef *char String;

struct node{
  int sku;
  String product;
  float price;

  struct node *next
};
