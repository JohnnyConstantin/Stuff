from sly import Lexer

class CalcLexer(Lexer):
    # Set of token names.   This is always required
    tokens = { GROUP, STUDENT, FOR, CONTAINS, AGE, EQUALS, DASH, ID, NUMBER, TIMES, DIVIDE,
               LPAREN, RPAREN, TYPE_OF_DATA_STUDENT, TYPE_OF_DATA_GROUP, INSERT, COMMENT, NAME, ADD, TYPE_OF_DATA_AGE, END_OF_CONTAINS,
               END_OF_ADDING}

    # String containing ignored characters between tokens
    ignore = ' \t , \n'

    # Regular expression rules for tokens
    CONTAINS = r'\('
    END_OF_CONTAINS = r'\)'
    NUMBER = r'\d+'
    TYPE_OF_DATA_AGE = r'age'
    NAME = r'(Vasily Pupkin)|(Ivan Ivanov)'
    COMMENT = r'\#.*'
    TYPE_OF_DATA_GROUP = r'gr'
    TYPE_OF_DATA_STUDENT = r'st'
    FOR = r'in'
    ADD = r'append'
    END_OF_ADDING = r'dneppa'
    GROUP = r'[a-zA-Z-_][a-zA-Z0-9-_]*'

if __name__ == '__main__':
    f = open('/Users/J.C/Library/Preferences/PyCharm2019.3/scratches/scratch.txt')
    data = f.read()
    print(data+'\n')
    lexer = CalcLexer()
    for tok in lexer.tokenize(data):
        print('type=%r, value=%r' % (tok.type, tok.value))
