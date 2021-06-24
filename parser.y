%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>

  #define ANSI_COLOR_RED		"\e[1;31m"
  #define ANSI_COLOR_GREEN	"\e[1;32m"
  #define ANSI_COLOR_CYAN		"\e[1;36m"
  #define ANSI_COLOR_RESET	"\x1b[0m"

  int yylex();
  void yyerror(char *);
  typedef struct Abstract_syntax_tree
  {
  	char *name;
      char *type;
      int isConstant ;
  	struct Abstract_syntax_tree *left;
  	struct Abstract_syntax_tree *right;
      char *var; 
  }node; 
  
  node* buildTree(char *,node *,node *);
  node* buildTree2(char *,node *,node * , char * , int);
  char * getType(char * token);
  void insert_line_ST(node * n );
  void printTree(node *);
  void print2DUtil( node *root, int space) ;

  #define COUNT 10 
  #define YYSTYPE char*
  int count = 0;
%}

%start S
%token   ID NUM WHILE INT CHAR FLOAT VOID MAINOP AUTO DO RETURN BREAK CONTINUE IF ELSE COUT STRING FOR ENDL CIN STRING_C CHAR_C FLOAT_C

%token T_inc T_dec T_ls T_le T_l T_ge T_g T_ee T_ne T_aa T_oo T_x T_me T_de T_re T_pe T_se T_lse T_rse T_ae T_xe T_oe T_a T_n T_s T_p T_m T_d T_r T_o T_e lcm gcd pow per fact
%left T_l T_g per gcd lcm fact pow
%left T_p T_s
%left T_m T_d


%%
S
      : START 
      ;

START
      : MAIN      
      ;

MAIN
      : VOID MAINOP BODY 
      | INT MAINOP BODY 
      ;

BODY
      : '{' C '}'
      ;

C
      : C statement ';' {printTree((node*)$2);}
      | statement ';' {printTree($1);}
      | C LOOPS {printTree($2);}
      | LOOPS {printTree($1);}
      | C ELF {if_else4();printTree($2);}
      | ELF {printTree($1);}

      ;

LOOPS
      : WHILE '(' {while1();} COND ')' {while2($4);} LOOPBODY {$$=buildTree("WHILE",$4,$7);while3();}
      | FOR '('  ASSIGN_EXPR {for1();} ';' COND {for2($6);} ';' statement {for4();} ')'  LOOPBODY {$$=buildTree("FOR",$6,$12); for3();} 
      | FOR '(' LIT  ',' LIT { for_new1($3 , $5);}  ',' EXP  {for_new2($3, $8);} ',' EXP ')' LOOPBODY {$$=buildTree("FOR",$7,$10); for_new3($3 ,$11); forhelp3();}
      ;
ELF 
      : EFCHILD { $$ = $1 ;}
      | ELF ELSE {if_else0();} EFCHILD { $$ = buildTree( "ELSE IF SEQ" , $1 , $4 );}
      | ELF ELSE {if_else0();} LOOPBODY { $$ = buildTree( "ELSE SEQ" , $1 ,buildTree("ELSE",NULL,$4)  ); if_else2();}
      ;
EFCHILD   
      : IF  '(' COND ')' {if_else1($3);} LOOPBODY { $$ =  buildTree("IF",$3,$6);if_else2();}
      ;

LOOPBODY
      : '{' LOOPC '}' {$$=$2;}
      | ';'           
      | statement ';' 
      | ' '
      ;


LOOPC
      : LOOPC statement ';' {$$=buildTree("SEQ",$1,$2);}
      | LOOPC LOOPS {$$=buildTree("SEQ",$1,$2);}
      | statement ';' {$$=$1;}
      | LOOPS {$$=$1;}
      | LOOPC ELF {if_else4();printTree($2);}
      | ELF {if_else4();printTree($1);}

      ;

statement
      : ASSIGN_EXPR {$$ = $1;}
      | EXP {$$=$1;}
      | PRINT {$$=buildTree("Print",NULL,NULL);}
      ;

COND
      : LIT RELOP LIT {search_id($1  , 0);  search_id($3  , 0);$$=buildTree($2,$1,$3); codegen($$,$1,$3,$2);}
      | LIT {$$=$1;}
      | LIT RELOP LIT bin_boolop LIT RELOP LIT {  search_id($1  , 0);  search_id($3  , 0);  search_id($5  , 0);  search_id($7  , 0); $$=buildTree($4, buildTree($2,$1,$3) , buildTree($6,$5,$7));}
      | un_boolop '(' LIT RELOP LIT ')'
      | un_boolop LIT RELOP LIT
      | LIT bin_boolop LIT
      | un_boolop '(' LIT ')'
      | un_boolop LIT
      ;

ASSIGN_EXPR
      : LIT T_e EXP {search_id($1  , 0); check_Type($1 , $3); insert_line_ST($1); add_value($1,$3); $$=buildTree("=",$1,$3);codegen_assign($$,$1,$3);}
      | TYPE LIT T_e EXP {search_id($2  , 1); insert_type_ST($2 , $1);  insert_line_ST($2); check_Type( $2 , $4); add_value($2,$4); $$=buildTree("=",$2,$4);codegen_assign($$,$2,$4);}
      ;

EXP
      : ADDSUB {$$=$1;}
      | EXP T_l EXP { $$=buildTree($2,$1,$3); codegen($$,$1,$3,$2);}
      | EXP T_g EXP {$$=buildTree($2,$1,$3);codegen($$,$1,$3,$2);}
      | LIT un_arop { search_id($1  , 0);  insert_line_ST($1); $$ = buildTree($2,$1,buildTree("1",0,0));codegen($$,$1,buildTree2("1",0,0 ,"INT" ,1),$2);codegen_assign($$,$1,$$);}
      | STRING_C { $$ = buildTree2((char *)yylval,0,0 , (char *)"STRING",1);}
      | EXP per EXP {search_id($1,0);search_id($3,0); $$ = buildTree("per" , $1 , $3); codegen_per($$,$1,$3,$2);}
      | EXP gcd EXP {search_id($1,0);search_id($3,0); $$ = buildTree("gcd" , $1 , $3); codegen_gcd($$,$1,$3,$2);}
      | EXP lcm EXP {search_id($1,0);search_id($3,0); $$ = buildTree("lcm" , $1 , $3); codegen_lcm($$,$1,$3,$2);}
      | EXP fact {search_id($1,0); $$ = buildTree("fact" , $1 , NULL); codegen_fact($$,$1,$2); }
      | EXP pow EXP {search_id($1,0);search_id($3,0); $$ = buildTree("pow" , $1 , $3); codegen_pow($$,$1,$3,$2);}
      ;
	  
ADDSUB
      : TERM {$$=$1;}
      | EXP T_p TERM {search_id($1,0);search_id($3,0);check_Type($1 , $3); $$=buildTree($2,$1,$3);codegen($$,$1,$3,"+");}
      | EXP T_s TERM {search_id($1,0);search_id($3,0);check_Type($1 , $3); $$=buildTree($2,$1,$3);codegen($$,$1,$3,"-");}
      ;

TERM
	: FACTOR {$$=$1; }
      | TERM T_m FACTOR {search_id($1,0);search_id($3,0); check_Type($1 , $3);  $$=buildTree($2,$1,$3 );codegen($$,$1,$3,"*");}
      | TERM T_d FACTOR {search_id($1,0);search_id($3,0); check_Type($1 , $3);  $$=buildTree($2,$1,$3);codegen($$,$1,$3,"/");}
      ;
      
FACTOR
      : LIT {$$=$1;}
      | '(' EXP ')' {$$ = $2;}
      ;

PRINT
      : COUT T_ls STRING_C 
      | COUT T_ls LIT 
      | COUT T_ls STRING_C T_ls ENDL 
      ;
LIT
      : ID {  $$ = buildTree2((char *)yylval,0,0 , getType($1)  , 0); }
      | NUM { $$ = buildTree2((char *)yylval,0,0 , (char *)"INT" ,1);}
      | FLOAT_C { $$ = buildTree2((char *)yylval,0,0 , (char *)"FLOAT",1);}
      | CHAR_C { $$ = buildTree2((char *)yylval,0,0 , (char *)"CHAR",1); }

      ;
TYPE
      : INT  {$$="INT";}
      | CHAR {$$="CHAR";}
      | FLOAT {$$="FLOAT";}
      | STRING { $$ = "STRING";}
      ;
RELOP
      : T_l { $$ = "<";}
      | T_g {  $$ =">" ;}
      | T_le { $$ ="<=";}
      | T_ge {  $$ =">="; }
      | T_ne {  $$ ="!=" ;}
      | T_ee {  $$ ="==";}
      ;
bin_boolop
      : T_aa  {  $$ ="&&";}
      | T_oo {  $$ ="||";}
      ;

un_arop
      : T_inc { $$ = "+";}
      | T_dec  { $$ = "-";} 
      ;

un_boolop 
      : T_n
      ;


%%

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
extern FILE *yyin;
extern int yylineno;
extern char *yytext;
void printST();
extern struct SymbolTable{
        char name[20];
        char class[20];
        char type[20];
        char value[100];
        int line;
        int var_size;
    }ST[1001];
int x = 0;
FILE *myfile;
int main(int argc,char *argv[])
{
  yyin = fopen(argv[1], "r");
  char * str = argv[1];
  char name[100] = "./icg/icg";
  name[9] = str[10];
  name[10] = '\0';
  char * filet = ".txt";
  strcat(name,filet);
  myfile=fopen(name,"w");
  yylineno=1;
  /*
  node *root,*temp;
  root = (node*)malloc(sizeof(node));
  temp = (node*)malloc(sizeof(node));
  */
  if(!yyparse())  //yyparse-> 0 if success
  {
    printf(ANSI_COLOR_CYAN "\n********************************************************************** \n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "                               Parsing Complete\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n********************************************************************** \n\n" ANSI_COLOR_RESET);
  }
  else
  {
    printf(ANSI_COLOR_CYAN "\n********************************************************************** \n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "                                 Parsing failed\n\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n********************************************************************** \n\n" ANSI_COLOR_RESET);
  }
  printST();
  fclose(myfile);
  fclose(yyin);
  return 0;
}

void printnode(char *op){
     // printf("\n\n");
     // printf("%s" , op);
     // printf("\n\n");
}

void printchild(node *n){
      
      printf("\n\n");
      printf("%s %s" , n->name , n->var);
      printf("\n\n");
}

node* buildTree2(char *op,node *left,node *right , char *type ,int isConstant)
{
	node *new = (node*)malloc(sizeof(node));
	char *newstr = (char *)malloc(sizeof(char)*100+1);
      char *var_str = (char *)malloc(sizeof(char)*100+1);
	strcpy(newstr,op);
	
      char *typestr = (char *)malloc(strlen(type)+1);
	strcpy(typestr,type);

      new->left=left;
	new->right=right;
	new->name=newstr;
      new->type = typestr;
      new->isConstant = isConstant;
      new->var = newstr;
	return (new);
}

node* buildTree(char *op,node *left,node *right )
{
	node *new = (node*)malloc(sizeof(node));
	char *newstr = (char *)malloc(strlen(op)+1);
      char *var_str = (char *)malloc(sizeof(char)*100+1);
	strcpy(newstr,op);
	
      char *typestr = (char *)malloc(4);
	strcpy(typestr," ");

      new->left=left;
	new->right=right;
	new->name=newstr;
      new->type=typestr;
      new->var = var_str;
      if(left)
      new->type = left->type;
      
	return (new);
}

void printTree2(node *tree)
{
	if(tree->left || tree->right)
	      printf("(");
	//printf(" %s ",tree->name);
	if(tree->left)
	printTree(tree->left);

      printf(" %s",tree->name);
	if(tree->right)
		printTree(tree->right);
	if(tree->left || tree->right)
		printf(")");
	
}
void yyerror(char *s)
{
	printf("%d %s %s\n", yylineno, s, yytext);
	printf(ANSI_COLOR_RED "Status: Parsing Failed - Invalid\n" ANSI_COLOR_RESET);
}
void insert_type_ST(node * n ,char * type){
      
      for(int i = 0;i<1001;i++){
            if(strcmp(ST[i].name,n->name)==0){
                  strcpy(ST[i].type , type);
                  char *typestr = (char *)malloc(sizeof(type));
                  strcpy(typestr, type);
                  n->type=typestr;

            }
      }
}

void add_value(node * n ,node * n2){
      if(n2->isConstant==0 || !(n2->name[0]>='0' && (n2->name[0]<='9'))){
            return;
      }
      for(int i = 0;i<1001;i++){
            if(strcmp(ST[i].name,n->name)==0){
                  strcpy(ST[i].value , n2->name);
            }
      }
}

void search_id(node *n , int purpose)
{
      if(n->isConstant ){
            return;
      }
      
  int flag = 0;
  for(int i = 0;i < 1001 ;i++)
  {
    if(!strcmp(ST[i].name,n->name)  && strlen(ST[i].type)>0 ) 
    {
      if(purpose == 1)
      {
            printf(ANSI_COLOR_RED "error: Redeclaration of variable %s at line %d\n" ANSI_COLOR_RESET,n->name,yylineno);
            exit(0);
      }
      flag = 1;
      return;
    }
  }

  if(flag == 0 && purpose == 0)
  {
    printf(ANSI_COLOR_RED "Error at line %d : %s is not defined\n" ANSI_COLOR_RESET,yylineno,n->name);
    exit(0);
  }
}

void check_Type(node *a , node *b){
     // printf("\n%s  -----  %s \n", a->type , b->type);
        if(!strcmp(a->type,b->type) ){
              return;
        }else{
             printf(ANSI_COLOR_RED "Error at line %d : Type mismatch\n" ANSI_COLOR_RESET,yylineno);
    exit(0);   
        } 
  
}

char * getType(char * n){
      
  for(int i = 0;i < 1001 ;i++)
  {
    if(!strcmp(ST[i].name,n)  && strlen(ST[i].type)>0 ) 
    {
          return ST[i].type;
    }
  }
  return "";    
}


void print2DUtil( node *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = 0; i < space; i++) 
        printf(" "); 
    printf("%s\n", root->name); 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 
  
void printTree( node *root) 
{ 
   // Pass initial space count as 0 
  // print2DUtil(root, 10); 
} 

void insert_line_ST(node * n ){
        for(int i = 0;i<1001;i++){
            if(strcmp(ST[i].name,n->name)==0){
                ST[i].line = yylineno;
            }
        }
}

int top = 0;
int temp = 0;
int l_num = 1;
int l_num1 = 50;
int flag = 0;
int arr[100];
int idx = -1;

codegen(node * cur, node * arg1 , node *arg2 , char *op){

      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t[10] = "T";  
      strcat(t,res);
      strcpy(cur->var,t);
      printf("%s = %s %s %s \n" ,t,arg1->var , op , arg2->var);
      fprintf(myfile, "%s = %s %s %s\n" ,t,arg1->var , op , arg2->var);
      temp++;     
      flag = 0;
}
codegen_assign(node * cur, node * arg1 , node * arg2){
       printf("%s = %s  \n" ,arg1->var,arg2->var );   
      fprintf(myfile,"%s = %s\n" ,arg1->var,arg2->var );   

       strcpy(cur->var , arg1->var); 
       flag = 0;
}

void tostring(char * str, int num)
{
    int i, rem, len = 0, n;
    if(num==0){
          str[0]='0';
              str[1] = '\0';

          return;
    }
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
    
}
if_else0(){
      if(flag==0)
      printf("L%d: \n", l_num); 
      fprintf(myfile, "L%d:\n", l_num); 
      l_num++;
}
if_else1(node * cond){
      printf("T%d = not %s \n",temp,cond->var);
      printf("If T%d goto L%d \n",temp,l_num); 
      fprintf(myfile,"T%d = not %s\n",temp,cond->var);
      fprintf(myfile,"If T%d goto L%d\n",temp,l_num); 
      temp++;
      flag = 0;
      //l_num++;

}

if_else2(){
      printf("goto L%d \n",l_num1);
      fprintf(myfile,"goto L%d\n",l_num1);
      flag = 0;
}

if_else4(){
      printf("L%d: \ngoto L%d \n",l_num1,l_num);
      fprintf(myfile,"L%d: \ngoto L%d\n",l_num1,l_num);
      l_num1++;
      printf("L%d:\n",l_num);
      fprintf(myfile,"L%d:\n",l_num);
      l_num++;
      flag = 1;
}

while1(){
      if(flag==0)
      {
            printf("L%d: \n", l_num); 
            fprintf(myfile,"L%d:\n", l_num); 
            l_num++;
      }
}

while2(node * cond){
      // printf("%s \n",cond->name);
      idx++;
      arr[idx] = l_num;
      printf("T%d = not %s \n",temp,cond->var);
      fprintf(myfile,"T%d = not %s\n",temp,cond->var);
      printf("If T%d goto L%d \n",temp,l_num); 
      fprintf(myfile,"If T%d goto L%d \n",temp,l_num); 
      temp++;
      l_num++;
      flag = 0;
}

while3(){
      int pop = arr[idx];
      arr[idx] = 0;
      idx--;
     // printf("goto L%d \n",l_num-1);
     // printf("L%d : \n",l_num++);
      printf("goto L%d \n",pop-1);
      printf("L%d : \n",pop);
      fprintf(myfile,"goto L%d\n",pop-1);
      fprintf(myfile,"L%d: \n",pop);
      flag = 1;
}

for1(){
      if(flag == 0){
            printf("L%d: \n", l_num);
            fprintf(myfile,"L%d: \n", l_num);
      }
      idx++;
      arr[idx++] = l_num+3;
      arr[idx++] = l_num+1;
      arr[idx++] = l_num+2;
      arr[idx] = l_num;
}

for2(node * n){
      printf("T%d = not %s \n",temp,n->var);
      printf("If T%d goto L%d \n",temp,l_num+3);
      fprintf(myfile,"T%d = not %s \n",temp,n->var);
      fprintf(myfile,"If T%d goto L%d \n",temp,l_num+3);
      temp++;
      printf("If T%d goto L%d \n",temp-2,l_num+2); 
      printf("L%d: \n",l_num+1); 
    
      fprintf(myfile,"If T%d goto L%d \n",temp-2,l_num+2); 
      fprintf(myfile,"L%d: \n",l_num+1); 
      flag = 0;
      l_num+=4;
}

for3(){
      //printf("goto L%d : \n",l_num+1);
      //printf("L%d : \n",l_num+3);

      printf("goto L%d \n",arr[idx]);
      fprintf(myfile,"goto L%d \n",arr[idx--]);
      printf("L%d: \n",arr[idx]);
      fprintf(myfile,"L%d: \n",arr[idx--]);

      flag = 1;
      
}
for4(){
      //printf("goto L%d : \n",l_num);
      //printf("L%d : \n",l_num+2);

      printf("goto L%d \n",arr[idx]);
      fprintf(myfile,"goto L%d \n",arr[idx--]);
      printf("L%d: \n",arr[idx]);
      fprintf(myfile,"L%d: \n",arr[idx--]);

}

codegen_per(node * cur, node * arg1 , node *arg2 , char *op){
      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t[10] = "T";  
      strcat(t,res);
      printf("%s = %s / %s \n" ,t , arg1->var , arg2->var);
      fprintf(myfile,"%s = %s / %s \n" ,t , arg1->var , arg2->var);
      char * prev = t;
      temp++;     
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t2[10] = "T";  
      strcat(t2,res);
      strcpy(cur->var,t2);
      printf("%s = %s * 100 \n" ,t2 , t);      
      fprintf(myfile,"%s = %s * 100 \n" ,t2 , t);      
      temp++;
}

codegen_gcd(node * cur, node * arg1 , node *arg2 , char *op){
      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t1[10] = "T";  
      strcat(t1,res);
      while1();
      printf("%s = %s %s %s \n" ,t1,arg1->var , "!=" , arg2->var);
      fprintf(myfile,"%s = %s %s %s \n" ,t1,arg1->var , "!=" , arg2->var);
      temp++;
      node *new = (node*)malloc(sizeof(node));
      new->var = t1;
      while2(new);
      //l_num++;
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t2[10] = "T";  
      strcat(t2,res);
      printf("%s = %s %s %s \n",t2,arg1->var,">",arg2->var);
      fprintf(myfile,"%s = %s %s %s \n",t2,arg1->var,">",arg2->var);
      temp++;
      new = (node*)malloc(sizeof(node));
      new->var = t2;
      if_else1(new);
      
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t3[10] = "T";  
      strcat(t3,res);
      printf("%s = %s %s %s \n",t3,arg1->var,"-",arg2->var);
      fprintf(myfile,"%s = %s %s %s \n",t3,arg1->var,"-",arg2->var);
      temp++;
      printf("%s = %s  \n" ,arg1->var,t3 );  
      fprintf(myfile,"%s = %s  \n" ,arg1->var,t3 );  
      
      
      if_else2();
      if_else0();
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t4[10] = "T";  
      strcat(t4,res);
      printf("%s = %s %s %s \n",t4,arg2->var,"-",arg1->var);
      fprintf(myfile,"%s = %s %s %s \n",t4,arg2->var,"-",arg1->var);
      temp++;
      printf("%s = %s  \n" ,arg2->var,t4);
      printf("L%d: \ngoto L%d \n",l_num1,l_num);
      fprintf(myfile,"%s = %s  \n" ,arg2->var,t4);
      fprintf(myfile,"L%d: \ngoto L%d \n",l_num1,l_num);
      l_num1++;
      printf("L%d:\n",l_num);
      fprintf(myfile,"L%d:\n",l_num);
      l_num++;
      flag = 1;

      printf("goto L%d \n",l_num-4);
      printf("L%d: \n",l_num-3);
      fprintf(myfile,"goto L%d \n",l_num-4);
      fprintf(myfile,"L%d: \n",l_num-3);
      flag = 0;
      strcpy(cur->var,arg1->var);

}

codegen_lcm(node * cur, node * arg1 , node *arg2 , char *op){

      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t7[10] = "T";  
      strcat(t7,res);
      printf("%s = %s %s %s \n" ,t7,arg1->var , "*" , arg2->var);
      fprintf(myfile,"%s = %s %s %s \n" ,t7,arg1->var , "*" , arg2->var);
      temp++;



      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t1[10] = "T";  
      strcat(t1,res);
      while1();
      printf("%s = %s %s %s \n" ,t1,arg1->var , "!=" , arg2->var);
      fprintf(myfile,"%s = %s %s %s \n" ,t1,arg1->var , "!=" , arg2->var);
      temp++;
      node *new = (node*)malloc(sizeof(node));
      new->var = t1;
      while2(new);
      //l_num++;
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t2[10] = "T";  
      strcat(t2,res);
      printf("%s = %s %s %s \n",t2,arg1->var,">",arg2->var);
      fprintf(myfile,"%s = %s %s %s \n",t2,arg1->var,">",arg2->var);
      temp++;
      new = (node*)malloc(sizeof(node));
      new->var = t2;
      if_else1(new);
      
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t3[10] = "T";  
      strcat(t3,res);
      printf("%s = %s %s %s \n",t3,arg1->var,"-",arg2->var);
      fprintf(myfile,"%s = %s %s %s \n",t3,arg1->var,"-",arg2->var);
      temp++;
      printf("%s = %s  \n" ,arg1->var,t3 );  
      fprintf(myfile,"%s = %s  \n" ,arg1->var,t3 );  
      
      
      if_else2();
      if_else0();
      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t4[10] = "T";  
      strcat(t4,res);
      printf("%s = %s %s %s \n",t4,arg2->var,"-",arg1->var);
      fprintf(myfile,"%s = %s %s %s \n",t4,arg2->var,"-",arg1->var);
      temp++;

      printf("%s = %s  \n" ,arg2->var,t4);
      printf("L%d: \ngoto L%d \n",l_num1,l_num);
      fprintf(myfile,"%s = %s  \n" ,arg2->var,t4);
      fprintf(myfile,"L%d: \ngoto L%d \n",l_num1,l_num);
      l_num1++;

      printf("L%d:\n",l_num);
      fprintf(myfile,"L%d:\n",l_num);
      l_num++;

      flag = 1;

      printf("goto L%d \n",l_num-4);
      printf("L%d: \n",l_num-3);
      fprintf(myfile,"goto L%d \n",l_num-4);
      fprintf(myfile,"L%d: \n",l_num-3);
      flag = 0;


      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t8[10] = "T";  
      strcat(t8,res);
      printf("%s = %s / %s \n" ,t8 , t7,arg1->var);
      fprintf(myfile,"%s = %s / %s \n" ,t8 , t7,arg1->var);
      temp++;
      strcpy(cur->var,t8);
}

codegen_fact(node * cur, node * arg1 , char *op){
      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t1[10] = "T";  
      strcat(t1,res);
      printf("%s = %s  \n" ,t1 , "1");
      fprintf(myfile,"%s = %s  \n" ,t1 , "1");
      temp++; 

      while1();

      node *new = (node*)malloc(sizeof(node));

      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t4[10] = "T";  
      strcat(t4,res);
      temp++;
      printf("%s = %s > 0 \n" , t4,arg1->var);
      fprintf(myfile,"%s = %s > 0 \n" , t4,arg1->var);
      new->var = t4;


      while2(new);

      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t2[10] = "T";  
      strcat(t2,res);
      printf("%s = %s * %s \n",t2,t1,arg1->var);
      printf("%s = %s \n",t1,t2);
      fprintf(myfile,"%s = %s * %s \n",t2,t1,arg1->var);
      fprintf(myfile,"%s = %s \n",t1,t2);
      temp++;

      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t3[10] = "T";  
      strcat(t3,res);
      printf("%s = %s - 1 \n",t3,arg1->var);
      printf("%s = %s\n",arg1->var,t3);
      fprintf(myfile,"%s = %s - 1 \n",t3,arg1->var);
      fprintf(myfile,"%s = %s\n",arg1->var,t3);
      temp++;


      while3();
      flag = 1;

      strcpy(cur->var,t1);
}

codegen_pow(node * cur, node * arg1 , node * arg2 , char *op){
      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t1[10] = "T";  
      strcat(t1,res);
      printf("%s = %s  \n" ,t1 , "1");
      fprintf(myfile,"%s = %s  \n" ,t1 , "1");
      temp++; 

      while1();

      node *new = (node*)malloc(sizeof(node));

      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t4[10] = "T";  
      strcat(t4,res);
      temp++;
      printf("%s = %s > 0 \n" , t4,arg2->var);
      fprintf(myfile,"%s = %s > 0 \n" , t4,arg2->var);
      new->var = t4;


      while2(new);

      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t2[10] = "T";  
      strcat(t2,res);
      printf("%s = %s * %s \n",t2,t1,arg1->var);
      printf("%s = %s \n",t1,t2);
      fprintf(myfile,"%s = %s * %s \n",t2,t1,arg1->var);
      fprintf(myfile,"%s = %s \n",t1,t2);
      temp++;

      res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t3[10] = "T";  
      strcat(t3,res);
      printf("%s = %s - 1 \n",t3,arg2->var);
      printf("%s = %s\n",arg2->var,t3);
      fprintf(myfile,"%s = %s - 1 \n",t3,arg2->var);
      fprintf(myfile,"%s = %s\n",arg2->var,t3);
      temp++;


      while3();
      flag = 1;

      strcpy(cur->var,t1);
}


for_new1( node* arg1  ,node* arg2 ){
      printf("%s = %s\n" , arg1->name , arg2->name);
      fprintf(myfile,"%s = %s\n" , arg1->name , arg2->name);
      arg1->var = arg1->name;
      forhelp1();
}
for_new2( node* arg1 , node * arg2 ){

      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t1[10] = "T";  
      strcat(t1,res);
      temp++;
      printf("%s = %s < %s \n"  ,t1, arg1->name , arg2->name);
      fprintf(myfile,"%s = %s < %s \n"  ,t1, arg1->name , arg2->name);

      node *new = (node*)malloc(sizeof(node));
      new->var = t1;

      forhelp2(new);
}
for_new3( node* arg1 , node * arg2 ){

      char *res = (char *)malloc(sizeof(char)*5+1);
      tostring(res,temp);      
      char t1[10] = "T";  
      strcat(t1,res);
      temp++;
      printf("%s = %s + %s\n"  ,t1, arg1->var , arg2->var);
      printf("%s = %s \n"  , arg1->var , t1);
      fprintf(myfile,"%s = %s + %s\n"  ,t1, arg1->var , arg2->var);
      fprintf(myfile,"%s = %s \n"  , arg1->var , t1);
}


forhelp1(){
      if(flag == 0){
      printf("L%d: \n", l_num);
      fprintf(myfile,"L%d: \n", l_num);
      }
      idx++;
      arr[idx++] = l_num+1;
      arr[idx] = l_num;
 
}

forhelp2(node * n){
      printf("T%d = not %s \n",temp,n->var);
      fprintf(myfile,"T%d = not %s \n",temp,n->var);
      printf("If T%d goto L%d \n",temp,++l_num);
      fprintf(myfile,"If T%d goto L%d \n",temp,l_num);
      temp++;

      flag = 0;
}

forhelp3(){

      printf("goto L%d  \n",arr[idx]);
      fprintf(myfile,"goto L%d \n",arr[idx--]);
      printf("L%: \n",arr[idx]);
      fprintf(myfile,"L%d: \n",arr[idx--]);
      flag = 1;     
}