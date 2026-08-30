#include <stdio.h>
#include <string.h>

int main(void){
  char x[67]; FILE *fp=fopen("output.bin","wb")
  fgets(x,sizeof(x),stdin);
  if (fgets(x,sizeof x,stdin)!=NULL) {
        x[strcspn(x,"\n")]='\0';
    }
  fwrite(x,sizeof(char),strlen(x)-1,fp); //sizeof(char) -> 1; either one depending on arch
  fclose(fp);
}
