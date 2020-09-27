from sly import Lexer

class CalcLexer(Lexer):
    # Set of token names.   This is always required
    tokens = { GROUP, STUDENT, ASSIGN, CONTAINS, AGE, EQUALS, DASH, ID, NUMBER, TIMES, DIVIDE,
               LPAREN, RPAREN, NEWLINE, TYPEOFDATASTUDENT, TYPEOFDATAGROUP, INSERT, COMMENT, NAME}

    # String containing ignored characters between tokens
    ignore = ' \t , \n'

    # Regular expression rules for tokens
    ID     = r'[a-zA-Z_][a-zA-Z_]*'
    NAME = r'[TYPEOFDATASTUDENT][a-zA-Z][a-zA-z]*'
    COMMENT = r'\#.*'
    ID['gr'] = TYPEOFDATAGROUP
    ID['st'] = TYPEOFDATASTUDENT
    GROUP = r'[a-zA-Z-_][a-zA-Z0-9-_]*'
    INSERT = r'append'
    NUMBER  = r'\d+'
    APPEND = 

if __name__ == '__main__':
    f = open('/Users/J.C/Library/Preferences/PyCharm2019.3/scratches/scratch.txt')
    data = f.read()
    print(data+'\n')
    lexer = CalcLexer()
    for tok in lexer.tokenize(data):
        print('type=%r, value=%r' % (tok.type, tok.value))
