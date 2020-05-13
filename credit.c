#include <stdio.h>
#include <cs50.h>


long long numberofDigits(long long num);
void findCard(int x, int y, long long number);
int main(void)
{
    int sum = 0;
    long long number = get_long("Number: ");
    long long d = numberofDigits(number);
    int product[d]; //make an array called products with the same number of digits as the input
    long long newNum = number;
    for(int j=0; j<d; j++) //Create in array with all of the input numbers
    {
        product[j] = newNum%10;
        newNum /=10;//remove the last digit
    }
    for(int i =1; i<d; i+=2) //Run it one time for every digit, but skip every other digit
    {
        if((product[i]*2)>9)//If doubling make it two digits add each digit individually
        {
            int product1 = (product[i]*2)%10;
            int product2 = (product[i]*2)/10;
            sum = sum+product1+product2;
        }
        else
        {
        sum += product[i]*2; //Mulptiply every other digit by 2 and add them together
        }
    }
    int leftovers = 0;
    for (int q=0; q<d; q+=2)//Add up all the left over digits
    {
        leftovers+=product[q];
    }
    int digit = (int) sum + leftovers;//
    if(digit%10==0) //If the last digit of that = 0
    {
        findCard(product[d-1], product[d-2], number); //Find which card company it is
    }
    else //If it's not 0 it's not a valid card
    {
        printf("INVALID\n");
    }
}

void findCard(int x, int y, long long number)
{
        int d = numberofDigits(number);
        printf("number of digits: %i\n", d);
        if(x==5 && (y>=1 && y<=5) && d==16) //Mastercard
        {
            printf("MASTERCARD\n");
        }
        else if (x==3 && (y==4 || y==7) && d==15) //American Express
        {
            printf("AMEX\n");
        }
        else if(x==4 && (d==13 || d==16)) //VISA
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

}


long long numberofDigits(long long num)
{
    long long n=0;
    do
    {
        n++; //Add one digit
        num/=10; //Take a digit off n
    } while(num!=0); //Do it until there are no digits left
    return n;
}