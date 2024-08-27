力扣Leetcode 20 有效括号 c语言
link->
  https://leetcode.com/problems/valid-parentheses/solutions/5615342/simplified-code-in-c/

video->
  https://www.youtube.com/watch?v=2NFQd-jyX48


bool isValid(char* s) {
int n = strlen(s);
char* stack = (char*)malloc(n * sizeof(s));
int t = -1;

for(int i = 0; s[i]; i++) {
    char ch = s[i];
    
    if(ch == '(' || ch == '{' || ch == '[') {
        stack[++t] = ch;
    } else {
        if(t == -1) return false;  
        char open = stack[t--];
        if((ch == ')' && open != '(') ||
           (ch == '}' && open != '{') ||
           (ch == ']' && open != '[')) {
            return false; 
        }
    }
}

return t == -1;
}
-----------------------------------------------------------------------------------------------------------------------
  //Don's solution
  bool isValid(char* s) {
      int strengLength=strlen(s);
      int counter=0;
      for (int i=0;i<strengLength;i++)
      {
        char ch=s[i];
        switch(ch):
          case ')':

          break;
        default:
          break;
        
      }

  }
