

all:
	  gcc txmakec.c  -o txmakec 
	  gcc txclean.c  -o txclean 

clean:
	      echo txclean ; [ -f txclean ] && txclean 


