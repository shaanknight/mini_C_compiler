#include <iostream>
#include "ast.h"
#include <vector>
#include "ExprVisitor.h"

using namespace std;

class ExprBuildASTVisitor : public ExprVisitor
{
public:
    /**
   * Visit parse trees produced by ExprParser.
   */
    vector<ASTScope> SymbolTable; 
    string latestDatatype;
    bool functionOn;

    virtual antlrcpp::Any visitProg(ExprParser::ProgContext *context)
    {
        cout << "In visitProg" << endl;
        ASTScope scope;
        SymbolTable.push_back(scope);
        ASTProg *node = new ASTProg();
        node->stu = visit(context->startup());
        node->blk = visit(context->block());
        SymbolTable.pop_back();
        return (ASTProg *) node;
    }

    virtual antlrcpp::Any visitVarStart(ExprParser::VarStartContext *context)
    {
        cout << "In visitVarStart" << endl;
        ASTVarStart *node = new ASTVarStart();
        node->vdef = visit(context->variableDef());
        node->stu = visit(context->startup());
        return (ASTStartup *) node;
    }

    virtual antlrcpp::Any visitFuncStart(ExprParser::FuncStartContext *context)
    {
        cout << "In visitFuncStart" << endl;
        ASTFuncStart *node = new ASTFuncStart();
        node->func = visit(context->function());
        node->stu = visit(context->startup());
        return (ASTStartup *) node;
    }

    virtual antlrcpp::Any visitBlankStart(ExprParser::BlankStartContext *context)
    {
        cout << "In visitBlankStart" << endl;
        return (ASTStartup *) nullptr;
    }

    virtual antlrcpp::Any visitFunction(ExprParser::FunctionContext *context)
    {
        cout << "In visitFunction" << endl;
        ASTScope scope;
        SymbolTable.push_back(scope);
        functionOn = true;
        ASTFunction *node = new ASTFunction();
        node->funcdef = visit(context->functionDef());
        node->blk = visit(context->block());
        SymbolTable.pop_back();
        functionOn = false;
        return (ASTFunction *) node;
    }

    virtual antlrcpp::Any visitFunctionDef(ExprParser::FunctionDefContext *context)
    {
        cout << "In visitFunctionDef" << endl;
        ASTFunctionDef *node = new ASTFunctionDef();
        node->datatype = context->datatype()->getText();
        node->ID = context->ID()->getText();
        node->args = visit(context->arguments());
        return (ASTFunctionDef *) node;
    }

    virtual antlrcpp::Any visitSingleArg(ExprParser::SingleArgContext *context)
    {
        cout << "In visitSingleArg" << endl;
        ASTSingleArg *node = new ASTSingleArg();
        node->datatype = context->datatype()->getText();
        node->ID = context->ID()->getText();
        int sz = SymbolTable.size();
        SymbolTable[sz-1].addScope(node->ID,node->datatype);
        return (ASTArguments *) node;
    }

    virtual antlrcpp::Any visitMultiArg(ExprParser::MultiArgContext *context) 
    {
        cout << "In visitMultiArg" << endl;
        ASTMultiArg *node = new ASTMultiArg();
        node->datatype = context->datatype()->getText();
        node->ID = context->ID()->getText();
        int sz = SymbolTable.size();
        SymbolTable[sz-1].addScope(node->ID,node->datatype);
        node->args = visit(context->arguments());
        return (ASTArguments *) node;
    }

    virtual antlrcpp::Any visitBlankArg(ExprParser::BlankArgContext *context)
    {
        cout << "In visitBlankArg" << endl;
        return (ASTArguments *) nullptr;
    }

    virtual antlrcpp::Any visitBlock(ExprParser::BlockContext *context)
    {
        cout << "In visitBlock" << endl;
        if(functionOn == false)
        {
            ASTScope scope;
            SymbolTable.push_back(scope);
        }
        ASTBlock *node = new ASTBlock();
        node->stats = visit(context->statements());
        if(functionOn == false)
            SymbolTable.pop_back();
        return (ASTBlock *) node;
    }

    virtual antlrcpp::Any visitRecStats(ExprParser::RecStatsContext *context)
    {
        cout << "In visitRecStats" << endl;
        ASTRecStats *node = new ASTRecStats();
        node->stat = visit(context->statement());
        node->recstats = visit(context->statements());
        return (ASTStatements *) node;
    }

    virtual antlrcpp::Any visitBlankStats(ExprParser::BlankStatsContext *context) 
    {   
        cout << "In visitBlankStats" << endl;
        return (ASTStatements *) nullptr;
    }

    virtual antlrcpp::Any visitVarStat(ExprParser::VarStatContext *context) 
    {
        cout << "In visitVarStat" << endl;
        ASTVarStat *node = new ASTVarStat();
        node->vdef = visit(context->variableDef());
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitAsgStat(ExprParser::AsgStatContext *context) 
    {
        cout << "In visitAsgStat" << endl;
        ASTAsgStat *node = new ASTAsgStat();
        node->asg = visit(context->assignmentStatement());
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitRetStat(ExprParser::RetStatContext *context) 
    {
        cout << "In visitRetStat" << endl;
        ASTRetStat *node = new ASTRetStat();
        node->expr = visit(context->expr());
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitIfStat(ExprParser::IfStatContext *context) 
    {
        cout << "In visitIfStat" << endl;
        ASTIfStat *node = new ASTIfStat();
        node->cond = visit(context->condition());
        node->blk = visit(context->block());
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitIfelseStat(ExprParser::IfelseStatContext *context) 
    {
        cout << "In visitIfelseStat" << endl;
        ASTIfelseStat *node = new ASTIfelseStat();
        node->cond = visit(context->condition());
        node->blk1 = visit(context->block(0));
        node->blk2 = visit(context->block(1));
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitForStat(ExprParser::ForStatContext *context) 
    {
        cout << "In visitForStat" << endl;
        ASTForStat *node = new ASTForStat();
        node->varasg1 = visit(context->varassign(0));
        node->cond = visit(context->condition());
        node->varasg2 = visit(context->varassign(1));
        node->blk = visit(context->block());
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitWhileStat(ExprParser::WhileStatContext *context) 
    {
        cout << "In visitWhileStat" << endl;
        ASTWhileStat *node = new ASTWhileStat();
        node->cond = visit(context->condition());
        node->blk = visit(context->block());
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitTernaryStat(ExprParser::TernaryStatContext *context) 
    {
        cout << "In visitTernaryStat" << endl;
        ASTTernaryStat *node = new ASTTernaryStat();
        node->cond = visit(context->condition());
        node->varas1 = visit(context->varassign(0));
        node->varas2 = visit(context->varassign(1));
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitInpStat(ExprParser::InpStatContext *context) 
    {
        cout << "In visitInpStat" << endl;
        ASTInpStat *node = new ASTInpStat();
        node->expr = visit(context->expr());
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitOtpStat(ExprParser::OtpStatContext *context) 
    {
        cout << "In visitOtpStat" << endl;
        ASTOtpStat *node = new ASTOtpStat();
        node->expr = visit(context->expr());
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitFilInpOpnStat(ExprParser::FilInpOpnStatContext *context) 
    {
        cout << "In visitFilInpOpnStat" << endl;
        ASTFilInpOpnStat *node = new ASTFilInpOpnStat();
        node->id = context->ID()->getText();
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitFilOutOpnStat(ExprParser::FilOutOpnStatContext *context) 
    {
        cout << "In visitFilOutOpnStat" << endl;
        ASTFilOutOpnStat *node = new ASTFilOutOpnStat();
        node->id = context->ID()->getText();
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitFilInpStat(ExprParser::FilInpStatContext *context) 
    {
        cout << "In visitFilInpStat" << endl;
        ASTFilInpStat *node = new ASTFilInpStat();
        node->expr = visit(context->expr());
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitFilOtpStat(ExprParser::FilOtpStatContext *context) 
    {
        cout << "In visitFilOtpStat" << endl;
        ASTFilOtpStat *node = new ASTFilOtpStat();
        node->expr = visit(context->expr());
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitFilClsStat(ExprParser::FilClsStatContext *context) 
    {
        cout << "In visitFilClsStat" << endl;
        ASTFilClsStat *node = new ASTFilClsStat();
        node->id = context->ID()->getText();
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitFuncCallStat(ExprParser::FuncCallStatContext *context) 
    {
        cout << "In visitFuncCallStat" << endl;
        ASTFuncCallStat *node = new ASTFuncCallStat();
        node->id = context->ID()->getText();
        node->params = visit(context->exps());
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitVarAsg(ExprParser::VarAsgContext *context) 
    {
        cout << "In visitVarAsg" << endl;
        ASTVarAsg *node = new ASTVarAsg();
        node->id = context->ID()->getText();
        int sz = SymbolTable.size();
        bool found = false;
        int i;
        for(i=sz-1;i>=0;i--)
        {
            if(SymbolTable[i].findScope(node->id) == true)
            {
                found = true;
                cout << "found" << endl;
                break;
            }
        }
        if(found == false)
        {
            cout << "Variable " << node->id << " not declared before use." << endl;
            exit(1);
        }
        node->expr = visit(context->expr());
        string type = SymbolTable[i].getType(node->id);
        if(type != node->expr->type)
        {
            cout << "Type mismatch for assignmentStatement" << endl;
            exit(1);
        }
        return (ASTAssignmentStatement *) node;
    }

    virtual antlrcpp::Any visitArAsg(ExprParser::ArAsgContext *context) 
    {
        cout << "In visitArAsg" << endl;
        ASTArAsg *node = new ASTArAsg();
        node->id = context->ID()->getText();
        int sz = SymbolTable.size();
        bool found = false;
        int i;
        for(i=sz-1;i>=0;i--)
        {
            if(SymbolTable[i].findScope(node->id) == true)
            {
                found = true;
                cout << "found" << endl;
                break;
            }
        }
        if(found == false)
        {
            cout << "Variable " << node->id << " not declared before use." << endl;
            exit(1);
        }
        node->expr1 = visit(context->expr(0));
        node->expr2 = visit(context->expr(1));
        string type = SymbolTable[i].getType(node->id);
        if(type != node->expr2->type)
        {
            cout << "Type mismatch for assignmentStatement" << endl;
            exit(1);
        }
        if(node->expr1->type != "int")
        {
            cout << "Type mismatch : array indexed at non integer literal" << endl;
            exit(1);
        }
        return (ASTAssignmentStatement *) node;
    }

    virtual antlrcpp::Any visitDarAsg(ExprParser::DarAsgContext *context) 
    {
        cout << "In visitDarAsg" << endl;
        ASTDarAsg *node = new ASTDarAsg();
        node->id = context->ID()->getText();
        int sz = SymbolTable.size();
        bool found = false;
        int i;
        for(i=sz-1;i>=0;i--)
        {
            if(SymbolTable[i].findScope(node->id) == true)
            {
                found = true;
                cout << "found" << endl;
                break;
            }
        }
        if(found == false)
        {
            cout << "Variable " << node->id << " not declared before use." << endl;
            exit(1);
        }
        node->expr1 = visit(context->expr(0));
        node->expr2 = visit(context->expr(1));
        node->expr3 = visit(context->expr(2));
        string type = SymbolTable[i].getType(node->id);
        if(type != node->expr3->type)
        {
            cout << "Type mismatch for assignmentStatement" << endl;
            exit(1);
        }
        if(node->expr1->type != "int" || node->expr2->type != "int")
        {
            cout << "Type mismatch : array indexed at non integer literal" << endl;
            exit(1);
        }
        return (ASTAssignmentStatement *) node;
    }

    virtual antlrcpp::Any visitVarassign(ExprParser::VarassignContext *context) 
    {
        cout << "In visitVarassign" << endl;
        ASTVarassign *node = new ASTVarassign();
        node->id = context->ID()->getText();
        int sz = SymbolTable.size();
        bool found = false;
        int i;
        for(i=sz-1;i>=0;i--)
        {
            if(SymbolTable[i].findScope(node->id) == true)
            {
                found = true;
                cout << "found" << endl;
                break;
            }
        }
        if(found == false)
        {
            cout << "Variable " << node->id << " not declared before use." << endl;
            exit(1);
        }
        node->expr = visit(context->expr());
        string type = SymbolTable[i].getType(node->id);
        if(type != node->expr->type)
        {
            cout << "Type mismatch for varassign" << endl;
            exit(1);
        }
        return (ASTVarassign *) node;
    }

    virtual antlrcpp::Any visitOrCond(ExprParser::OrCondContext *context) 
    {
        cout << "In visitOrCond" << endl;
        ASTOrCond *node = new ASTOrCond();
        node->cond1 = visit(context->condition(0));
        node->cond2 = visit(context->condition(1));
        return (ASTCondition *) node;
    }

    virtual antlrcpp::Any visitAndCond(ExprParser::AndCondContext *context) 
    {
        cout << "In visitAndCond" << endl;
        ASTAndCond *node = new ASTAndCond();
        node->cond1 = visit(context->condition(0));
        node->cond2 = visit(context->condition(1));
        return (ASTCondition *) node;
    }

    virtual antlrcpp::Any visitParanCond(ExprParser::ParanCondContext *context) 
    {
        cout << "In visitParanCond" << endl;
        return (ASTCondition *) nullptr;
    }

    virtual antlrcpp::Any visitNotCond(ExprParser::NotCondContext *context) 
    {
        cout << "In visitNotCond" << endl;
        ASTNotCond *node = new ASTNotCond();
        node->cond = visit(context->condition());
        return (ASTCondition *) node;
    }

    virtual antlrcpp::Any visitBaseCond(ExprParser::BaseCondContext *context) 
    {
        cout << "In visitBaseCond" << endl;
        ASTBaseCond *node = new ASTBaseCond();
        node->expr1 = visit(context->expr(0));
        node->relop = context->Relop()->getText();
        node->expr2 = visit(context->expr(1));
        if(node->expr1->type != node->expr2->type)
        {
            cout << "Type Mismatch at BaseCondContext" << endl;
            exit(1);
        }
        return (ASTCondition *) node;
    }

    virtual antlrcpp::Any visitDaracExpr(ExprParser::DaracExprContext *context) 
    {
        cout << "In visitDaracExpr" << endl;
        ASTDaracExpr *node = new ASTDaracExpr();
        node->id = context->ID()->getText();
        int sz = SymbolTable.size();
        bool found = false;
        int i;
        for(i=sz-1;i>=0;i--)
        {
            if(SymbolTable[i].findScope(node->id) == true)
            {
                found = true;
                cout << "found" << endl;
                break;
            }
        }
        if(found == false)
        {
            cout << "Variable " << node->id << " not declared before use." << endl;
            exit(1);
        }
        node->type = SymbolTable[i].getType(node->id);
        node->expr1 = visit(context->expr(0));
        node->expr2 = visit(context->expr(1));
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitVaracExpr(ExprParser::VaracExprContext *context) 
    {
        cout << "In visitVaracExpr" << endl;
        ASTVaracExpr *node = new ASTVaracExpr();
        node->id = context->ID()->getText();
        int sz = SymbolTable.size();
        bool found = false;
        int i;
        for(i=sz-1;i>=0;i--)
        {
            if(SymbolTable[i].findScope(node->id) == true)
            {
                found = true;
                cout << "found" << endl;
                break;
            }
        }
        if(found == false)
        {
            cout << "Variable " << node->id << " not declared before use." << endl;
            exit(1);
        }
        node->type = SymbolTable[i].getType(node->id);
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitModExpr(ExprParser::ModExprContext *context) 
    {
        cout << "In visitModExpr" << endl;
        ASTModExpr *node = new ASTModExpr();
        node->expr1 = visit(context->expr(0));
        node->expr2 = visit(context->expr(1));
        if(node->expr1->type != node->expr2->type)
        {
            cout << "Type Mismatch at ModExprContext" << endl;
            exit(1);
        }
        if(node->expr1->type != "int")
        {
            cout << "ModExprContext expects int exprs" << endl;
        }
        node->type = node->expr1->type;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitRelopExpr(ExprParser::RelopExprContext *context) 
    {
        cout << "In visitRelopExpr" << endl;
        ASTRelopExpr *node = new ASTRelopExpr();
        node->expr1 = visit(context->expr(0));
        node->relop = context->Relop()->getText();
        node->expr2 = visit(context->expr(1));
        if(node->expr1->type != node->expr2->type)
        {
            cout << "Type Mismatch at RelopExprContext" << endl;
            exit(1);
        }
        if(node->expr1->type != "int" && node->expr1->type != "float")
        {
            cout << "RelopExprContext expects int/float exprs" << endl;
        }
        node->type = node->expr1->type;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitOrExpr(ExprParser::OrExprContext *context) 
    {
        cout << "In visitOrExpr" << endl;
        ASTOrExpr *node = new ASTOrExpr();
        node->expr1 = visit(context->expr(0));
        node->expr2 = visit(context->expr(1));
        if(node->expr1->type != node->expr2->type)
        {
            cout << "Type Mismatch at OrExprContext" << endl;
            exit(1);
        }
        if(node->expr1->type != "int")
        {
            cout << "OrExprContext expects int exprs" << endl;
        }
        node->type = node->expr1->type;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitXorExpr(ExprParser::XorExprContext *context) 
    {
        cout << "In visitXorExpr" << endl;
        ASTXorExpr *node = new ASTXorExpr();
        node->expr1 = visit(context->expr(0));
        node->expr2 = visit(context->expr(1));
        if(node->expr1->type != node->expr2->type)
        {
            cout << "Type Mismatch at XorExprContext" << endl;
            exit(1);
        }
        if(node->expr1->type != "int")
        {
            cout << "XorExprContext expects int exprs" << endl;
        }
        node->type = node->expr1->type;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitEqopExpr(ExprParser::EqopExprContext *context) 
    {
        cout << "In visitEqopExpr" << endl;
        ASTEqopExpr *node = new ASTEqopExpr();
        node->expr1 = visit(context->expr(0));
        node->eqop = context->Eqop()->getText();
        node->expr2 = visit(context->expr(1));
        if(node->expr1->type != node->expr2->type)
        {
            cout << "Type Mismatch at EqopExprContext" << endl;
            exit(1);
        }
        node->type = node->expr1->type;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitAdsubExpr(ExprParser::AdsubExprContext *context) 
    {
        cout << "In visitAdsubExpr" << endl;
        ASTAdsubExpr *node = new ASTAdsubExpr();
        node->expr1 = visit(context->expr(0));
        node->adsub = context->Adsub()->getText();
        node->expr2 = visit(context->expr(1));
        if(node->expr1->type != node->expr2->type)
        {
            cout << "Type Mismatch at AdsubExprContext" << endl;
            exit(1);
        }
        if(node->expr1->type != "int" && node->expr1->type != "float")
        {
            cout << "AdsubExprContext expects int/float exprs" << endl;
        }
        node->type = node->expr1->type;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitFunccallExpr(ExprParser::FunccallExprContext *context) 
    {
        cout << "In visitFunccallExpr" << endl;
        ASTFunccallExpr *node = new ASTFunccallExpr();
        node->id = context->ID()->getText();
        node->exps = visit(context->exps());
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitMulExpr(ExprParser::MulExprContext *context) 
    {
        cout << "In visitMulExpr" << endl;
        ASTMulExpr *node = new ASTMulExpr();
        node->expr1 = visit(context->expr(0));
        node->expr2 = visit(context->expr(1));
        if(node->expr1->type != node->expr2->type)
        {
            cout << "Type Mismatch at MulExprContext" << endl;
            exit(1);
        }
        if(node->expr1->type != "int" && node->expr1->type != "float")
        {
            cout << "MulExprContext expects int/float exprs" << endl;
        }
        node->type = node->expr1->type;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitAracExpr(ExprParser::AracExprContext *context) 
    {
        cout << "In visitAracExpr" << endl;
        ASTAracExpr *node = new ASTAracExpr();
        node->id = context->ID()->getText();
        int sz = SymbolTable.size();
        bool found = false;
        int i;
        for(i=sz-1;i>=0;i--)
        {
            if(SymbolTable[i].findScope(node->id) == true)
            {
                found = true;
                cout << "found" << endl;
                break;
            }
        }
        if(found == false)
        {
            cout << "Variable " << node->id << " not declared before use." << endl;
            exit(1);
        }
        node->expr = visit(context->expr());
        node->type = SymbolTable[i].getType(node->id);
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitDivExpr(ExprParser::DivExprContext *context) 
    {
        cout << "In visitDivExpr" << endl;
        ASTDivExpr *node = new ASTDivExpr();
        node->expr1 = visit(context->expr(0));
        node->expr2 = visit(context->expr(1));
        if(node->expr1->type != node->expr2->type)
        {
            cout << "Type Mismatch at DivExprContext" << endl;
            exit(1);
        }
        if(node->expr1->type != "int" && node->expr1->type != "float")
        {
            cout << "DivExprContext expects int/float exprs" << endl;
        }
        node->type = node->expr1->type;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitParanExpr(ExprParser::ParanExprContext *context) 
    {
        cout << "In visitParanExpr" << endl;
        ASTParanExpr *node = new ASTParanExpr();
        node->expr = visit(context->expr());
        node->type = node->expr->type;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitLitExpr(ExprParser::LitExprContext *context) 
    {
        cout << "In visitLitExpr" << endl;
        ASTLitExpr *node = new ASTLitExpr();
        node->litexpr = visit(context->literal());
        node->type = node->litexpr->type;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitAndExpr(ExprParser::AndExprContext *context) 
    {
        cout << "In visitAndExpr" << endl;
        ASTAndExpr *node = new ASTAndExpr();
        node->expr1 = visit(context->expr(0));
        node->expr2 = visit(context->expr(1));
        if(node->expr1->type != node->expr2->type)
        {
            cout << "Type Mismatch at AndExprContext" << endl;
            exit(1);
        }
        if(node->expr1->type != "int")
        {
            cout << "AndExprContext expects int exprs" << endl;
        }
        node->type = node->expr1->type;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprExps(ExprParser::ExprExpsContext *context) 
    {
        cout << "In visitExprExps" << endl;
        ASTExprExps *node = new ASTExprExps();
        node->expr = visit(context->expr());
        return (ASTExps *) node;
    }

    virtual antlrcpp::Any visitMulexprExps(ExprParser::MulexprExpsContext *context) 
    {
        cout << "In visitMulexprExps" << endl;
        ASTMulexprExps *node = new ASTMulexprExps();
        node->expr = visit(context->expr());
        node->exps = visit(context->exps());
        return (ASTExps *) node;
    }

    virtual antlrcpp::Any visitVariableDef(ExprParser::VariableDefContext *context) 
    {
        cout << "In visitVariableDef" << endl;
        ASTVariableDef *node = new ASTVariableDef();
        node->datatype = context->datatype()->getText();
        latestDatatype = node->datatype;
        node->vars = visit(context->vars());
        return (ASTVariableDef *) node;
    }

    virtual antlrcpp::Any visitMulVars(ExprParser::MulVarsContext *context) 
    {
        cout << "In visitMulVars" << endl;
        ASTMulVars *node = new ASTMulVars();
        node->var = visit(context->variable());
        node->vars = visit(context->vars());
        return (ASTVars *) node;
    }

    virtual antlrcpp::Any visitVarVars(ExprParser::VarVarsContext *context) 
    {
        cout << "In visitVarVars" << endl;
        ASTVarVars *node = new ASTVarVars();
        node->var = visit(context->variable());
        return (ASTVars *) node;
    }

    virtual antlrcpp::Any visitIdVar(ExprParser::IdVarContext *context) 
    {
        cout << "In visitIdVar" << endl;
        ASTIdVar *node = new ASTIdVar();
        node->id = context->ID()->getText();
        int sz = SymbolTable.size();
        SymbolTable[sz-1].addScope(node->id,latestDatatype);
        return (ASTVariable *) node;
    }

    virtual antlrcpp::Any visitArVar(ExprParser::ArVarContext *context) 
    {
        cout << "In visitArVar" << endl;
        ASTArVar *node = new ASTArVar();
        node->id = context->ID()->getText();
        int sz = SymbolTable.size();
        SymbolTable[sz-1].addScope(node->id,latestDatatype);
        node->expr = visit(context->expr());
        if(node->expr->type != "int")
        {
            cout << "Type mismatch : array indexed at non integer literal" << endl;
            exit(1);
        }
        return (ASTVariable *) node;
    }

    virtual antlrcpp::Any visitDarVar(ExprParser::DarVarContext *context) 
    {
        cout << "In visitDarVar" << endl;
        ASTDarVar *node = new ASTDarVar();
        node->id = context->ID()->getText();
        int sz = SymbolTable.size();
        SymbolTable[sz-1].addScope(node->id,latestDatatype);
        node->expr1 = visit(context->expr(0));
        node->expr2 = visit(context->expr(1));
        if(node->expr1->type != "int" || node->expr2->type != "int")
        {
            cout << "Type mismatch : array indexed at non integer literal" << endl;
            exit(1);
        }
        return (ASTVariable *) node;
    }

    virtual antlrcpp::Any visitIntLit(ExprParser::IntLitContext *context)
    {
        cout << "In visitIntLit" << endl;
        ASTIntLit *node = new ASTIntLit();
        node->type = "int";
        node->intlit = stoi(context->Int_literal()->getText());
        return (ASTLiteral *) node;
    }

    virtual antlrcpp::Any visitFloatLit(ExprParser::FloatLitContext *context)
    {
        cout << "In visitFloatLit" << endl;
        ASTFloatLit *node = new ASTFloatLit();
        node->type = "float";
        node->floatlit = stof(context->Float_literal()->getText());
        return (ASTLiteral *) node;
    }

    virtual antlrcpp::Any visitStringLit(ExprParser::StringLitContext *context)
    {
        cout << "In visitStringLit" << endl;
        ASTStringLit *node = new ASTStringLit();
        node->type = "string";
        node->stringlit = context->String_literal()->getText();
        return (ASTLiteral *) node;
    }

    virtual antlrcpp::Any visitCharLit(ExprParser::CharLitContext *context)
    {
        cout << "In visitCharLit" << endl;
        ASTCharLit *node = new ASTCharLit();
        node->type = "char";
        string tmpstr = context->Char_literal()->getText();
        node->charlit = tmpstr[0];
        return (ASTLiteral *) node;
    }

    virtual antlrcpp::Any visitBoolLit(ExprParser::BoolLitContext *context)
    {
        cout << "In visitBoolLit" << endl;
        ASTBoolLit *node = new ASTBoolLit();
        node->type = "bool";
        string tmpstr = context->Bool_literal()->getText();
        if(tmpstr[0] == '0')
            node->boollit = false;
        else
            node->boollit = true;
        return (ASTLiteral *) node;
    }

    virtual antlrcpp::Any visitDatatype(ExprParser::DatatypeContext *context)
    {
        cout << "In visitDatatype" << endl;
        return (ASTDatatype *) nullptr;
    }
};