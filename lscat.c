#include <sys/types.h>


#include <dirent.h>

#include <stdio.h>

#include <stdlib.h>


#include <unistd.h>


#define BUFFSIZE 32768



int
main(int argc, char **argv) {
     char filename[80]; 
     char buf[BUFFSIZE];

     int n;
     int  name_length;

/*     *     *    *    given code    *    *    *    *     */
     while ((dirp = readdir(dp)) != NULL ){
           printf("%s\n", dirp->d_name);
           memset(filename, '\0', sizeof(filename));  
           strcpy(filename, dirp->d_name);
           printf(" ** %s ", filename);
           name_length = strlen(filename);
           printf(" name_length=%d \n", name_length);
/*     *     *    *    *   *    *    *    *    *    *     */

           if (strstr(filename,".c\0") != NULL){  //test for .c only at end, only print if found
	   	while ((n = read(filename, buf, BUFFSIZE)) > 0) {
  //simple-cat code except read from filename instead of stdin
			if (write(STDOUT_FILENO, buf, n) != n) {

				fprintf(stderr, "write error\n");

				exit(1);

			}
	   	}

     	  	if (n < 0) {

			fprintf(stderr, "read error\n");

			exit(1);

     	 	}
	   }
      }
     return(0);
}