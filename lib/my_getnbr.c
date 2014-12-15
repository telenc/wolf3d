/*
** my_getnbr.c for Jour_4 in /home/telenc_r//Piscine/Jour_04
** 
** Made by remi telenczak
** Login   <telenc_r@epitech.net>
** 
** Started on  Thu Oct  4 14:00:52 2012 remi telenczak
** Last update Wed Jan  9 08:41:46 2013 telenc_r
*/

void	affect_var(int *hav_s, int *fir, int *i, long *all)
{
  *hav_s = 1;
  *fir = 0;
  *i = 0;
  *all = 0;
}

void	affect_sig(int val, int *hav)
{
  if (val == '-')
    *hav *= -1;
  else if (va l == '+')
    *hav *= 1;
}

int	my_getnbr(char *str)
{
  int	number_char;
  int	i;
  long	all_num;
  int	first;
  int	have_signe;

  number_char = my_strlen(str);
  affect_var(&have_signe, &first, &i, &all_num);
  while (i < number_char)
    {
      if (str[i] >= 48 && str[i] <= 57 && (first==0 || first ==1))
	{
	  all_num = (all_num*10) + (str[i]-48);
	  first=1;
	}
      else if ((str[i] == '-' || str[i] == '+') && first==0)
	affect_sig(str[i], &have_signe);
      else if (first==1)
	first=2;
      i++;
    }
  if (all_num < 2147483648 && all_num > -2147483649 )
    return (all_num * have_signe);
  else
    return (0);
}
