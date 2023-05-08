#include <iostream>
#include <string>

using namespace std;
string crc(string data, string poly){
    int i = 0;
    while(i != data.size() - poly.size() +1){
        if(data[i] == '0'){
            i++;
        }
        else{
            for(int j=0;j<poly.size();j++){
                if(data[i+j] == poly[j])
                data[i+j]='0';
                else
                data[i+j]='1';
            }
            
        }
    }
    string crc_bits;
    for(int j=i;j<data.size();j++){
        crc_bits.push_back(data[j]);
    }
    return crc_bits;
}
bool receive(string recv,string poly){
    string rem = crc(recv,poly);
    for(int i=0;i<rem.size();i++){
        if(rem[i]=='1')
        return false;
    }
    return true;
}
int main(){
    string data,polynomial;
    //take the data string as input
    cout << "\nEnter the data to be transmitted: ";
    cin >> data;
    //take the generating polynomial as input
    cout<< "\nEnter the generating polynomial in bit format: ";
    cin >> polynomial;
    while(polynomial[0] == '0'){
        polynomial.erase(polynomial.begin());
        if(polynomial.size() == 0){
            cout<< "\nThe generating polynomial must be non zero\n";
            cout<< "\nExiting the code\n";
            return 0;
        }
    }
    //append n-k zeros at end of the data (where length of gen_poly is n-k+1)
    int n = polynomial.size();
    string data1=data;
    for(int i=0;i<n-1;i++){
        data1.push_back('0');
    }
    cout<< "---------------------------------------\n";
    cout<< "Data padded with n-1 zeros: " << data1 << "\n";
    cout << "---------------------------------------\n";

    string crc_bits = crc(data1,polynomial);

    cout<< "The CRC bits are: " << crc_bits << "\n";
    cout << "---------------------------------------\n";

    data+=crc_bits;

    cout<< "\nThe final data to be sent: "<<data;
    cout<<"\n----------------------------------------";

    string rece;
    cout<<"\nEnter the received data: ";
    cin>>rece;
    if(receive(rece,polynomial))
    cout<<"\nNo Error detected, hence frame accepted\n\n";
    else cout<<"\nError detected, hence frame rejected\n\n";
    return 0;
}