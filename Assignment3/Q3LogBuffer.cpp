#include<iostream>

using namespace std;

class LogBuffer{
    char *buffer;
    int capacity;
    int size;
    static int instanceCount;
    public:
    LogBuffer(int capacity):capacity(capacity),size(0){

        buffer= new char[capacity+1]; // beause in c there is a Null Character at end

         buffer[0]='\0';
        cout<<"[LogBuffer Created] capacity="<<capacity<<endl;
           instanceCount++;
    }


    LogBuffer(const LogBuffer& other){
           capacity=other.capacity;
           size=other.size;
           buffer=new char[capacity+1];
           for(int i=0; i<size; i++){
            buffer[i]=other.buffer[i];
           }

            buffer[size] = '\0';

           cout<<"[LogBuffer Deep Copied] capacity="<<capacity<<endl;
             instanceCount++;
        }

   LogBuffer& operator=(const LogBuffer& other)
{
    if(this == &other)
    {
        cout << "[Self-assignment detected - no operation]"
             << endl;

        return *this;
    }

    delete[] buffer;

    capacity=other.capacity;
    size = other.size;

    buffer =new char[capacity + 1];

    for(int i=0; i<size; i++)
    {
        buffer[i]=other.buffer[i];
    }

    buffer[size]= '\0';

    cout<<"[LogBuffer Assigned] capacity="
         <<capacity<<endl;

    return *this;
}

    ~LogBuffer(){
        delete[] buffer;
        instanceCount--;
        cout << "[LogBuffer Destroyed]" << endl;
    }

    void append(const char* msg){
       int i=0;
       while(msg[i]!='\0'&& size<capacity){
        buffer[size]=msg[i];
        i++;
        size++;
       }
       buffer[size]='\0';  //\0 represent character stoped eg hello\0
    }
    void print()const{
         cout<<buffer<<endl;
    }
    void clear(){
      size=0;
       buffer[0]='\0';
    }

    static int getInstanceCount(){
       return instanceCount;
    }

};

int LogBuffer::instanceCount = 0;

int main(){
    LogBuffer log1(256);
    log1.append("Server started on port 8080");
    log1.append(" | request recevied from 192.168.1.10");
    log1.print();

    LogBuffer log2=log1;
    log2.append(" | cached response sent");
    cout<<"Log1 : "; log1.print();
    cout<<"Log2 : "; log2.print();

    LogBuffer log3(128);
    log3=log1;
    log3.print();

    log1=log1;
    log1.print();

    cout<<"Live LogBuffer Objects : "<< LogBuffer::getInstanceCount()<<endl;
    return 0;
}