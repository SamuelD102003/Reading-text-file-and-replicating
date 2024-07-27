#include <stdio.h>

int main(void) {
  FILE *fpt,*fpw;
  int account [8],i=0,j;
  char name [8][30];
  float balance [8];
  if ((fpt = fopen("data.txt","r"))==NULL)
  {
    printf("FILE NOT FOUND.");
  }
  else
  {
    while(!feof(fpt))
      {
        fscanf(fpt,"%d %s %f", &account[i],name[i],&balance[i]);
        i++;
      }
    fclose(fpt);
    fpw = fopen("newdata.txt","w");
    for(j=7;j>=0;j--)
      {
      printf("%d %s %.2f\n",account[j],name[j],balance[j]);
      fprintf(fpw,"%d %s %.2f\n",account[j],name[j],balance[j]);
      }
    fclose(fpw);
  }
  return 0;
}