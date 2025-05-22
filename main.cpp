#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <pthread.h>

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
        
        // Launch the server on a thread then launch the client
        pthread_t serverThread;
        if (pthread_create(&serverThread, NULL, startServer, NULL) != 0){
            fprintf(stderr, "Erreur lors de la création du thread du serveur\n");
            exit(EXIT_FAILURE);
        }
        

        startClient();
         
        // Join
        if( pthread_join(serverThread, NULL) != 0){
            fprintf(stderr, "Erreur lors du join du thread du serveur\n");
            exit(EXIT_FAILURE);
        }
        return 0;
    }
    else{
        
        // Launch the client
        startClient();
        return 0;
    }
    return 0;
}   
