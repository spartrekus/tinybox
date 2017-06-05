

///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////
// TINYBOX
// Programme:   txls
// Description: list files/dir
// Author & origin: Spartrekus (BSD)
///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>


static int compare_fun( const void *p, const void *q)
{
  const char *l = p ; 
  const char *r = q ; 
  int cmp; 
  cmp = strcmp( l, r );
  return cmp; 
}


char *strrlf(char *str)
{    
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0; str[i]!='\0'; i++)
      {
        if (str[i] != '\n' && str[i] != '\n') 
        ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}



int fexist(char *a_option){
  char dir1[PATH_MAX]; 
  char *dir2;
  DIR *dip;
  strncpy( dir1 , "",  PATH_MAX  );
  strncpy( dir1 , a_option,  PATH_MAX  );

  struct stat st_buf; 
  int status; 
  int fileordir = 0 ; 

  status = stat ( dir1 , &st_buf);
  if (status != 0) {
    fileordir = 0;
  }

  // this is compatible to check if a file exists
  FILE *fp2check = fopen( dir1  ,"r");
  if( fp2check ) {
  // exists
  fileordir = 1; 
  fclose(fp2check);
  } 

  if (S_ISDIR (st_buf.st_mode)) {
    fileordir = 2; 
  }
return fileordir;
/////////////////////////////
}











int main()
{	

    int ch = 0; 
    int selection = 0; 
    int scrolly = 0; 

    char line[PATH_MAX];
    char cmdi[250];
    char filetarget[250];
    char idata[1240][250];

    char currentselection[PATH_MAX];
    strncpy( currentselection, "", PATH_MAX );

    unsigned filemax = 0;
    unsigned n=0;
    DIR *dirp;
    struct dirent *dp;






  void loaddir()
  {
    n = 0 ; 
    filemax = 0; 
    dirp = opendir( "." );
    while  ((dp = readdir( dirp )) != NULL  &&  
            n < sizeof idata / sizeof idata[ 0 ]) {
            if ( strcmp( dp->d_name , "." ) != 0 )
            if ( strcmp( dp->d_name , ".." ) != 0 )
            if ( dp->d_name[0] !=  '.' )
            {
              strncpy( idata[ n++ ] , dp->d_name , 250 );
            }
    }
    filemax = n-1 ; 
    closedir( dirp );

    if ( n > 1 )
      qsort( idata, n , sizeof idata[0], compare_fun );
  }





    loaddir();
    int posy=2;
    for( n = 0 ; n <= filemax ; n++)
    {
          printf( "%s\n", idata[ n ] );
    }


    return 0;
}





