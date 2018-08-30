#include <stdio.h>

int removestr(int c);
int removecomment(int c);

int tm; //is this character needs to be escaped
int instr, inchar;
int insc, inmc; /* single-line comments and multi-line comments*/
int last;

int main() {
    int c, t;
    char str[] = "I'd like to say: \"GTMD崔三炮\""; //test removestr
    int count[3], check[3]; //store '(', '[', '{' count, check ')', ']', '}' count

    insc = inmc = instr = inchar = tm = 0;
    for (int i = 0; i < 3; ++i) {
        count[i] = check[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        t = removecomment(c);
        if (t)
            t = removestr(t);
        if (t) {
            //putchar(t);
            if (t == '(')
                count[0]++;
            else if (t == ')')
                check[0]++;
            else if (t == '[')
                count[1]++;
            else if (t == ']')
                check[1]++;
            else if (t == '{')
                count[2]++;
            else if (t == '}')
                check[2]++;
        }
        last = c;
        if (tm)
            tm = 0;
        else if (c == '\\')
            tm = 1;
    }
    
    for (int i = 0; i < 3; ++i) {
        if (count[i] != check[i]) {
            if (i == 0)
                printf("() mismatch\n");
            else if (i == 1)
                printf("[] mismatch\n");
            else if (i == 2)
                printf("{} mismatch\n");
        }
    }

    return 0;
}

int removestr(int c) {
    if (!instr && !inchar) {
        if (c == '"') {
            instr = 1;
        }
        else if (c == '\'') {
            inchar = 1;
        }
    } else if (instr) {
        if (c == '"' && !tm) {
            instr = 0;
        } else {
            return 0;
        }
    } else if (inchar) {
        if (c == '\'' && !tm) {
            inchar = 0;
        } else {
            return 0;
        }
    }

    return c;
}

/* cannot remove the first two characters of the comment
 * but enough :D
 */
int removecomment(int c) {
    if (!insc && !inmc) {
        if (last == '/') {
            if (c == '/')
                insc = 1;
            else if (c == '*')
                inmc = 1;
        }
    } else if (insc) {
        if (c == '\n')
            insc = 0;
        else
            return 0;
    } else if (inmc) {
        if (c == '/' && last == '*') {
            inmc = 0;
            return 0;
        } else 
            return 0;
    }

    return c;
}
