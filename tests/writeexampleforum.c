#include <locale.h>
#include <stdio.h>

char *ft_putnbr(int nb);
void ft_putchar(int nb);
int main(void)
{
//char *l = setlocale(LC_ALL,"en_US.UTF-8");  

//if  (l == NULL)  
//	    printf("Locale not set \n");  
//		else 
//		    printf("Locale set to%s\n", l);  
			ft_putnbr(printf("%lc", 945)); 

			return (0);
}
