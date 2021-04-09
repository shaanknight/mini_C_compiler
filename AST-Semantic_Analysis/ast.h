#include <string>
#include <vector>

using namespace std;

class ASTProg;
class ASTStartup;
class ASTBlankStart;
class ASTVarStart;
class ASTFuncStart;
class ASTFunction;
class ASTFunctionDef;
class ASTArguments;
class ASTSingleArg;
class ASTMultiArg;
class ASTBlock;
class ASTStatements;
class ASTBlankStats;
class ASTRecStats;
class ASTStatement;
class ASTIfStat;
class ASTAsgStat;
class ASTIfelseStat;
class ASTTernaryStat;
class ASTVarStat;
class ASTOtpStat;
class ASTFilClsStat;
class ASTInpStat;
class ASTForStat;
class ASTFilInpOpnStat;
class ASTFilOtpStat;
class ASTFuncCallStat;
class ASTFilInpStat;
class ASTFilOutOpnStat;
class ASTRetStat;
class ASTWhileStat;
class ASTAssignmentStatement;
class ASTDarAsg;
class ASTVarAsg;
class ASTArAsg;
class ASTVarassign;
class ASTCondition;
class ASTOrCond;
class ASTAndCond;
class ASTParanCond;
class ASTNotCond;
class ASTBaseCond;
class ASTExpr;
class ASTDaracExpr;
class ASTVaracExpr;
class ASTModExpr;
class ASTRelopExpr;
class ASTOrExpr;
class ASTXorExpr;
class ASTEqopExpr;
class ASTAdsubExpr;
class ASTFunccallExpr;
class ASTMulExpr;
class ASTAracExpr;
class ASTDivExpr;
class ASTParanExpr;
class ASTLitExpr;
class ASTAndExpr;
class ASTExps;
class ASTExprExps;
class ASTMulexprExps;
class ASTVariableDef;
class ASTVars;
class ASTVarVars;
class ASTMulVars;
class ASTVariable;
class ASTDarVar;
class ASTIdVar;
class ASTArVar;
class ASTLiteral;
class ASTIntLit;
class ASTCharLit;
class ASTBoolLit;
class ASTFloatLit;
class ASTStringLit;
class ASTBlankArg;
class ASTDatatype;

class ASTvisitor
{
public:
    virtual void visit(ASTProg &node) = 0;
    virtual void visit(ASTStartup &node) = 0;
    virtual void visit(ASTBlankStart &node) = 0;
    virtual void visit(ASTVarStart &node) = 0;
    virtual void visit(ASTFuncStart &node) = 0;
    virtual void visit(ASTFunction &node) = 0;
    virtual void visit(ASTFunctionDef &node) = 0;
    virtual void visit(ASTArguments &node) = 0;
    virtual void visit(ASTSingleArg &node) = 0;
    virtual void visit(ASTMultiArg &node) = 0;
    virtual void visit(ASTBlock &node) = 0;
    virtual void visit(ASTStatements &node) = 0;
    virtual void visit(ASTBlankStats &node) = 0;
    virtual void visit(ASTRecStats &node) = 0;
    virtual void visit(ASTStatement &node) = 0;
    virtual void visit(ASTIfStat &node) = 0;
    virtual void visit(ASTAsgStat &node) = 0;
    virtual void visit(ASTIfelseStat &node) = 0;
    virtual void visit(ASTTernaryStat &node) = 0;
    virtual void visit(ASTVarStat &node) = 0;
    virtual void visit(ASTOtpStat &node) = 0;
    virtual void visit(ASTFilClsStat &node) = 0;
    virtual void visit(ASTInpStat &node) = 0;
    virtual void visit(ASTForStat &node) = 0;
    virtual void visit(ASTFilInpOpnStat &node) = 0;
    virtual void visit(ASTFilOtpStat &node) = 0;
    virtual void visit(ASTFuncCallStat &node) = 0;
    virtual void visit(ASTFilInpStat &node) = 0;
    virtual void visit(ASTFilOutOpnStat &node) = 0;
    virtual void visit(ASTRetStat &node) = 0;
    virtual void visit(ASTWhileStat &node) = 0;
    virtual void visit(ASTAssignmentStatement &node) = 0;
    virtual void visit(ASTDarAsg &node) = 0;
    virtual void visit(ASTVarAsg &node) = 0;
    virtual void visit(ASTArAsg &node) = 0;
    virtual void visit(ASTVarassign &node) = 0;
    virtual void visit(ASTCondition &node) = 0;
    virtual void visit(ASTOrCond &node) = 0;
    virtual void visit(ASTAndCond &node) = 0;
    virtual void visit(ASTParanCond &node) = 0;
    virtual void visit(ASTNotCond &node) = 0;
    virtual void visit(ASTBaseCond &node) = 0;
    virtual void visit(ASTExpr &node) = 0;
    virtual void visit(ASTDaracExpr &node) = 0;
    virtual void visit(ASTVaracExpr &node) = 0;
    virtual void visit(ASTModExpr &node) = 0;
    virtual void visit(ASTRelopExpr &node) = 0;
    virtual void visit(ASTOrExpr &node) = 0;
    virtual void visit(ASTXorExpr &node) = 0;
    virtual void visit(ASTEqopExpr &node) = 0;
    virtual void visit(ASTAdsubExpr &node) = 0;
    virtual void visit(ASTFunccallExpr &node) = 0;
    virtual void visit(ASTMulExpr &node) = 0;
    virtual void visit(ASTAracExpr &node) = 0;
    virtual void visit(ASTDivExpr &node) = 0;
    virtual void visit(ASTParanExpr &node) = 0;
    virtual void visit(ASTLitExpr &node) = 0;
    virtual void visit(ASTAndExpr &node) = 0;
    virtual void visit(ASTExps &node) = 0;
    virtual void visit(ASTExprExps &node) = 0;
    virtual void visit(ASTMulexprExps &node) = 0;
    virtual void visit(ASTVariableDef &node) = 0;
    virtual void visit(ASTVars &node) = 0;
    virtual void visit(ASTVarVars &node) = 0;
    virtual void visit(ASTMulVars &node) = 0;
    virtual void visit(ASTVariable &node) = 0;
    virtual void visit(ASTDarVar &node) = 0;
    virtual void visit(ASTIdVar &node) = 0;
    virtual void visit(ASTArVar &node) = 0;
    virtual void visit(ASTLiteral &node) = 0;
    virtual void visit(ASTIntLit &node) = 0;
    virtual void visit(ASTCharLit &node) = 0;
    virtual void visit(ASTBoolLit &node) = 0;
    virtual void visit(ASTFloatLit &node) = 0;
    virtual void visit(ASTStringLit &node) = 0;
    virtual void visit(ASTBlankArg &node) = 0;
    virtual void visit(ASTDatatype &node) = 0;
};

class ASTnode
{
public:
    virtual ~ASTnode()
    {
    }

    //  virtual void printPostFix() const = 0;

    virtual void accept(ASTvisitor &V) = 0;
};

class ASTProg : public ASTnode
{
public:
    ASTStartup *stu;
    ASTBlock *blk;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStartup : public ASTnode
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTBlankStart : public ASTStartup
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVarStart : public ASTStartup
{
public:
    ASTVariableDef *vdef;
    ASTStartup *stu;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTFuncStart : public ASTStartup
{
public:
    ASTFunction *func;
    ASTStartup *stu;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTFunction : public ASTnode
{
public:
    ASTFunctionDef *funcdef;
    ASTBlock *blk;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTFunctionDef : public ASTnode
{
public:
    string datatype;
    string ID;
    ASTArguments *args;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTArguments : public ASTnode
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTSingleArg : public ASTArguments
{
public:
    string datatype;
    string ID;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTMultiArg : public ASTArguments
{
public:
    string datatype;
    string ID;
    ASTArguments *args;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTBlankArg : public ASTArguments
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTBlock : public ASTnode
{
public:
    ASTStatements *stats;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatements : public ASTnode
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTBlankStats : public ASTStatements
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTRecStats : public ASTStatements
{
public:
    ASTStatement *stat;
    ASTStatements *recstats;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatement : public ASTnode
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTIfStat : public ASTStatement
{
public:
    ASTCondition *cond;
    ASTBlock *blk;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTAsgStat : public ASTStatement
{
public:
    ASTAssignmentStatement *asg;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTIfelseStat : public ASTStatement
{
public:
    ASTCondition *cond;
    ASTBlock *blk1;
    ASTBlock *blk2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTTernaryStat : public ASTStatement
{
public:
    ASTCondition *cond;
    ASTVarassign *varas1;
    ASTVarassign *varas2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVarStat : public ASTStatement
{
public:
    ASTVariableDef *vdef;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTOtpStat : public ASTStatement
{
public:
    ASTExpr *expr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTFilClsStat : public ASTStatement
{
public:
    string id;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTInpStat : public ASTStatement
{
public:
    ASTExpr *expr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTForStat : public ASTStatement
{
public:
    ASTVarassign *varasg1;
    ASTVarassign *varasg2;
    ASTCondition *cond;
    ASTBlock *blk;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTFilInpOpnStat : public ASTStatement
{
public:
    string id;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTFilOtpStat : public ASTStatement
{
public:
    ASTExpr *expr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTFuncCallStat : public ASTStatement
{
public:
    string id;
    ASTExps *params;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTFilInpStat : public ASTStatement
{
public:
    ASTExpr *expr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTFilOutOpnStat : public ASTStatement
{
public:
    string id;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTRetStat : public ASTStatement
{
public:
    ASTExpr *expr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTWhileStat : public ASTStatement
{
public:
    ASTCondition *cond;
    ASTBlock *blk;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTAssignmentStatement : public ASTnode
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTDarAsg : public ASTAssignmentStatement
{
public:
    string id;
    ASTExpr *expr1;
    ASTExpr *expr2;
    ASTExpr *expr3;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVarAsg : public ASTAssignmentStatement
{
public:
    string id;
    ASTExpr *expr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTArAsg : public ASTAssignmentStatement
{
public:
    string id;
    ASTExpr *expr1;
    ASTExpr *expr2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVarassign : public ASTnode
{
public:
    string id;
    ASTExpr *expr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTCondition : public ASTnode
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTOrCond : public ASTCondition
{
public:
    ASTCondition *cond1;
    ASTCondition *cond2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTAndCond : public ASTCondition
{
public:
    ASTCondition *cond1;
    ASTCondition *cond2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTParanCond : public ASTCondition
{
public:
    ASTCondition *cond;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTNotCond : public ASTCondition
{
public:
    ASTCondition *cond;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTBaseCond : public ASTCondition
{
public:
    ASTExpr *expr1;
    string relop;
    ASTExpr *expr2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExpr : public ASTnode
{
public:
    string type;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTDaracExpr : public ASTExpr
{
public:
    string id;
    ASTExpr *expr1;
    ASTExpr *expr2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVaracExpr : public ASTExpr
{
public:
    string id;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTModExpr : public ASTExpr
{
public:
    ASTExpr *expr1;
    ASTExpr *expr2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTRelopExpr : public ASTExpr
{
public:
    ASTExpr *expr1;
    string relop;
    ASTExpr *expr2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTOrExpr : public ASTExpr
{
public:
    ASTExpr *expr1;
    ASTExpr *expr2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTXorExpr : public ASTExpr
{
public:
    ASTExpr *expr1;
    ASTExpr *expr2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTEqopExpr : public ASTExpr
{
public:
    ASTExpr *expr1;
    string eqop;
    ASTExpr *expr2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTAdsubExpr : public ASTExpr
{
public:
    ASTExpr *expr1;
    string adsub;
    ASTExpr *expr2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTFunccallExpr : public ASTExpr
{
public:
    string id;
    ASTExps *exps;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTMulExpr : public ASTExpr
{
public:
    ASTExpr *expr1;
    ASTExpr *expr2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTAracExpr : public ASTExpr
{
public:
    string id;
    ASTExpr *expr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTDivExpr : public ASTExpr
{
public:
    ASTExpr *expr1;
    ASTExpr *expr2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTParanExpr : public ASTExpr
{
public:
    ASTExpr *expr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTLitExpr : public ASTExpr
{
public:
    ASTLiteral *litexpr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTAndExpr : public ASTExpr
{
public:
    ASTExpr *expr1;
    ASTExpr *expr2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExps : public ASTnode
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprExps : public ASTExps
{
public:
    ASTExpr *expr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTMulexprExps : public ASTExps
{
public:
    ASTExpr *expr;
    ASTExps *exps;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVariableDef : public ASTnode
{
public:
    string datatype;
    ASTVars *vars;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVars : public ASTnode
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVarVars : public ASTVars
{
public:
    ASTVariable *var;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTMulVars : public ASTVars
{
public:
    ASTVariable *var;
    ASTVars *vars;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVariable : public ASTnode
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTIdVar : public ASTVariable
{
public:
    string id;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTDarVar : public ASTVariable
{
public:
    string id;
    ASTExpr *expr1;
    ASTExpr *expr2;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTArVar : public ASTVariable
{
public:
    string id;
    ASTExpr *expr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTLiteral : public ASTnode
{
public:
    string type;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTIntLit : public ASTLiteral
{
public:
    int intlit;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTCharLit : public ASTLiteral
{
public:
    char charlit;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTBoolLit : public ASTLiteral
{
public:
    bool boollit;

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTFloatLit : public ASTLiteral
{
public:
    float floatlit;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStringLit : public ASTLiteral
{
public:
    string stringlit;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTDatatype : public ASTnode
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }  
};

class ASTContext
{
public:
    ASTnode *root;

    ~ASTContext()
    {
        clearAST();
    }

    /// free all saved expression trees
    void clearAST()
    {
        delete root;
    }
};

class ASTScope
{
public:
    map<string,string> scp;
    void addScope(string name,string type)
    {
        scp[name] = type;
    }
    bool findScope(string name)
    {
        if(scp.find(name) == scp.end())
            return false;
        else
            return true;
    }
    string getType(string name)
    {
        return scp[name];
    }
};

