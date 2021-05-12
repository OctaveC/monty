[ This program adds two digits given by the user and prints the result.
]

,		Get Cell c0
> ,  		Get Cell c1

[ 		Start your loops with your cell pointer on the loop counter (c1 in our case)
	< +     Add 1 to c0
	> -     Subtract 1 from c1
]	  	End your loops with the cell pointer on the loop counter

<       	Go back to p1
------------------------------------------------ ; Subtract 48 (ie ASCII char code of '0')
.		Print p1
