#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main( int argc, char **argv)
{
  //variabile pentru parcurgere
  int i, j, t, d; 
  
  int len, N;
  int ***N_ap;
  float Info;
  float ***p;
  char *buffer;

  FILE *inFile, *outFile;

  // numele fisierului este specificat la rulare
  inFile = fopen( argv[1], "r");

  // determin lungimea fisierului
  fseek(inFile,0,SEEK_END);
  len = ftell(inFile);
  rewind(inFile);

  // aloc memorie pentru a incarca continutul in "buffer"
  if((buffer=malloc(len*sizeof(char)))==NULL) 
   {
       printf("Eroare alocare memorie\n");
       return(1);
   }

  // incarca fisierul in buffer
  fread(buffer, len, 1, inFile);

  fclose(inFile);

  // afisez codurile  ASCII ale primelor 10 combinatii de caractere din text
  for(i=0;i<30-1;i+=1)
   {
   	printf( "%i %i %i \n", *(buffer+i), *(buffer+i+1), *(buffer+i+2));
   }

  // array nr. de aparitii N_ap pentru fiecare caracter (coduri ASCII intre 0 si 127)
  N = 128;
  N_ap = (int***)malloc( N*sizeof(int**));  // nr. de aparatii
  p = (float***)malloc( N*sizeof(float**)); // probabilitatea de aparitie
  for(i=0;i<N;i++)
    {
        N_ap[i] = (int**)malloc(N*sizeof(int*));
        p[i] = (float**)malloc(N*sizeof(float*));
    	
	for(j=0;j<N;j++)
		{
		  N_ap[i][j] = (int*)malloc(N*sizeof(int));
        	  p[i][j] = (float*)malloc(N*sizeof(float));
		}
    }

  // initializare
  for (i=0;i<N;i++)
    {
       for (j=0;j<N;j++)
	  for (t=0;t<N;t++)
          	N_ap[i][j][t] = 0;
    }

  // incrementez nr de aparatii pentru fiecare caracter N_ap[i][j][t]
  for (i=0;i<len-2;i++) 
	{
	        j = *(buffer+i);
       		t = *(buffer+i+1);
		d = *(buffer+i+2);
       		N_ap[j][t][d] = N_ap[j][t][d] + 1;
  	}

  // calculez probabilitatea de aparitie a unui grup de 2 caractere = nr. aparitii / nr. total caractere
  for (i=0;i<N;i++)
    for (j=0;j<N;j++)
    	for (t=0;t<N;t++)
	{
       		p[i][j][t] = (float)N_ap[i][j][t] / (float)len;
       		if (p[i][j][t]!=0)
        		printf( "%i %i %i %f\n", i, j, t, p[i][j][t]);
    	}

  // Calculez Informatia (Entropia) Shannon
  Info = 0.;
  for (i=0;i<N;i++)
    for (j=0;j<N;j++)
	for (t=0;t<N;t++)
    	{
       		if (p[i][j][t]!=0.)
       		 {
           	  Info = Info - p[i][j][t]*log(p[i][j][t])/log(2.0);
       		 }
    	}

  // Afisez Informatia Shannon
  // Rezultatul reprezinta informatia medie masurata in bits pe care o
  // primesc cand aflu un caracter nou din text
  printf( "Info = %f \n", Info);

  free(buffer);
  
  for (i=0;i<N;i++)
      {
	for(j=0;j<N;j++)	
	{
		free(N_ap[i][j]);
		free(p[i][j]);
	}
       free(N_ap[i]);
       free(p[i]);
      }
  free(N_ap);
  free(p);

  return 0;

}



