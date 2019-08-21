#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// stuff from Queue lecture goes here ... then apply template on it

#define SIZE 4

//void pause();

template <class T>
class Queue {
    private:
    T q[SIZE];
    int in, out;
    //T xyz;
    bool is_empty, is_full;

    // circular increment
    int inc(int val);

    public:
    Queue();
    void enqueue(T val);  // spell that as ... enq-ue-ue
    T dequeue();          // deq-ue-ue

    //void print_queue();
};

template <class T>
Queue<T>::Queue() {
    // cout << "what do you want to initialize your queue with?" << endl;
    // cin >> xyz;
    // for (int i = 0; i < SIZE; i++) {
    //   q[i] = xyz;
    // }
    in = out = 0;
    is_full = false;
    is_empty = true;
}

template <class T>
int Queue<T>::inc(int val) {
    if (val + 1 == SIZE)         // loop around
        val = 0;
    else
        val += 1;
    return val;
}

template <class T>
void Queue<T>::enqueue(T val) {
    if (is_full) {
        // cout << is_full << endl;
        throw "Queue full. Cannot enqueue ... ";
        // cout << "Nahi kerta!" ;
        // return;
    }
    // cout << is_full << endl;
    // put where in is and increment in
    q[in] = val;
    in = inc(in);

    // check if we are now full
    if (in == out)
        is_full = true;

    // definitely not empty any more
    is_empty = false;
}

template <class T>
T Queue<T>::dequeue() {
    if (is_empty) {
        throw "Queue empty. Cannot dequeue ... ";
    }

    // get from where out is and inc out
    T ret = q[out];
    out = inc(out);

    // see if we are now empty
    if (in == out)
        is_empty = true;

    // definitely not full any more
    is_full = false;

    return ret;
}

// template <class T>
// void Queue<T>::print_queue() {
//     cout << "[\t";
//     for (int i = 0; i < SIZE; i++)
//         cout << q[i] << "\t";
//     cout << "]" << endl;
//
//     cout << " \t";
//     for (int i = 0; i < SIZE; i++)
//         cout << i << "\t";
//     cout << " " << endl;
//
//     cout << " ";
//     for (int i = 0; i <= in; i++)
//         cout << "\t";
//     cout << "^in" << endl;
//
//     cout << " ";
//     for (int i = 0; i <= out; i++)
//         cout << "\t";
//     cout << "^out" << endl;
//
//     //pause();
// }


class Writer {
    // fill stuff here
  public:
    void process_file(string filename,Queue<string> *q);
};

// method definitions for Writer class here
void Writer::process_file(string filename,Queue<string> *q){
  string line;
  ifstream fin;
  fin.open(filename);
  int count = SIZE;
  while (!fin.eof()) {
      count--;
      getline(fin,line);
      q->enqueue(line);
      if (count == 0){
        return;
      }
  }
  fin.close();
}

class Reader {
    // fill stuff  here
  public:
    void process_queue(Queue<string> *q);
};

// method definitions for Reader class here
void Reader::process_queue(Queue<string> *q) {
  string temp;
  for (int i = 0; i < SIZE; i++) {
    temp = q->dequeue();                                                          // omit -1, error not
    cout << "String: " << temp << " has length: " << temp.length() << endl;
  }
}

// q->print_queue();

int main() {
    Queue<string> *que;
    que = new Queue<string>;

    string filename = "string-collection.txt";

    Writer first_writer;
    Reader first_reader;

    try {
      first_writer.process_file(filename, que);
      first_reader.process_queue(que);
    } catch (const char *msg) {
      cout << msg << endl;
    }

    return 0;
}
