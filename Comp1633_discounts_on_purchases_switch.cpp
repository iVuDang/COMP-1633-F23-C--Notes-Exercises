#include <iostream>
using namespace std; 

/*
Write a function that calculates the amount to be paid by a customer that purchases 1, 2, 3 or more identical products. 

Today the store offers generous discounts as follows: buy one item and save 5%, 
buy two items and save 10%, 
byu three items and save 25%, 
by four or more and save 40% of the total price. 

Don’t forget to add the GST at the end. Make sure you use nested ifs for decisions.

*/


double calc_pay_amount(int num_products, double unit_price){

  const double GST = 0.05; 

  double discount = 0, total = 0; 

  switch(num_products){
    case 1: 
      discount = 0.05;
      break;

    case 2: 
      discount = 0.1; 
      break;

    case 3: 
      discount = 0.25;
      break; 

    default: 
      discount = 0.4; 
  }

  total = (num_products * unit_price) - (discount * num_products * unit_price) * (1 + GST); 

  return total; 
}


int main(){

  cout << calc_pay_amount(3, 10) << endl;  // 22.125

  return 0;

}
