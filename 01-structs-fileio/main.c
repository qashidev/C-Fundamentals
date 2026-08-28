#include <stdio.h>
#include <string.h>
typedef struct User {
  char name[17];
  int age;}User;

void change(User *x){
  char n[17];printf("enter your name\n> ");
  fgets(n,sizeof(n),stdin);
  if (n[strlen(n)-1]=='\n'){
    n[strlen(n)-1]='\0';
  } strcpy(x->name,n);

  int a;printf("enter your age\n> ");
  scanf("%d",&a); x->age=a;
  int grb;
  while ((grb=getchar())!='\n' && grb!=EOF){}
}

void output(char fname[14],User *x){
  FILE *fp=fopen(fname,"w");
  if (fp==NULL){
    printf("cannot open the specified file\n"); return;
  } else { printf("%s is valid\n",fname); }
  fprintf(fp,"details: %s is %d years old\n",x->name,x->age);
  fclose(fp);
}

int main(void){
  char filename[14]; User person;char destbuf[100];
  printf("enter a file name\n> ");fgets(filename,sizeof(filename),stdin);
  if (filename[strlen(filename)-1]=='\n'){
    filename[strlen(filename)-1]='\0';
  }

  change(&person); output(filename,&person);
  FILE *fp = fopen(filename, "r");
  if (fp==NULL){
    printf("cannot open the specified file\n"); return 1;
   } fgets(destbuf,sizeof(destbuf),fp); fclose(fp);
  printf("%s\n",destbuf);
  return 0;
}
