#include <iostream>
#include <cstring>

extern "C" {
    #include <enet/enet.h>
}

#include "network.hpp"

void startClient(void){

    ENetHost* client = enet_host_create(nullptr, 1, 2, 0, 0);
    if (!client) {
        std::cerr << "Client creation failed.\n";
        return;
    }

    ENetAddress address;
    enet_address_set_host(&address, "127.0.0.1");
    address.port = 1234;

    ENetPeer* peer = enet_host_connect(client, &address, 2, 0);
    if (!peer) {
        std::cerr << "Connection failed.\n";
        return;
    }

    ENetEvent event;
    if (enet_host_service(client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
        std::cout << "Connected to server.\n";

        const char* msg = "Hello from C++ client!";
        ENetPacket* packet = enet_packet_create(msg, std::strlen(msg) + 1, ENET_PACKET_FLAG_RELIABLE);
        enet_peer_send(peer, 0, packet);
        enet_host_flush(client);
    } else {
        std::cerr << "Could not connect to server.\n";
    }

    enet_host_destroy(client);
    return;
}

