/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-dom1-details" } */
/* { dg-final { scan-tree-dump-times "FSM" 6 "dom1" } } */

int sum0, sum1, sum2, sum3;
int foo (char *s, char **ret)
{
  int state=0;
  char c;

  for (; *s && state != 4; s++)
    {
      c = *s;
      if (c == '*')
	{
	  s++;
	  break;
	}
      switch (state)
	{
	case 0:
	  if (c == '+')
	    state = 1;
	  else if (c != '-')
	    sum0+=c;
	  break;
	case 1:
	  if (c == '+')
	    state = 2;
	  else if (c == '-')
	    state = 0;
	  else
	    sum1+=c;
	  break;
	default:
	  break;
	}

    }
  *ret = s;
  return state;
}
