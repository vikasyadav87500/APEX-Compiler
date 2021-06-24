%{
    #include <stdio.h>
	#include <string.h>
    #include <stdlib.h>
    #include <conio.h>
    #include "y.tab.h"

    #define ANSI_COLOR_RED		"\x1b[31m"
    #define ANSI_COLOR_GREEN	"\x1b[32m"
    #define ANSI_COLOR_CYAN		"\x1b[36m"
    #define ANSI_COLOR_RESET	"\x1b[0m"
    #define ANSI_COLOR_YELLOW    "\033[1;33m"

    
    int yylineno = 1;
    struct SymbolTable{
        char name[20];
        char class[20];
        char type[20];
        char value[100];
        int line;
        int var_size;
    }ST[1001];

    int hash_fn(char * str){
        int value = 0;
        for(int i = 0;i<strlen(str);i++){
            value += value*10 + (str[i]-'A');
            value = value%1001;
            if(value<0){
                value+=1001;
            }
        }
        return value;
    }

    int SearchST(char * var_name){
        int value = hash_fn(var_name);
        if(ST[value].var_size==0){
            return 0;
        }else if(strcmp(ST[value].name,var_name)==0){
            return 1;
        }
        int i = (value+1)%1001;
        while(i!=value){
            if(strcmp(ST[value].name,var_name)==0){
                return 1;
            }
            i = (i+1)%1001;
        }
        return 0;
    }

    void insert_line_ST2(char * var_name , int line){
        for(int i = 0;i<1001;i++){
            if(strcmp(ST[i].name,var_name)==0){
                ST[i].line = line;
            }
        }
    }


    
    void insert_value_ST(char * var_name ,char * value){
        for(int i = 0;i<1001;i++){
            if(strcmp(ST[i].name,var_name)==0){
                strcpy(ST[i].value , value);
            }
        }
    }

    void insertST(char *var_name , char * class ){
        if(SearchST(var_name)){
            return ;
        }else{
            int value = hash_fn(var_name);
            while(1){
                if(ST[value].var_size==0){
                    strcpy(ST[value].name,var_name);
                    strcpy(ST[value].class , class);
                    ST[value].var_size = strlen(var_name);
                    break;
                }
                value++;
                value%=1001;
            }
        }
    }
    void insert_type(char * n ,char * type){
        
        for(int i = 0;i<1001;i++){
                if(strcmp(ST[i].name,n)==0){
                    strcpy(ST[i].type , type);
                }
        }
    }
    void printST(){
        printf(ANSI_COLOR_YELLOW "\n                                 SYMBOL TABLE                          \n\n" ANSI_COLOR_RESET);
		printf("%10s | %15s | %10s | %10s | %10s\n","SYMBOL", "CLASS", "TYPE","VALUE", "LINE NO");
		for(int i=0;i<81;i++) {
			printf("-");
		}
		printf("\n");
		for(int i = 0 ; i < 1001 ; i++)
		{
			if(ST[i].var_size == 0)
			{
				continue;
			}
			printf("%10s | %15s | %10s | %10s | %10d\n",ST[i].name, ST[i].class, ST[i].type, ST[i].value, ST[i].line);
		}
    }

    char curid[20];
	char curtype[20];
	char curval[20];
%}



%%

\n  {yylineno++;}
\/\/(.*) {printf("%s \t- SINGLE LINE COMMENT\n", yytext);}
\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/ 	;
[  \n\t] ;


";"				{ return(';'); }
","				{ return(','); }
("{")			{ return('{'); }
("}")			{ return('}'); }
"("				{ return('('); }
")"				{ return(')'); }
":"				{ return(':'); }
"."				{ return('.'); }

"main()"         { insertST(yytext, "Keyword");insert_line_ST2(yytext , yylineno);  return MAINOP;}
"auto"          { insertST(yytext, "Keyword"); insert_line_ST2(yytext , yylineno);  return AUTO;}
"continue"      { insertST(yytext, "Keyword"); insert_line_ST2(yytext , yylineno);  return CONTINUE;}
"char"			{ strcpy(curtype,yytext); insertST(yytext, "Keyword"); insert_line_ST2(yytext , yylineno); return CHAR;}
"else"			{  insertST(yytext, "Keyword"); insert_line_ST2(yytext , yylineno); return ELSE;}
"float"			{ strcpy(curtype,yytext); insertST(yytext, "Keyword"); insert_line_ST2(yytext , yylineno); return FLOAT;}
"while"			{ insertST(yytext, "Keyword"); insert_line_ST2(yytext , yylineno);  return WHILE;}
"do"			{ insertST(yytext, "Keyword");insert_line_ST2(yytext , yylineno); return DO;}
"for"			{ insertST(yytext, "Keyword");insert_line_ST2(yytext , yylineno);  return FOR;}
"if"			{ insertST(yytext, "Keyword"); insert_line_ST2(yytext , yylineno); return IF;}
"int"			{ strcpy(curtype,yytext); insertST(yytext, "Keyword");insert_line_ST2(yytext , yylineno);  return INT;}
"return"		{ insertST(yytext, "Keyword"); insert_line_ST2(yytext , yylineno);  return RETURN;}
"void"			{ strcpy(curtype,yytext); insertST(yytext, "Keyword");insert_line_ST2(yytext , yylineno);  return VOID;}
"break"			{ insertST(yytext, "Keyword");insert_line_ST2(yytext , yylineno);  return BREAK;}
"cout"          { insertST(yytext, "Keyword");insert_line_ST2(yytext , yylineno); return COUT;}
"endl"          { insertST(yytext, "Keyword");insert_line_ST2(yytext , yylineno); return ENDL;}
"cin"           { insertST(yytext, "Keyword");insert_line_ST2(yytext , yylineno); return CIN;}
"string"		{ strcpy(curtype,yytext); insertST(yytext, "Keyword"); insert_line_ST2(yytext , yylineno); return STRING;}

"%%"            {  yylval = yytext; return per;}
"++"			{ yylval = yytext; return T_inc; }
"--"			{ yylval = yytext; return T_dec; }
"<<"			{  yylval = yytext; return T_ls; }
"<="			{  yylval = yytext; return T_le; }
"<"				{  yylval = yytext; return T_l; }
">="			{  yylval = yytext; return T_ge; }
">"			    {  yylval = yytext; return T_g; }
"=="			{  yylval = yytext; return T_ee; }
"!="			{  yylval = yytext; return T_ne; }
"&&"			{  yylval = yytext; return T_aa; }
"||"			{  yylval = yytext; return T_oo; }
"^"				{  yylval = yytext; return T_x; }
"*="			{  yylval = yytext; return T_me; }
"/="			{  yylval = yytext; return T_de; }
"%="			{  yylval = yytext; return T_re; }
"+="			{  yylval = yytext; return T_pe; }
"-="			{  yylval = yytext; return T_se; }
"<<="			{  yylval = yytext; return T_lse; }
">>="			{  yylval = yytext; return T_rse; }
"&="			{  yylval = yytext; return T_ae; }
"^="			{  yylval = yytext; return T_xe; }
"|="			{  yylval = yytext; return T_oe; }
"&"				{  yylval = yytext; return T_a; }
"!"				{  yylval = yytext; return fact; }
"-"				{  yylval = yytext; return T_s; }
"+"				{  yylval = yytext; return T_p; }
"*"				{  yylval = yytext; return T_m; }
"/"				{  yylval = yytext; return T_d; }
"%"				{  yylval = yytext; yylval = yytext; return T_r; }
"|"				{  yylval = yytext; return T_o; }
\=				{  yylval = yytext; return T_e;}
"gcd"           {  yylval = yytext; return gcd;}
"lcm"           {  yylval = yytext; return lcm;}
"**"            {  yylval = yytext; return pow;}


\"[A-Z|a-z|0-9]*[^\n]*\"/[;|,|\|" ")] 			{ insertST(yytext, "CONSTANT");insert_line_ST2(yytext , yylineno); insert_type(yytext , "STRING"); yylval = yytext; strcpy(curval,yytext); return STRING_C;}
\'[A-Z|a-z |0-9]\'/[;|,|\)|:|" "] 		{insertST(yytext, "CONSTANT");insert_line_ST2(yytext , yylineno); insert_type(yytext , "CHAR"); yylval = yytext; strcpy(curval,yytext); return CHAR_C;}
[1-9][0-9]*|0/[;|,|" "|\)|<|>|=|\!|\||&|\+|\-|\*|\/|\%|~|\]|\}|:|\n|\t|\^] 	 { insertST(yytext, "CONSTANT");insert_line_ST2(yytext , yylineno); insert_type(yytext , "INT"); yylval = (int)yytext; strcpy(curval,yytext); return NUM;}
([0-9]*)\.([0-9]+)/[;|,|" "|\)|<|>|=|\!|\||&|\+|\-|\*|\/|\%|~|\n|\t|\^] 	{ insertST(yytext, "CONSTANT");insert_line_ST2(yytext , yylineno); insert_type(yytext , "FLOAT"); yylval = yytext; strcpy(curval,yytext); return FLOAT_C;}
[A-Za-z_][A-Za-z_0-9]* {strcpy(curid,yytext);insertST(yytext,"Identifier");  yylval = yytext; return ID;}
"$" return 0;

(.?) {
        printf("%s\n",yytext);
		if(yytext[0]=='#')
		{
       		printf("Error in Pre-Processor directive at line no. %d\n",yylineno);
       	}
	    else if(yytext[0]=='/')
	    {
       		printf("ERR_UNMATCHED_COMMENT at line no. %d\n",yylineno);
       	}
       	else if(yytext[0]=='"')
       	{
       		printf("ERR_INCOMPLETE_STRING at line no. %d\n",yylineno);
       	}
       	else
       	{
       		printf("ERROR at line no. %d\n",yylineno);
       	}
       	printf("%s\n", yytext);
       	return 0;
}

%%

int yywrap (void){
    return 1;
} 
