Please use this Google doc to code during your interview. To free your hands for coding, we recommend that you use a headset or a phone with speaker option.


string Calculate(string arg1, string op, string arg2);

Calculate(“1”, “+”, “2”) == “3”

Test functions:
Test if 1st and 3rd arguments are valid atoi convertibles
Test if 2nd arg is of strlen(1) andTest validity of the 2nd operator ( +-/*%) 
Check if return string is a valid number
Check if arg number are 3 and not more or less
Check if args are strings
Test recursion



class Iterator {
public:
  Iterator(const vector<int>&);
  virtual int Next();
  virtual bool HasNext();
}

class IteratorImpl : public Iterator {
	
};

A: a1, a2
B: b1
C: c1, c2, c3

//output??
I: a1, b1, c1, a2, c2, c3

i = new MyIterator(A, B, C);
while (i.HasNext()) {
  print i.Next();
}


class MyIterator : public Iterator {
int curr_pos, curr_vec;
vector<Iterator> V;
public:
MyIterator(vector<int>, vector<int>, vector<int>);
int Next();
};

MyIterator::MyIterator(vector<int> A, vector<int> B, vector<int> C) {

	
	V.push_back(A.begin());
V.push_back(B.begin());
V.push_back(C.begin());
curr_pos = 0;
curr_vec = 0;

}

int
MyIterator::Next() {
	int temp;
	int vector_num = V.size();
	
	for (i = curr_vec ; i < vector_num; i++) {		
		temp = V[i].next();
		if (curr_vec == (vector_num-1))
			curr_vec = 0;
		else
			curr_vec++;
		break;
	}
	return (temp);
			
}

bool MyIterator::HasNext() {
	if (!V[curr_vec].hasNext()) {
		
		do {
if (curr_vec == (vector_num-1))
			curr_vec = 0;
		else
			curr_vec++;
		}while(V[curr_vec].hasNext());

		
	}
	else {
		
	}
		

