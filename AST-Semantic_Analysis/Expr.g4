grammar Expr;

prog: startup 'int' 'main' '(' ')' block EOF
    ;

startup: variableDef startup    #varStart
    | function startup          #funcStart
    |                           #blankStart
    ;

function: functionDef block;

functionDef: 'func' datatype ID'('arguments')';

arguments: datatype ID              #singleArg 
        | datatype ID',' arguments  #multiArg
        |                           #blankArg
        ;

block: '{'statements'}';

statements: statement statements    #recStats
        |                           #blankStats
        ;

statement: variableDef                                              #varStat      
    | assignmentStatement                                           #asgStat
    | 'return' expr ';'                                             #retStat
    | 'if' '('condition')' block                                    #ifStat
    | 'if' '('condition')' block 'else' block                       #ifelseStat
    | 'for' '(' varassign ';' condition ';' varassign ')' block     #forStat
    | 'while' '(' condition ')' block                               #whileStat
    | '(' condition ')' '?' varassign ':' varassign ';'             #ternaryStat
    | 'cin' '(' expr ')' ';'                                        #inpStat
    | 'cout' '(' expr ')' ';'                                       #otpStat
    | 'ifstream' ID ';'                                             #filInpOpnStat
    | 'ofstream' ID ';'                                             #filOutOpnStat
    | 'fin' '(' expr ')' ';'                                        #filInpStat
    | 'fout' '(' expr ')' ';'                                       #filOtpStat
    | 'fclose' ID ';'                                               #filClsStat
    | ID '(' exps ')' ';'                                           #funcCallStat
    ;

assignmentStatement: ID '=' expr';'             #varAsg
    | ID '[' expr ']' '=' expr';'               #arAsg
    | ID '[' expr ']' '[' expr ']' '=' expr';'  #darAsg
    ;

varassign : ID '=' expr;

condition: '('condition')'              #paranCond
    | '!' condition                     #notCond
    | condition '||' condition          #orCond
    | condition '&&' condition          #andCond
    | expr Relop expr                   #baseCond
    ;

expr: '(' expr ')'                  #paranExpr
    | ID '(' exps ')'               #funccallExpr
    | expr '%' expr                 #modExpr
    | expr '/' expr                 #divExpr
    | expr '*' expr                 #mulExpr
    | expr Adsub expr               #adsubExpr
    | expr Relop expr               #relopExpr
    | expr '&' expr                 #andExpr
    | expr '^' expr                 #xorExpr
    | expr '|' expr                 #orExpr
    | expr Eqop expr                #eqopExpr
    | literal                       #litExpr
    | ID '[' expr ']'               #aracExpr
    | ID '[' expr ']' '[' expr ']'  #daracExpr
    | ID                            #varacExpr
    ;

literal: Int_literal    #intLit
    | Float_literal     #floatLit
    | String_literal    #stringLit
    | Char_literal      #charLit
    | Bool_literal      #boolLit
    ;

exps: expr              #exprExps 
    | expr ',' exps     #mulexprExps
    ;

variableDef: datatype vars';' ;

vars : variable ',' vars    #mulVars
    | variable              #varVars
    ;

variable : ID                              #idVar
    | ID '[' expr ']'                      #arVar
    | ID '[' expr ']' '[' expr ']'         #darVar
    ; 

datatype : 'int' | 'bool' | 'char' | 'uint' | 'float' | 'string';
Bool_literal : 'true' | 'false';
ID  : [a-z][a-zA-Z0-9_]*;
Int_literal : [0-9]+ ;
Char_literal : '\'' ( ~['\r\n\\] | '\\' ['\\] ) '\'';
String_literal : '"'.*?'"' ;
Float_literal : [0-9]*'.'[0-9]+;
Relop : '<=' | '>=' | '<' | '>' | '==' | '!=';
Eqop : '=';
Adsub : '+' | '-';
COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \r\t\n]+ -> skip;