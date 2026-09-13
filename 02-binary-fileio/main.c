#include <stdio.h>
#include <string.h>

int main(void){
  char x[67]; FILE *fp=fopen("output.bin","wb");
  if (fgets(x,sizeof x,stdin)!=NULL) {
        x[strcspn(x,"\n")]='\0';
    }
  fwrite(x,sizeof(char),strlen(x),fp); //sizeof(char) -> 1; either one dependin>
  fclose(fp);

  fp=fopen("output.bin","rb"); unsigned char z;
  while (fread(&z,sizeof(char),1,fp)>0){
    printf("%d ",z);
  }printf("\n");
  fclose(fp);
}
