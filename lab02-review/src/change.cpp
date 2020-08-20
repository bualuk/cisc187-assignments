#include "change.h"

purchase_t buy_stuff () 
{
  purchase_t purchase;

  for (double price = 1; purchase.funds >= price; price += 1) 
  {
    purchase.funds -= price;
    purchase.items += 1;
  }

  return purchase;
}

