#ifndef MYSTACK_H
#define MYSTACK_H
#define MAX_SIZE 10000

template <class T>
class mystack{
  private:
        // Declare necessary variables and methods
	int topNum;
	T *stack;
	T value;
  public:
        mystack(){
		stack = new T[MAX_SIZE];
		topNum = -1;
	}
/*        void push(T x);
        T top();
        T pop();
        bool empty();
        int size();
*/


	void push(T x){
		stack[topNum+1] = x;
		topNum++;
	}
	T top(){
		if(!empty()) return stack[topNum];
		else return 0;
	}
	T pop(){
		if(!empty()){
			topNum--;
			return stack[topNum+1];
		}else return 0;
	}
	bool empty(){
		return topNum<0;
	}
	int size(){
		return (topNum+1);
	}
};
#endif
