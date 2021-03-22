#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main( int argc, char **argv)
{
  int i, len, nrcuv=0, nrcuvdif=0, verif;

  float Info;
  float *p;
  char *buffer;
  char *copiebuffer;
  int *N_ap;
  char **vector_de_cuvinte;

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

  copiebuffer=malloc(len*sizeof(char));

  strcpy(copiebuffer,buffer);

  //pentru dimensiunea vectorului am decis sa folosesc produsul dintre numarul de caractere regasite in text pentru a cuprinde toate cuvintele
  vector_de_cuvinte=(char**)malloc(len*len*sizeof(char*));

  char* temp = strtok(copiebuffer," ");
  while (temp!=NULL)
    {
       verif=1;
       for(i=0;i<nrcuvdif;i++)
        {
           if(strcmp(temp,vector_de_cuvinte[i])==0)
                verif=0;
        }
       if(verif==1)
            vector_de_cuvinte[nrcuvdif++] = temp;
       nrcuv++;
       temp = strtok(NULL," ");
    }

  // array nr. de aparitii N_ap pentru fiecare caracter (coduri ASCII intre 0 si 127)
  N_ap = (int*)malloc(nrcuvdif*sizeof(int));
  p = (float*)malloc( nrcuvdif*sizeof(float)); // probabilitatea de aparitie

  //intializare
  for(i=0;i<nrcuvdif;i++)
    {
     N_ap[i]=0;
    }

  //incrementez nr de aparatii pentru fiecare cuvant N_ap[i]
  //pentru a incrementa numarul de aparatii vom cauta cuvintele in buffer
  char *part;
  for(i=0;i<nrcuvdif;i++)
    {
     strcpy(copiebuffer,buffer);
     part = strtok(copiebuffer," ");
     while (part != NULL)
        {
         if(strcmp(vector_de_cuvinte[i],part)==0)
            N_ap[i]++;
         part = strtok(NULL," ");
        }
    }
  // Am realizat calculul probabilitatii in doua moduri
  // calculez probabilitatea de aparitie a unui cuvant = nr. aparitii / nr. total de cuvinte
  for (i=0;i<nrcuvdif;i++)
    	{
       		p[i] = (float)N_ap[i] / (float)nrcuv;
       		if (p[i]!=0)
        		printf( "%s %f\n", vector_de_cuvinte[i], p[i]);
    	}
  // calculez probabilitatea de aparitie a unui cuvant = nr. aparitii / nr. total de caractere
  /*for (i=0;i<nrcuvdif;i++)
    	{
       		p[i] = (float)N_ap[i] / (float)len;
       		if (p[i]!=0)
        		printf( "%s %f\n", vector_de_cuvinte[i], p[i]);
	}*/
  // Calculez Informatia (Entropia) Shannon
  Info = 0.;
  for (i=0;i<nrcuvdif;i++)
    	{
       		if (p[i]!=0.)
       		 {
           	  Info = Info - p[i]*log(p[i])/log(2.0);
       		 }
    	}

  // Afisez Informatia Shannon
  // Rezultatul reprezinta informatia medie masurata in bits pe care o
  // primesc cand aflu un caracter nou din text
  printf( "Info = %f \n", Info);

  free(buffer);
  free(p);
  free(N_ap);
  free(copiebuffer);
  free(vector_de_cuvinte);
  free(temp);
  free(part);
  return 0;

}



