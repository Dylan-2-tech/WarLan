#ifndef NETWORK_HPP_2727
#define NETWORK_HPP_2727

extern "C" {
    #include <enet/enet.h>
}

// Launch the server
void* startServer(void *arg);

// Launch the client
void startClient(void);

// Send a Message to the server
void sendMessage(ENetPeer* to, const char * message);


#endif // NETWORK_HPP_2727
