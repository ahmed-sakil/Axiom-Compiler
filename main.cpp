#include <bits/stdc++.h>
using namespace std;

// ==========================================
// PART 1: DEFINITIONS 
// ==========================================

enum OpCode {
    PUSH = 1, ADD = 2, SUB = 3, MUL = 4, DIV = 5,
    PRINT = 6, HALT = 7, STORE = 8, LOAD = 9
};

enum TokenType {
    TOKEN_INT, TOKEN_PRINT, TOKEN_SET, TOKEN_ID,
    TOKEN_ASSIGN, TOKEN_PLUS, TOKEN_MINUS, TOKEN_MUL, TOKEN_DIV,
    TOKEN_LPAREN, TOKEN_RPAREN, TOKEN_SEMI, TOKEN_EOF
};

struct Token {
    TokenType type;
    string text;
};

// ==========================================
// PART 2: THE LEXER 
// ==========================================

class Lexer {
    string src;
    size_t pos = 0;

public:
    Lexer(string source) : src(source) {}

    Token nextToken() {
        while (pos < src.length()) {
            if (isspace(src[pos])) { pos++; continue; }
            if (src[pos] == '/' && pos + 1 < src.length() && src[pos+1] == '/') {
                while (pos < src.length() && src[pos] != '\n') pos++;
                continue;
            }
            break;
        }

        if (pos >= src.length()) return {TOKEN_EOF, ""};

        if (isdigit(src[pos])) {
            string numStr;
            while (pos < src.length() && isdigit(src[pos])) {
                numStr += src[pos]; pos++;
            }
            return {TOKEN_INT, numStr};
        }

        if (isalpha(src[pos])) {
            string word;
            while (pos < src.length() && isalpha(src[pos])) {
                word += src[pos]; pos++;
            }
            if (word == "print") return {TOKEN_PRINT, word};
            if (word == "set") return {TOKEN_SET, word};
            return {TOKEN_ID, word};
        }

        if (src[pos] == '(') { pos++; return {TOKEN_LPAREN, "("}; }
        if (src[pos] == ')') { pos++; return {TOKEN_RPAREN, ")"}; }
        if (src[pos] == ';') { pos++; return {TOKEN_SEMI, ";"}; }
        if (src[pos] == '=') { pos++; return {TOKEN_ASSIGN, "="}; }
        if (src[pos] == '+') { pos++; return {TOKEN_PLUS, "+"}; }
        if (src[pos] == '-') { pos++; return {TOKEN_MINUS, "-"}; }
        if (src[pos] == '*') { pos++; return {TOKEN_MUL, "*"}; }
        if (src[pos] == '/') { pos++; return {TOKEN_DIV, "/"}; }

        cout << "Unexpected: " << src[pos] << endl;
        pos++;
        return {TOKEN_EOF, ""};
    }
};

// ==========================================
// PART 3: THE PARSER 
// ==========================================

class Parser {
    Lexer lexer;
    Token currentToken;
    vector<int> bytecode;
    map<string, int> symbolTable;
    int nextMemoryAddr = 0;

    void eat(TokenType type) {
        if (currentToken.type == type) {
            currentToken = lexer.nextToken();
        } else {
            cerr << "Parser Error: Expected token type " << type 
                 << " but got " << currentToken.text << endl;
            exit(1);
        }
    }

    void emit(int instruction) { bytecode.push_back(instruction); }

    int getVariableAddress(string name) {
        if (symbolTable.find(name) == symbolTable.end()) symbolTable[name] = nextMemoryAddr++;
        return symbolTable[name];
    }

    // --- PROTOTYPE ONLY ---
    // We declare it here so parseFactor can see it.
    // We will define the body OUTSIDE the class.
    void parseExpression(); 

    void parseFactor() {
        if (currentToken.type == TOKEN_INT) {
            emit(PUSH);
            emit(stoi(currentToken.text));
            eat(TOKEN_INT);
        } 
        else if (currentToken.type == TOKEN_ID) {
            int addr = getVariableAddress(currentToken.text);
            emit(LOAD);
            emit(addr);
            eat(TOKEN_ID);
        } 
        else if (currentToken.type == TOKEN_LPAREN) {
            eat(TOKEN_LPAREN);
            parseExpression(); // Recursion
            eat(TOKEN_RPAREN);
        }
        else {
            cerr << "Error: Expected Integer, Variable, or (" << endl;
            exit(1);
        }
    }

    void parseTerm() {
        parseFactor();
        while (currentToken.type == TOKEN_MUL || currentToken.type == TOKEN_DIV) {
            TokenType op = currentToken.type;
            eat(op);
            parseFactor();
            if (op == TOKEN_MUL) emit(MUL); else emit(DIV);
        }
    }

    void parseStatement() {
        if (currentToken.type == TOKEN_PRINT) {
            eat(TOKEN_PRINT);
            parseExpression();
            emit(PRINT);
            eat(TOKEN_SEMI);
        } else if (currentToken.type == TOKEN_SET) {
            eat(TOKEN_SET);
            string varName = currentToken.text;
            eat(TOKEN_ID);
            eat(TOKEN_ASSIGN);
            parseExpression();
            emit(STORE);
            emit(getVariableAddress(varName));
            eat(TOKEN_SEMI);
        }
    }

public:
    Parser(Lexer l) : lexer(l) {
        currentToken = lexer.nextToken();
    }

    vector<int> parse() {
        while (currentToken.type != TOKEN_EOF) {
            parseStatement();
        }
        emit(HALT);
        return bytecode;
    }
};

// --- IMPLEMENTATION OF parseExpression ---
// This is defined OUTSIDE the class to fix the circular dependency error.
void Parser::parseExpression() {
    parseTerm();
    while (currentToken.type == TOKEN_PLUS || currentToken.type == TOKEN_MINUS) {
        TokenType op = currentToken.type;
        eat(op);
        parseTerm();
        if (op == TOKEN_PLUS) emit(ADD); else emit(SUB);
    }
}

// ==========================================
// PART 4: THE VIRTUAL MACHINE 
// ==========================================

class VirtualMachine {
    vector<int> bytecode;
    vector<int> stack;
    int globals[256]; 
    int ip = 0;

public:
    VirtualMachine(const vector<int>& code) : bytecode(code) {
        fill(begin(globals), end(globals), 0);
    }

    void run() {
        bool running = true;
        while (running && ip < bytecode.size()) {
            int instruction = bytecode[ip++];
            switch (instruction) {
                case PUSH: stack.push_back(bytecode[ip++]); break;
                case LOAD: stack.push_back(globals[bytecode[ip++]]); break;
                case STORE: {
                    int addr = bytecode[ip++];
                    int val = stack.back(); stack.pop_back();
                    globals[addr] = val;
                    break;
                }
                case ADD: {
                    int b = stack.back(); stack.pop_back();
                    int a = stack.back(); stack.pop_back();
                    stack.push_back(a + b);
                    break;
                }
                case SUB: {
                    int b = stack.back(); stack.pop_back();
                    int a = stack.back(); stack.pop_back();
                    stack.push_back(a - b);
                    break;
                }
                case MUL: {
                    int b = stack.back(); stack.pop_back();
                    int a = stack.back(); stack.pop_back();
                    stack.push_back(a * b);
                    break;
                }
                case DIV: {
                    int b = stack.back(); stack.pop_back();
                    int a = stack.back(); stack.pop_back();
                    if(b==0) { cerr << "Div Zero"; running=false; }
                    else stack.push_back(a / b);
                    break;
                }
                case PRINT: {
                    cout << stack.back() << endl; 
                    stack.pop_back();
                    break;
                }
                case HALT: running = false; break;
            }
        }
    }
};

// ==========================================
// MAIN DRIVER
// ==========================================
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./axiom <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Could not open file '" << filename << "'" << endl;
        return 1;
    }

    string sourceCode((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    Lexer lexer(sourceCode);
    Parser parser(lexer);
    vector<int> bytecode = parser.parse();

    VirtualMachine vm(bytecode);
    vm.run();

    return 0;
}