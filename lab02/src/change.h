#ifndef MESA_CISC187_LAB02_CHANGE_H
#define MESA_CISC187_LAB02_CHANGE_H

/**
 * A struct to hold the results of a purchase.
 * @funds the amount of money we hold
 * @items the number of items purchased
 */
struct purchase_t
{
  double funds = 1.00;
  int items = 0;
};

purchase_t buy_stuff();

#endif

