#ifndef NETWORK_HPP_2727
#define NETWORK_HPP_2727

extern "C" {
    #include <enet/enet.h>
}

// Launch the server
void startServer(void);

// Launch the client
void startClient(void);


#endif // NETWORK_HPP_2727
