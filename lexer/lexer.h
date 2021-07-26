#ifndef __LEXER_H_
#define __LEXER_H_

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Tag {
public: 
      static const int AND;   
      static const int BASIC;    
      static const int BREAK;    
      static const int DO;   
      static const int ELSE;
      static const int EQ;    
      static const int FALSE;    
      static const int GE;
      static const int ID;   
      static const int IF;
      static const int INDEX; 
      static const int LE;       
      static const int MINUS;    
      static const int NE;   
      static const int NUM;
      static const int OR;    
      static const int REAL;     
      static const int TEMP;     
      static const int TRUE; 
      static const int WHILE;
};

class Token {
public: 
        Token(int t) { tag = t;}
      
        string toString();
public:
      int tag;
};

class Num : public Token {
public:
      Num(int v):Token(Tag::NUM) {
            value = v;
      }
      string toString();
public:
      int value;
};

class Word: public Token {
public:
      Word(const string& s, int tag):Token(tag){
            lexeme = s;
      }
      string toString();
      static Word *And, *Or, *Eq, *Ne, *Le, *Ge, *Minus, *True, *False, *Temp;
public:
      string lexeme;
};

class Real: public Token {
public:
      Real(float v):Token(Tag::REAL) { value = v;}
      string toString();
public:
      float value;
};

class Lexer {
public:
      Lexer ();
      void reserve(const Word &w); 

public:
      static const int line;
      char peak;
      map<string, Word> words;
};

#endif 
