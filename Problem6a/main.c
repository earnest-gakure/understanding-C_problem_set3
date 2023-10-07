/** @brief Making a simple calculator
    Created on : 3rd oct 2023
    author : Earnest k
 */
//implimenting a simple four-function calculator using stackand queues
//this calculator takes  input space delimited infix expression which is converted into a postfix notation before evaliaion
//Binary operators to handle = + , - , *  , / 
//unary operators = - (negatioon operator)

/*Pseudocode 
function enqueue (pqueue , ptoken)
    set ptoken.linked_token to null
    if pqueue.back is not null:
       set pqueue.back.linked_token to ptoken
    else:
      set pqueue.back and pqueue.front to ptoken

function dequeue (pqueue):
    ctreate ptoken and set it to pqueue.front
    if pqueue.front is not null:
        set pqueue.front to ptoken.linked_token
        if ptoken is equal to pqueue.back;
           set pqueue.back to null
        set ptoken.linked_token to null
    Return ptoken :token deleted

function push(ptop , ptoken):
  set ptoken.linked_token to top 
  set ptop to token

function pop(ptop):
  set ptoken to *ptop
  if ptoken is not null :
     set *ptop to ptoken.linked_token
     set ptoken.linked_token to null

    Return ptoken

function new_token (type ,value)
   allocate memeory for ptoken
   set ptoken.type to type
   set ptoken.value to value
   set ptoken.linked_token to null
Rturn ptoken

function expr_to_infix (str)
create  struct token_queue que_infix 
  initialize  queue_infix.front and queue_infix.back to null
   set type to operator 
   read the str token using strtok()
   for each token in strtok(str , DELIMS_STR)
     if token is a single character:
       switch on the character :
       case '+' ,'-','*','/','(',')' 
       in the case that the token falls : set type to OPERATOR ,
        value.op_code to respective case i.e :ADD ,SUBTRACT,MULTIPLY,DIVIDE NEGATE
        for '(' set type to LPARENS and ')' to RPARENS
    else :
    set type to OPERAND , value.operand to strtod(token ,null)
    Enqueue a new token with type and value to que_infix
    Return queue_infix

function infix_to_postfix(pqueue_infix):
  initialize stack_top to null
  initialize queue_postfix.front and queue_postfix.back to NULL
  while there is a token i pqueue_infix :
    set ptoken to dequeue(pqueue_infix)
    switch on ptoken.type :
    case OPERAND:
        Enqueue ptoken to queue_postfix
    case OPERATOR :
     while stack_top is not NULL and stack_top.type is OPERATOR and
     (
                    op_precedence[stack_top.value.op_code] > op_precedence[ptoken.value.op_code] or
                    (op_operands[stack_top.value.op_code] == op_precedence[ptoken.value.op_code] and
                    op_associativity[op_precedence[ptoken.value.op_code]] is LEFT)
        ):
         Enque pop(&stack_top) to queue_postfix
         push ptoken to stack_top
    case LPARENS:
        push ptoken to stack_top
    case RPARENS:
         free ptoken 
           while stack_top is not NULL:
           set ptoken to pop(&stack_top)
           if ptoken.type is LPARENS :
              free ptoken 
              break
            Enqueue ptoken to queue_postfix
    while stack_top is not NULL :
       Enqueue pop(&stack_top) to queuue _postfix
    Return queue_postfix

Function Evaluate_postfix(pqueue_postfix):
      initialize ans to 0.0
      initialize stack_value to NULL
      initialize operands array with size [2]
      initialize ptoken and pvalue
    while pqueue ! NULL
     set ptoken to dequeue(pqueue_postfix)
       switch ptoken.type:
       case OPERAND:
          push ptoken to stack_values
       case OPERATOR:
         for i=0; i<op_operands[ptoken.value.op_code] ; i++:
           Set pvalue to pop(&stack_values)
             set operands[i] to pvalue.value.operand
             free pvalue
        switch on ptoken.value.op_code:
          process operands according to opcode 
         note operands are popped in reverse order 
       push new token with operator result to stack ->push new_token(OPERAND , value) to stack_values
         free ptoken
         set ans to stack_values.value.operand

function evaluate(str)
   copy str to strbuffer:
   strbuffer = strcpy((char *)malloc(strlen(str)+1),str);
	queue_infix = expr_to_infix(strbuffer);
	queue_postfix = infix_to_postfix(&queue_infix);
	ans = evaluate_postfix(&queue_postfix);
	free(strbuffer); 
	return ans;


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* maximum length of input string (including newline character) */
#define INPUT_MAX 2048

/* enable (1) or disable (0) parentheses checking in parsing strings */
/* leave disabled for part (a); enable for part (b) */
#define PARSE_PARENS 1

/* type of token */
enum token_type {
	OPERAND, /* number */
	OPERATOR, /* operator: +, -, *, / */
#if PARSE_PARENS
	LPARENS, /* left parentheses ( */
	RPARENS /* right parentheses ) */
#endif
};

/* operator identifiers (opcodes) */
enum op {
	ADD, /* a+b */
	SUBTRACT, /* a-b (binary) */ 
	MULTIPLY, /* a*b */
	DIVIDE, /* a/b */
	NEGATE /* -a (unary) */
};

/* direction of evaluation (associativity) */
enum assoc {
	LEFT, /* left-to-right (+, binary -, *, /) */
	RIGHT /* right-to-left (unary -) */
};

/* number of operands for each operator type */
const unsigned int op_operands[] = {2, 2, 2, 2, 1};

/* order-of-operations (precedence) (0 = evaluated last) */
const unsigned int op_precedence[] = {0, 0, 1, 1, 2};

/* evaluation direction (associativity) for each precedence level */
const enum assoc op_associativity[] = {LEFT, LEFT, RIGHT};

/* contains value of token */
union token_value {
	double operand; /* numeric value for operand */
	enum op op_code; /* opcode for operators */
};

/* data structure for token */
typedef struct s_expr_token {
	union token_value value; /* numeric value or opcode */
	enum token_type type; /* type of token */

	struct s_expr_token * linked_token; /* linked token in stack/queue */
} * p_expr_token; /* p_expr_token is shorthand for "struct s_expr_token */

 
 /* data structure for queue */
struct token_queue {
	p_expr_token front; /* front of queue, where tokens are dequeued */
	p_expr_token back; /* back of queue, where tokens are added */
};

/* queue functions - enqueue and dequeue */
void enqueue(struct token_queue * pqueue, const p_expr_token ptoken);
p_expr_token dequeue(struct token_queue * pqueue);

/* stack functions - push and pop */
void push(p_expr_token * ptop, const p_expr_token ptoken);
p_expr_token pop(p_expr_token * ptop);

/* creates a new token in dynamic memory (using malloc()) */
p_expr_token new_token(const enum token_type type, const union token_value value);

/* constructs a queue of tokens in infix order from a space-delimited string */
struct token_queue expr_to_infix(char * str);

/* creates a queue of tokens in postfix order from a queue of tokens in infix order */
/* postcondition: returned queue contains all the tokens, and pqueue_infix should be 
   empty */
struct token_queue infix_to_postfix(struct token_queue * pqueue_infix);

/* evalutes the postfix expression stored in the queue */
/* postcondition: returned value is final answer, and pqueue_postfix should be empty */
double evaluate_postfix(struct token_queue * pqueue_postfix);

/* handles evaluation process (calls above functions) for expression string str */
double evaluate(const char * str);

int main(void) {
	char input[INPUT_MAX];
	double ans;
	unsigned int len;

	do {
		printf("Enter an expression to evaluate: ");
		fflush(stdout);
		if (!fgets(input, INPUT_MAX, stdin))
			abort(); /* failed to read stdin */
		
		len = strlen(input);
		/* remove trailing newline character */
		if (len > 0 && input[len-1] == '\n') {
			input[len-1] = '\0';//null terminate string
			--len;//decrement len to reflect removal of the newline character
		}
		if (len == 0) /* empty expression signals exit */
			break;

		/* call evaluation functions */
		ans = evaluate(input);

		/* write result to stdout */
		printf("%s => %g\n", input, ans);
	} while (1);

	return 0;
}

/* enqueue (add) token to end of queue
   input: pqueue - pointer to queue to which you want to enqueue a new token
          ptoken - pointer to token you want to enqueue
   postcondition: token added to end of queue */
void enqueue(struct token_queue * pqueue, const p_expr_token ptoken) {
   //set the linked_token of the token to Null(since it's added to the end)
	ptoken->linked_token = NULL;
    //if the queue is not empty ,update the linked_token of the current back to the new token 
	if (pqueue->back)
		pqueue->back->linked_token = ptoken;
	else /* if empty ,set front and back to the new token */
		pqueue->front = ptoken;
	pqueue->back = ptoken;
}

/* dequeue (remove) token from front of queue
   input: pointer to queue
   output: front token pointer (or NULL, if queue was empty)
   postcondition: token removed from queue */
p_expr_token dequeue(struct token_queue * pqueue) {
	p_expr_token ptoken = pqueue->front;
	if (pqueue->front) {
		pqueue->front = ptoken->linked_token;
        /*if dequeued token was the last token*/
		if (ptoken == pqueue->back) /* at end */
			pqueue->back = NULL;

		ptoken->linked_token = NULL;/*set linked token to null*/
	}
	return ptoken; //returns the dequeued token ,if que was empty this will be null
}

/* push (add) token to top of stack
   input: ptop - pointer to top of stack
          ptoken - token pointer to add
   postcondition: ptop points to the added token */
void push(p_expr_token * ptop, const p_expr_token ptoken) {
	ptoken->linked_token = *ptop;
	*ptop = ptoken;
}

/* pop (remove) token from top of stack 
   input: pointer to top token pointer of stack
   output: top token pointer (or NULL, if stack was empty)
   postcondition: ptop points to next token in stack */
p_expr_token pop(p_expr_token * ptop) {
	p_expr_token ptoken;
    /*if stack is not empty(top is not null)*/
	if ( (ptoken = *ptop) ) {
        /*update  the top of the stack  to point to the next token in stack
        this effectively removes the token from the top of the stack*/
		*ptop = ptoken->linked_token;
        /*set linked token of the poped token to null
          indicating that it is no longer part of stack */
		ptoken->linked_token = NULL;
	}
    /*return the poppped token (or NULL if stack was empty)*/
	return ptoken;
}

/* allocate new token on heap, with specified type and value; the token is initially
   un-linked (field "linked_token" == NULL) 
   note: token must be freed using free() after use */
p_expr_token new_token(const enum token_type type, const union token_value value) {
	p_expr_token ptoken = (p_expr_token)malloc(sizeof(struct s_expr_token));
	ptoken->type = type;
	ptoken->value = value;
	ptoken->linked_token = NULL;
	return ptoken;
}

/* handles evaluation process  for expression string str */
/* returns the final answer */
double evaluate(const char * str) {
	char * strbuffer; /* mutable buffer for string (modified in calls to strtok()) */
	double ans; /* answer to return */
	struct token_queue queue_infix, queue_postfix;

	/* copy str into mutable buffer */
	strbuffer = strcpy((char *)malloc(strlen(str)+1),str);

	/* get queue of tokens in infix order from string buffer */
	queue_infix = expr_to_infix(strbuffer);

	/* get queue of tokens in postfix order from infix-ordered queue */
	queue_postfix = infix_to_postfix(&queue_infix);

	/* get answer from postfix-ordered queue */
	ans = evaluate_postfix(&queue_postfix);

	free(strbuffer); /* free memory from heap */
	return ans;
}

/* constructs a queue of tokens in infix order from a space-delimited string */
struct token_queue expr_to_infix(char * str) {
	struct token_queue queue_infix; /* queue with infix ordering */
	enum token_type type = OPERATOR;
	union token_value value;

	/* initialize the queue to empty */
	queue_infix.front = NULL;
	queue_infix.back = NULL;

	/* delimiter string for strtok() -- contains whitespace characters */
#define DELIMS_STR " \n\r\t"
	for (str = strtok(str, DELIMS_STR); str; str = strtok(NULL, DELIMS_STR)) {
		/* parse token */
		if (strlen(str) == 1) { /* operators are all 1 character */
			switch (str[0]) {
			case '+':
				type = OPERATOR;
				value.op_code = ADD;
				break;
			case '-':
				/* check previous token to distinguish between
				   negate (unary) and subtract (binary) */
				if (type == OPERATOR)
					value.op_code = NEGATE; /* unary */
#if PARSE_PARENS
				else if (type == LPARENS)
					value.op_code = NEGATE; /* unary */
#endif
				else
					value.op_code = SUBTRACT; /* binary */
				type = OPERATOR;
				break;
			case '*':
				type = OPERATOR;
				value.op_code = MULTIPLY;
				break;
			case '/':
				type = OPERATOR;
				value.op_code = DIVIDE;
				break;
#if PARSE_PARENS
			case '(':
				type = LPARENS;
				break;
			case ')':
				type = RPARENS;
				break;
#endif
			default:
				/* not an operator */
				type = OPERAND;
				value.operand = strtod(str, NULL);
			}
		} else {
			type = OPERAND;
			value.operand = strtod(str, NULL);
		}
		/* add token with parsed type and value to end of queue */
		enqueue(&queue_infix, new_token(type, value));
	}
	return queue_infix;
}


/* creates a queue of tokens in postfix order from a queue of tokens in infix order */
/* postcondition: returned queue contains all the tokens, and pqueue_infix should be 
   empty */
struct token_queue infix_to_postfix(struct token_queue * pqueue_infix) {
	/* TODO: construct postfix-ordered queue from infix-ordered queue;
	   all tokens from infix queue should be added to postfix queue or freed */

   p_expr_token stack_top = NULL ,ptoken ;
   struct token_queue queue_postfix;

   queue_postfix.front = queue_postfix.back = NULL;

   for(ptoken = dequeue(pqueue_infix) ; ptoken ; ptoken = dequeue(pqueue_infix))
   {
     switch (ptoken->type)
     {
     case OPERAND:
       /*operands added directly to postfix queue*/
       enqueue(&queue_postfix , ptoken);
        break;
     case OPERATOR :
           /*operator added to stack ,after operators of higher precedence
           are moved to queue*/
     while (stack_top && stack_top->type == OPERATOR &&
     (op_precedence[stack_top->value.op_code] > op_precedence[ptoken->value.op_code] || 
     (op_operands[stack_top->value.op_code] ==  op_precedence[ptoken->value.op_code] && 
     op_associativity[op_precedence[ptoken->value.op_code]] == LEFT)))
     
     enqueue(&queue_postfix , pop(&stack_top));
     push(&stack_top , ptoken);
     break;
     case LPARENS :
      /*pushed to operator stack*/
      push(&stack_top , ptoken);
      break;

     case RPARENS :
     /*pop operators off stack until left parentheses reached*/
     free(ptoken);/*parenthesess not included in postfix queue*/
      while ((ptoken = pop(&stack_top)))
      {
       if (ptoken->type == LPARENS)
       {
       free(ptoken);
       break;
       }
       enqueue(&queue_postfix , ptoken);
      }
     }
   }
   while(stack_top)/*pop remaining operators off stack*/
   enqueue(&queue_postfix , pop(&stack_top));
   return queue_postfix ;

}

 /* evalutes the postfix expression stored in the queue */
/* postcondition: returned value is final answer, and pqueue_postfix should be empty */
double evaluate_postfix(struct token_queue *pqueue_postfix) {
    /* TODO: process postfix-ordered queue and return final answer;
       all tokens from postfix-ordered queue are freed */
    double ans = 0.0;
    p_expr_token stack_values = NULL, ptoken, pvalue;
    double operands[2]; /* max two operands */
    union token_value value;
    int i;

    while ((ptoken = dequeue(pqueue_postfix))) {
        switch (ptoken->type) {
            case OPERAND:
                /* operands always pushed to stack */
                push(&stack_values, ptoken);
                break;
            case OPERATOR:
                /* pop operands from stack */
for (i = 0; i < op_operands[ptoken->value.op_code]; i++) {
    if ((pvalue = pop(&stack_values))) {
        operands[i] = pvalue->value.operand;//the value of the popped operand is stored at operand index i
        free(pvalue); /* done with token */
        //printf("Popped operand %d: %f\n", i, operands[i]);
    } else {
        goto error;
    }
}

                /* process operands according to opcode */
                /* note operands are popped in reverse order */
                switch (ptoken->value.op_code) {
                    case ADD:
                        value.operand = operands[1] + operands[0];
                        break;
                    case SUBTRACT:
                        value.operand = operands[1] - operands[0];
                        break;
                    case MULTIPLY:
                        value.operand = operands[1] * operands[0];
                        break;
                    case DIVIDE:
                        value.operand = operands[1] / operands[0];
                        break;
                    case NEGATE:
                        value.operand = -operands[0];
                        break;
                    default:
                     /* Print an error message for unrecognized operators */
                        printf("Error: Unrecognized operator %d\n", ptoken->value.op_code);
                        goto error;
                        break; /* Handle other operators if needed */
                }
                /* push new token with operator result to stack */
                push(&stack_values, new_token(OPERAND, value));
                // printf("Intermediate result: %f\n", value.operand);
                break;
            default:
                free(ptoken); /* free token */
                break;
        }
    }

    /* return value is on top of stack (should be last value on stack) */
    if (stack_values)
        ans = stack_values->value.operand;

    cleanup:
    /* free any remaining tokens */
    while ((ptoken = dequeue(pqueue_postfix)))
        free(ptoken);
    while ((pvalue = pop(&stack_values)))
        free(pvalue);
    return ans;

    error:
    fputs("Error evaluating the expression.\n", stderr);
    goto cleanup;
}

