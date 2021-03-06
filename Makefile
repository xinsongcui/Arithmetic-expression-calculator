all: stack queue expr_eval

stack: stack_main.cpp mystack.h  
	g++ -std=c++11 -o stack stack_main.cpp
	
queue: queue_main.cpp myqueue.h
	g++ -std=c++11 -o queue queue_main.cpp

expr_eval: expr_eval.h expr_eval_main.cpp mystack.h
	g++ -std=c++11 -o expr_eval expr_eval_main.cpp

clean:
	rm -f stack queue expr_eval
