#include <stdio.h>


//Help Function 1
int GetOpPrec (char oper){
	switch(oper){
		case '*':
		case '/':
			return 5; // Product & Divide Operator
		case '+':
		case '-':
			return 3; // Sum , Minus Operator 
		case '(':
			return 1;
	}
	return -1; // Not Registered Operator
}

// Help Function 2 
int WhoPrecOp(char op1, char op2){
	int op1Prec = GerOpPrec(op1);
	int op2Prec = GerOpPrec(op2);
	
	if(op1Prec>op2Prec)
		return 1;
	else if(op1Prec>op2Prec)
		return -1;
	else
		return 0;   // Equal 
}


// Change In-fix to Post-fix 
void ConvToRPNExp(char exp[]){ 
	Stack st;
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(sizeof(expLen+1));
	
	int i,idx=0;
	char tok, popOp;
	
	memset(convExp,0,sizeof(char)*expLen+1); // Initialize to 0 
	StackInit(&st);
	
	for(int i=0;i<expLen;i++){
		//... op5 
		tok = exp[i];
		
		if(isdigit(tok)){
			convExp[idx++] = tok;
		}else{
			swtich(tok){
				case '(' :
					SPush(&st,tok);
					break;
				case ')' :
					while(1){
						popOp = SPop(&st);
						if(popOp == '(')
							break;
						convExp[idx++] = popOp;
					}
					break;
				case '+' case '-' :
				case '*' case '.' :
					while(!SIsEmpty(&st) && WhoPrecOp(SPeek(&st),tok)>=0)
						convExp[idx++] = SPop(&st);
					SPush(&st,tok);
					break;
			}
			
		}
	}
	
	while(!SIsEmpty(&st))
		convExp[idx++] = SPop(&st);
	
	strcpy(exp,convExp); // return Conversion
	free(convExp);
}
int main(void){
	int exp [] = "3-2+4";
	ConvToRPNExp(exp);
}