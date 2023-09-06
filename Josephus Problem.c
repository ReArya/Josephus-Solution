#include <stdio.h>
#include <math.h>

int josephus(int input, int l)
{
	/* Inside this program the user should find the value recursively thus making an if else statement on whether or not
	   to recursively call the function again.
	   
	   After the first person is killed there is input - 1 people left. Recrusively call the function to get the
	   position of the next person killed but be aware that you are starting from the point of the next person of the 
	   person that was just killed. Do this until you recursively get down to only 1 person left which that position is your winner
	*/
	
    if (input == 1)
    {
        return 1;
	}
    else
    {
    	printf("%d   %d\n", input, l);
        return (josephus(input - 1, l) + l - 1) % input + 1;
    }
}

int main()
{
	/* Using the Formulas:
	   n = user input value	
	   m = highest number of the power of 2 without going over n
	   k = value needed to be added to equal n
	   w = winning number
	  
	   n = 2^m + k
	   w = 2 * k + 1 
	   
	*/
	
	int input;
	int value = 0;
	
	printf("The Josephus Problem is a Mathematical problem to determine which person stays alive and is the last \n"
	       "one remaining. Each person in a circle kills the person to their left starting with position 1.\n"
	       "This program is able to determine which position in the circle you must be to survive this dire task\n\n");
	
	printf("USING THE FORMULA\n\nPlease enter the amount of people in the circle: ");
	scanf("%i", &input);
	printf("\nThere was a total of %i people in the circle \n\n", input); 
	
	int i = 0;
	
	while (value <= input)
	{
		i++;
		value = pow(2.0, i);	
	}
	
	int k = input - pow(2.0, i - 1);
	
	int winner = 2 * k + 1; 
	
	printf("In order to be win the Josephus problem you must be in this position: %d", winner);
	
	/* Using Recursion
	   In order to use recursion there are two integer values that the student must get
	   the amount of people in the circle and how many people starting from 1 to kill a person
	   
	   HINT: the answer to this is two as it takes two places to kill a person as the first person is the one thats alive
	         and kills the 2nd person thus giving us the position 2 being the value to be sent to the recursion function
	
	*/
	
	printf("\n\nUSING RECURSION\n\nPlease enter the amount of people in the circle: ");
	scanf("%i", &input);
	printf("\nThere was a total of %i people in the circle \n\n", input); 
	
    int l = 2;
    
    printf("In order to be win the Josephus problem you must be in this position: %d", josephus(input, l));
	
	return 0;
}
