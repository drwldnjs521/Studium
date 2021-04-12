/* bruch.c */
#include<stdio.h>
#include"bruch.h"

bruch product (bruch a, bruch b) {

	    bruch c; 
        c.zaehler = a.zaehler * b.zaehler;
        c.nenner = a.nenner * b.nenner; 
        return c; 
}

void set_nenner(bruch* a, int nenner) {
	 
	 if(nenner == 0)
		nenner = 1;
		
	 a->nenner = nenner;
	 
}

void print(bruch a) {
   
     printf("%lf \n", (double)a.zaehler/a.nenner);

}

