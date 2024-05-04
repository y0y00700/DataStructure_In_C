import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class CalcPr {
    static Stack st;
    static int operPr(char op){
        switch(op){
            case '*':
                return 5;
            case '/':
                return 5;
            case '+':
                return 3;
            case '-':
                return 3;
            case '(':
                return 1;
        }
        return -1;
    }
    static int operBet(char op1,char op2){
        int oper1 = operPr(op1);
        int oper2 = operPr(op2);
        if(oper1>oper2)
            return 1;
        else if (oper1<oper2)
            return -1;
        else 
            return 0;
    }

    static char[] changePostFix(char [] exp){
        char [] changeExp = new char[exp.length];
        int counter = 0;
        st = new Stack<Character>();

        for(int i=0;i<exp.length;i++){
            if(Character.isDigit(exp[i])){
                changeExp[counter++] = exp[i];
                System.out.print(changeExp[counter]+" ");
            }else{
                switch (exp[i]) {
                    case '(':
                        st.push((char)exp[i]);
                        break;
                    case ')':
                        while(true){
                            if((char)st.pop()=='(')
                                break;
                            changeExp[counter++] = (char)st.pop();
                            System.out.print(changeExp[counter]+" ");
                        }
                    case '*' : case '/' : case '+' : case '-' :
                        while(!st.empty()&&operBet((char)st.peek(), exp[i])>=0){
                            changeExp[counter++] = (char)st.pop();
                            System.out.print(changeExp[counter]+" ");
                        }
                        st.push((char)exp[i]);
                        break;
                }
            }

            while(!st.empty()){
                changeExp[counter++] = (char)st.pop();
                System.out.print(changeExp[counter]+" ");
            }
            st.clear();

            return changeExp;
        }
        return changeExp;
    }
    
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        System.out.print("Input CalcExp: ");
        char [] exp = br.readLine().toCharArray();

        char [] changedArr = changePostFix(exp);
        for(int i=0;i<changedArr.length;i++){
            sb.append(changedArr[i]+" ");
        }

        System.out.println("changedExp : "+ sb.toString());
        
    }
    
}
