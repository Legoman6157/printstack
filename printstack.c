#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int safechar(char c)
{
	  if (c >= 'a' && c <= 'z') return(c);
	    if (c >= 'A' && c <= 'Z') return(c);
	      if (c >= '0' && c <= '9') return(c);
	        if (c == ' ') return(c);
		  if (c == '.') return(c);
		    if (c == '-') return(c);
		      if (c == ',') return(c);
		        if (c == '(') return(c);
			  if (c == ')') return(c);
			    if (c == '[') return(c);
			      if (c == ']') return(c);
			        if (c == '{') return(c);
				  if (c == '}') return(c);
				    return '@';
}
int main(int argc, char **argv, char **envp)
{
	  char **s;
	    char *s2;
	      int i, top;

	        if (argc < 2) {
			    fprintf(stderr, "usage: printstack nentries (& other junk if you want)\n");
			        exit(1);
				  }

		  top = atoi(argv[1]);

		    printf("&s = 0x%x\n", &s);
		      printf("&s2= 0x%x\n", &s2);
		        printf("&i = 0x%x\n", &i);
			  printf("&top = 0x%x\n", &top);
			  printf("&main = 0x%x\n", &main);
			    printf("&argc = 0x%x\n", &argc);
			      printf("&argv = 0x%x\n", &argv);
			        printf("&envp = 0x%x\n", &envp);
				  printf("\n");

				    s = (char **) &s;
				      for (i = 0; i < top; i++) {
					          s++;
						      s2 = (char *) s;
						          printf("0x%x : %15d 0x%-8x %2c %2c %2c %2c\n", s, *s, *s, safechar(s2[0]), 
									                 safechar(s2[1]), safechar(s2[2]), safechar(s2[3]));
							    }
}
