x is equal to y and z
// x == (y && z)


x is equal to at least one of y and z
// x == (y || z) 
// (x == y) || (x == z)


x is equal to at most one of y and z
x is equal to y or z but not both
// [(x == y) && ( x!= z)] || [(x!=y) && (x == z)]


40 < x <= 80
// ( 40 < x) && (x <= 80)

