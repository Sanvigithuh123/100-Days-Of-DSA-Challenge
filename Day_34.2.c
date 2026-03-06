int calculate(char* s) {
    int num = 0;
    int res = 0;
    int last = 0;
    char op = '+';

    for(int i = 0; s[i] != '\0'; i++) {

        if(s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        }

        if((s[i] < '0' || s[i] > '9') && s[i] != ' ' || s[i+1] == '\0') {

            if(op == '+') {
                res += last;
                last = num;
            }

            else if(op == '-') {
                res += last;
                last = -num;
            }

            else if(op == '*') {
                last = last * num;
            }

            else if(op == '/') {
                last = last / num;
            }

            op = s[i];
            num = 0;
        }
    }

    res += last;
    return res;
}
