//NAME : Nauman Nasir
//ROLL # P13-6020 CS-15A
//Algo Assignment : 1

#include<iostream>

using namespace std;

int length(int num){
    int val = 0;
    for(;num > 0;){
        val++;
        num = num/10;
    }

    return val;
}

int power(int val, int num) {
    int result = 1;
    for(int i=1; i<=num; i++){
        result *= val;
    }

    return result;
}

int recursion(int val1, int val2) {

    int arr1[2] = {0},arr2[2] = {0},divisor,result[4] = {0},ans[3] = {0};

    if(val1 > val2) {
        if(val1 % 2 == 0) {
            divisor = power(10, length(val1)/2);
        }
        else {
            divisor = power(10, ((length(val1)-1)/2) + 1);
        }
    }
    else {
        if(val2 % 2 == 0) {
            divisor = power(10, length(val2)/2);
        }
        else {
            divisor = power(10, ((length(val2)-1)/2) + 1);
        }
    }

    arr1[0] = val1 / divisor;
    arr1[1] = val1 % divisor;

    arr2[0] = val2 / divisor;
    arr2[1] = val2 % divisor;

    cout<<"= Divisor = "<<divisor<<endl;
    cout<<"= ARR one = "<<arr2[0]<<" : "<<arr2[1]<<endl;
    cout<<"= ARR two = "<<arr1[0]<<" : "<<arr1[1]<<endl<<endl;

    if(length(arr1[1]) > 1 || length(arr2[1]) > 1){
        result[3] = recursion(arr1[1],arr2[1]);
    }
    else {
        result[3] = arr1[1] * arr2[1];
    }

    if(length(arr1[1]) > 1 || length(arr2[0]) > 1){
        result[2] = recursion(arr1[1],arr2[0]);
    }
    else {
        result[2] = arr1[1] * arr2[0];
    }

    if(length(arr1[0]) > 1 || length(arr2[1]) > 1){
        result[1] = recursion(arr1[0],arr2[1]);

    }
    else {
        result[1] = arr1[0] * arr2[1];
    }

    if(length(arr1[0]) > 1 || length(arr2[0]) > 1){
        result[0] = recursion(arr1[0],arr2[0]);
    }
    else {
        result[0] = arr1[0] * arr2[0];
    }

    ans[2] = result[3] % divisor;
    ans[1] = result[2] + result[1] + (result[3] / divisor);
    ans[0] = result[0] + (ans[1] / divisor);
    ans[1] = ans[1] % divisor;

    return (ans[0]*divisor*divisor) + (ans[1]*divisor) + ans[2];
}


int main(){

    int  num1, num2;
    char turns = 'y';

    cout<<" == DIVIDE & CONQUER =="<<endl;
    cout<<"    ================"<<endl<<endl;

    for(;turns != 'n';){
        cout<<"\n\nEnter 1st Number : ";cin>>num1;
        cout<<"Enter 2nd Number : ";cin>>num2;cout<<endl;

        cout<<"Final Product = "<<recursion(num1,num2);
        cout<<endl<<"^^^^^^^^^^^^^"<<endl<<endl;
        cout<<"Multiply Again ? (y/n) :";cin>>turns;
    }

    return 0;
}
