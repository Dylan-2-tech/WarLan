#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <thread>

extern "C" {
    #include <enet/enet.h>
}

#include "network/network.hpp"


int main(void) {
    
    if (enet_initialize() != 0) {
        std::cerr << "ENet initialization failed.\n";
        return 1;
    }

    atexit(enet_deinitialize);

    char answer;
    do{
        // Asks the player if it's a server or a client
        printf("Are you server or client ? (s/c): ");
        std::cin >> answer;
        while((getchar()) != '\n'); // skips every other chars
    }while(answer != 's' && answer != 'c');
    
    // Initialize the server if the player has choosed server
    if (answer == 's'){
        
        pthread_t serverThread;


        // Launch the server on a thread then launch the client
        startServer();

        startClient();
        return 0;
    }
    else{
        
        // Launch the client
        startClient();
        return 0;
    }
    return 0;
}   
