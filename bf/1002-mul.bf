[ This program adds two digits given by the user and prints the result.
]

>, >,				Get both user input in c1 and c2
<< 				Go back to c0

convert from ascii
+++++ +				Add 6 to c0 to make a loop that runs six times
[
 >----- ---			Reduce c1 by 8
 >----- ---			Reduce c2 by 8
 <<-				Decrease iteration
]

multiply
>[				while c1 is not null
 >[>+>+<<-]			while c2 is not null; Move data from c2 to c3 and c4
 >[<+>-]			while c3 is not null; Increase c2 by the number that's in c3
 <<-				Go back to c1 and decrease it
]

separate numbers
>[-]				clear c2
>+				increment c3
>>+++++ +++++			set c5 to 8
<				go back to c4
[
 - >-
 [>>>]+++++ +++++<<+
 [<<<]>>>>
]
<-
<+++++ +++++>>>[-<<<->>>]<<<


convert to ascii
<+++++ +
[
 >+++++ +++>
 [+++++ +++>]
 <[<]>-
]

print
>>[.<<]<[<<]>>.