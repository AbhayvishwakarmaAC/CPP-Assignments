#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <type_traits>
#include <stdexcept>
using namespace std;

class DataProcessor{
    string source;
    string destination;
    public:
    virtual void loadData(const string& source) =0;
    virtual void processData()=0;
    virtual void exportResult(const string& destination)=0;
    virtual string processorType() const=0;
    virtual int recordCount() const=0;
    virtual void printSummary() const{
     cout<<"Processor: "<<processorType()<<endl;
     cout<<"Record   : "<<recordCount()<<endl;
    }
    virtual ~DataProcessor()=default;
};

class CSVProcessor:public DataProcessor{
    vector<string> records;
    public:
    void loadData(const string& source) override{
         cout<<"Loading CSV from: "<<source<<endl;
         records.push_back("abhay,mumbai,21");
         records.push_back("rahul,pune,25");
         records.push_back("amit,nashik,23");
         records.push_back("rohit,thane,26");
         records.push_back("karan,nagpur,22");

    }
    void processData()override{
        for(string& record:records){
            for(char& ch:record){
                ch=static_cast<char>(
                    toupper(static_cast<unsigned char>(ch))
                );
            }
        }
    }
    void exportResult(const string& destination)override{
       cout<<"[CSV Export -> "<<destination<<endl;
       for(const string& record:records){
        cout<<record<<endl;
       }
    }
    string processorType()const override{
         return "CSV Processor";
    }
    int recordCount()const override{
        return static_cast<int>(records.size());
    }

    ~CSVProcessor(){

    }
};

class SensorStreamProcessor: public DataProcessor{
    vector<double> readings;
    double mean=0;
    double minimum=0;
    double maximum=0;
   public:
    void loadData(const string& source)override{
        cout<<"Loading Sensor Stream From"<<source<<endl;
        readings={23.4,21.8,25.1,22.6,24.9,26.2,20.7,23.8};
    }
    void processData()override{
        if(readings.empty())
            return;
            double sum=0;
            minimum=readings[0];
            maximum=readings[0];

            for(double value:readings){
                sum=sum+value;
                if(value<minimum)
                  minimum=value;
                  if(value>maximum)
                  maximum=value;
            }
            mean=sum/readings.size();
    }
    void exportResult(const string& destination)override{
      cout<<"[Sensor Export]-> "<<destination<<"]"<<endl;
      cout<<"Mean : "<<mean<<endl;
      cout<<"Min : "<<minimum<<endl;
      cout<<"Max : "<<maximum<<endl;

    }
    string processorType()const override{
        return "Sensor Stream Processor";
    }
    int recordCount()const override{
        return static_cast<int>(readings.size());
    }

    ~SensorStreamProcessor(){
        
    }
};

template <typename T>
class DataBuffer{
  T* data;
  int capacity;
  int head;
  int tail;
  int count;

  public:
      DataBuffer(int capacity):capacity(capacity), head(0),tail(0), count(0){
       data=new T[capacity];
    }
     ~DataBuffer(){
        delete[] data;
     }

     void push(const T& value){
        data[tail]=value;
        tail=(tail+1)%capacity;
        if(count<capacity){
            count++;
        }else{
            head=(head+1)%capacity;
        }
     }

     T pop(){
        if(isEmpty()){
            throw runtime_error("Buffer Empty");
        }

        T value=data[head];
        head=(head+1)%capacity;
        count--;

        return value;
     }

     T peek(){
        if(isEmpty()){
            throw runtime_error("Buffer Empty");
        }
        return data[head];
    }

      bool isEmpty() const{
        return count ==0;
      }
      bool isFull() const{
        return count ==capacity;
      }

      int size() const{
        return count;
      }

    template<typename U>
    friend ostream& operator<<(ostream& out,
                               const DataBuffer<U>& buf);

    };


template <typename U>
ostream& operator<<(ostream& out, const DataBuffer<U>&buf)
{
    out<<"[";
    for(int i=0; i<buf.count; i++){
        int index=(buf.head+i)% buf.capacity;

        if constexpr(is_same_v<U, string>)
        {
            out<<"\""<<buf.data[index]<<"\"";
        }else{
            out<<buf.data[index];
        }
        if(i<buf.count -1){
            out<<",";
        }
    }
    out<<"]";
    return out;
}




int main(){

    cout<<"====Part A===="<<endl;


    vector<DataProcessor*> pipeline;

    pipeline.push_back(new CSVProcessor());
    pipeline.push_back(new SensorStreamProcessor());

    for(auto * p: pipeline){
        p->loadData("source_data");
        p->processData();
        p->printSummary();
        p->exportResult("output_dir");
        cout<<"---"<<endl;
    }

    // DataProcessor dp;
    // ERROR: It is Pure virtual Class known as abstract class so its objecty Cannot be Created 
    for(auto *p: pipeline){
        delete p;
    }



    cout<<"======Part B======"<<endl;

    DataBuffer<int>tickBuffer(5);
    for(int i=1; i<=7; i++){
        tickBuffer.push(i*10);
    }

    cout<<"Tick Buffer: "<<tickBuffer<<endl;

    DataBuffer<double>tempBuffer(4);

    tempBuffer.push(36.6);
    tempBuffer.push(37.1);
    tempBuffer.push(38.2);
    tempBuffer.push(36.9);

    cout<<endl;
    cout<<"Before pop: "<<tempBuffer<<endl;
    cout<<"popped: "<<tempBuffer.pop()<<endl;
    cout<<"After Pop: "<<tempBuffer<<endl;
     

    DataBuffer<string> logBuffer(3);

     logBuffer.push("INFO: Server started");
    logBuffer.push("WARN: High memory usage");
    logBuffer.push("ERROR: DB connection timeout");
     logBuffer.push("INFO: Retry successful");
     cout<<endl;

     cout<<"Log Buffer: "<<logBuffer<<endl;
   
     return 0;
}