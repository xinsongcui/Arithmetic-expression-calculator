#ifndef MYQUEUE_H
#define MYQUEUE_H
#define MAX_SIZE 10000

template <class T>
class myqueue{
  private:
        // Declare necessary variables and methods
	T *queue;
	int frontNum; 
  public:

	myqueue(){
		queue = new T[MAX_SIZE];
		frontNum = -1;
	}	
	void enqueue(T x){
		if(frontNum<0){
			queue[0] = x;
			frontNum++;
		}
		else{
			for(int i=frontNum; i>-1; i--){
				queue[i+1] = queue[i];
			}
			queue[0] = x;
			frontNum++;
		}
	}
	T front(){
		if(!empty())return queue[frontNum];
		else return 0;
	}
	T dequeue(){
		if(!empty()){
			T temp = queue[frontNum];
			//for(int i=0; i<frontNum; i++){
			//	queue[i] = queue[i+1];
			//}
			frontNum--;
			return temp;
		}else return 0;
	}
	bool empty(){
		if(frontNum<0){
			return true;
		}
		else{
			return false;
		}
	}
	int size(){
		return (frontNum+1);
	}
};

#endif
