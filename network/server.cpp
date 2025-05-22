#include <iostream>
#include <cstring>

extern "C" {
    #include <enet/enet.h>
}

#include "network.hpp"

void startServer(void){

    ENetAddress address;
    ENetHost* server;

    address.host = ENET_HOST_ANY;
    address.port = 1234;

    server = enet_host_create(&address, 32, 2, 0, 0);
    if (!server) {
        std::cerr << "Server creation failed.\n";
        return;
    }

    std::cout << "Server started.\n";


    while (true) {
        ENetEvent event;
        while (enet_host_service(server, &event, 1000) > 0) {
            switch (event.type) {
                case ENET_EVENT_TYPE_CONNECT:
                    std::cout << "Client connected.\n";
                    break;
                case ENET_EVENT_TYPE_RECEIVE:
                    std::cout << "Received: " << event.packet->data << "\n";
                    enet_packet_destroy(event.packet);
                    break;
                case ENET_EVENT_TYPE_DISCONNECT:
                    std::cout << "Client disconnected.\n";
                    break;
                default:
                    break;
            }
        }
    }

    enet_host_destroy(server);
}

