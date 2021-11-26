#include<iostream>
#include<ctime>
#include<cstdlib>

int main(){
    int nf,N;
    int no_tr=0;
    srand(time(NULL));

    std:: cout << "Enter the number of frames: ";
    std:: cin >> nf;
    
    std:: cout << "Enter the Window Size: ";
    std:: cin >> N;

    int i=0;
    
    while(i< nf){
        int x= 0;
        
        for(int j= i; j< i+N && j< nf; j++){
            std:: cout << "Sent Frame " << j << std:: endl;
            no_tr++;
        }

        for(int j= i; j< i+N && j< nf; j++){
            int flag = rand()%2;
            if(!flag){
                    std:: cout << "Acknowledgment for Frame " << j << std:: endl;
                    x++;
                }
            else{   
                    std:: cout << "Frame " << j << " Not Received" << std:: endl;
                    std:: cout << "Retransmitting Window" << std:: endl;
                    break;
                }
        }
        std:: cout << std:: endl;
        i+= x;
    }
    std:: cout << "Total number of transmissions : " << no_tr << std:: endl;

return 0;
}