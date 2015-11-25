#include <iostream>
#include <unistd.h>
#include <deque>
#include <pthread.h>

using namespace std;




class Thread {
	void* (*startFunc)(void*);
	void* arg;
	public:
	Thread();
	Thread(void*(*)(void*), void*);	
	~Thread();
};

Thread::Thread() {	
	this->startFunc = NULL;
	this->arg = NULL;
}

Thread::Thread(void*(*startF)(void*), void* fArg) {	
	this->startFunc = startF;
	this->arg = fArg;
}


class jobQ {
	int maxsize;
	deque<Thread> jQ;
public:	
	jobQ();
	jobQ(int);
	
	Thread pop();
	int push(Thread);
	int currSize();
};

jobQ::jobQ() {
	int maxsize = 0;	
}

jobQ::jobQ(int size) {
	this->maxsize = size;
			
}

int
jobQ::currSize() {
	return jQ.size();
}

int 
jobQ::push(Thread item) {
	if (this->jQ.size() < (this->maxsize)) {
		this->jQ.push_back(item);
		return(0);
	} else {
		cout<<"Unable to enter the item in freeQ"<<endl;
		return(-1);
	}
}

Thread 
jobQ::pop() {
	Thread popped;
	if(this->jQ.size() != 0) {
		popped = jQ.front();
		this->jQ.pop_front();
		return (popped);
	} 
}




class ThreadPool {	
	pthread_mutex_t thrsigMutex;
	pthread_cond_t condVar;
	int thr_num;	
	Thread* tpool;
	jobQ jQ;
	void intializeTPool();
	void shellFunc();
	
public:
	ThreadPool();
	ThreadPool(int);
	int addJob(Thread);
	bool checkJobQEmpty();
	void jobWalk();
	
};

ThreadPool::ThreadPool(int num) {
	this->thr_num = num;		
	pthread_mutex_init(&thrsigMutex, NULL);
	pthread_cond_init(&condVar, NULL);	
	this->jQ = jobQ(120);
	intializeTPool();
}

int
ThreadPool::addJob(Thread t) {	
	pthread_mutex_lock(&thrsigMutex);
	this->jQ.push(t);
	pthread	
	pthread_mutex_unlock(&thrsigMutex);
}

bool 
ThreadPool::checkJobQEmpty() {	
	if (jQ.currSize() == 0)
		return(true);
	else
		return(false);
	
}

void
ThreadPool::jobWalk() {
	jQ.printQ();
}

void
ThreadPool::intializeTPool() {
	int ret  =-1;
	for(int i=0; i < thr_num; i++) {
		pthread_t tid;

		ret = pthread_create(&tid, NULL, shellFunc, &i);
		if (ret != 0) {
			cout<<"Unable to create thread#:"<<i<<" in threadpool init"<<endl;
			exit(0);
		}
	}	
}

void* 
ThreadPool::shellFunc (void* arg) {
	Thread t;
	while(1) {
		pthread_mutex_lock(&thrsigMutex);		
		pthread_cond_wait(&condVar, &thrsigMutex);		
		t = jQ.pop();
		t.startFunc(t.arg);		
		pthread_mutex_unlock(&thrsigMutex);

	}
}







void* func (void* arg) {
	int *x = (int*)arg;
	cout<<"sleeping for:"<<*x<<endl;
	sleep(*x);
}


int main() {
	int ret = 0;
	Thread t1(1,func,(void*)10);
	Thread t2(2,func,(void*)20);
	Thread t3(3,func,(void*)30);
	Thread t4(4,func,(void*)40);
	Thread t5(5,func,(void*)50);
	
	
	ThreadPool tp(3);
	tp.addJob(t1);
	tp.addJob(t2);
	tp.addJob(t3);
	tp.addJob(t4);
	tp.addJob(t5);
	tp.jobWalk();



	
	
}