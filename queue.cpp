#include <iostream>
#include <list> 
#include <initializer_list>
using namespace std;
template <typename T>
class LL{                                           //abstract CLass LL
    protected: 
        list<T> ll;
        size_t size;
    public:
        LL():size(0){}          //default constructor        
        LL(const std::initializer_list<T>& l):size(0){ // initializer_list constructor
            for(T i: l){
                push(i);
                size++;
            }
        }
        //LL(const LL& arr);
        virtual void push(T elem)=0;
        virtual T front()=0;
        virtual bool isEmpty()=0;
        virtual T pop()=0;
        virtual void clear()=0;
};
template <typename T>
class my_queue:protected LL<T>{
    public:
        my_queue():LL<T>(){}

        my_queue(const std::initializer_list<T>& l):LL<T>(l){}
        my_queue(const my_queue& arr):LL<T>(arr){}
        void push(T elem){
                LL<T>::ll.push_back(elem);
                LL<T>::size++;
        }
        T front(){
            return LL<T>::ll.front();         
        }
        bool isEmpty(){
            return LL<T>::size==0;
        }
        T pop(){
            T m=LL<T>::ll.front();
            LL<T>::ll.pop_front();
            LL<T>::size--;
            return m;
        }
        void clear(){
            LL<T>::size=0;
            LL<T>::ll.clear();
        }
};
int main(){
    my_queue<int> arr;
    cout<<arr.isEmpty()<<endl;
    for(int i=0;i<10;i++)   arr.push(i*i*i);

    cout<<arr.front()<<endl;
    arr.pop();
    while(!arr.isEmpty()){
        cout<<arr.front()<<endl;
        arr.pop();
    }
    cout<<"______________\n";
    for(int i=0;i<10;i++)   arr.push(i*i*i*i);
    cout<<arr.isEmpty()<<endl;
    arr.clear();
    cout<<arr.isEmpty()<<endl;
    return 0;
}