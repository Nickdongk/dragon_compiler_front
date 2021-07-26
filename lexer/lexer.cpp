#include "lexer.h"


static const int    AND   = 256;   
static const int    BASIC   = 257;    
static const int    BREAK   = 258;    
static const int    DO      = 259;   
static const int    ELSE    = 260;
static const int    EQ      = 261;    
static const int    FALSE   = 262;    
static const int    GE      = 263;    
static const int    ID      = 264;   
static const int    IF      = 265;
static const int    INDEX   = 266; 
static const int    LE      = 267;       
static const int    MINUS   = 268;    
static const int    NE      = 269;   
static const int    NUM     = 270;
static const int    OR      = 271;    
static const int    REAL    = 272;     
static const int    TEMP    = 273;     
static const int    TRUE    = 273; 
static const int    WHILE   = 275;

string Token::toString()
{
    return "" + to_string(tag);
}

string Num::toString() 
{
    return "" + to_string(value);
}

string Word::toString()
{
    return lexeme;
}

Word *Word::And = new Word("&&", Tag::AND);
Word *Word::Or = new Word("||", Tag::OR);
Word *Word::Eq = new Word("==", Tag::EQ);
Word *Word::Ne = new Word("!=", Tag::NE);
Word *Word::Le = new Word("<=", Tag::LE);
Word *Word::Ge = new Word(">=", Tag::GE);
Word *Word::Minus = new Word("minus", Tag::MINUS);
Word *Word::True = new Word("true", Tag::TRUE);
Word *Word::False = new Word("false", Tag::FALSE);
Word *Word::Temp = new Word("t", Tag::TEMP);

string Real::toString()
{
     return "" + to_string(value);
}

Lexer::Lexer() 
{
    reserve(Word("if", Tag::IF));
    reserve(Word("else", Tag::ELSE));
    reserve(Word("while", Tag::WHILE));
    reserve(Word("do", Tag::DO));
    reserve(Word("break", Tag::BREAK));
    reserve(*Word::True);
    reserve(*Word::False);
    /*add type unit*/
    reserve(*Word)
     
}

void Lexer::reserve(const Word& w) 
{
    words.insert(make_pair(w.lexeme, w));
}



