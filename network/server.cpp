#include <iostream>
#include <cstring>

extern "C" {
    #include <enet/enet.h>
}

#include "network.hpp"

void sendMessage(ENetPeer * to, const char* message){
    ENetPacket* packet = enet_packet_create(message, sizeof(message) + 1, ENET_PACKET_FLAG_RELIABLE);
    enet_peer_send(to, 0, packet);

}

void* startServer(void* arg){

    ENetAddress address;
    ENetHost* server;

    // clients[0] == Main client
    ENetPeer* clients[2] = {nullptr, nullptr};
    int connectedClients = 0;

    address.host = ENET_HOST_ANY;
    address.port = 1234;

    server = enet_host_create(&address, 32, 2, 0, 0);
    if (!server) {
        std::cerr << "Server creation failed.\n";
        return NULL;
    }

    std::cout << "Server started.\n";


    while (true) {
        ENetEvent event;
        while (enet_host_service(server, &event, 1000) > 0) {
            switch (event.type) {
                case ENET_EVENT_TYPE_CONNECT:
                    std::cout << "Client connected.\n";
                    
                    if (connectedClients < 2){
                        if (connectedClients == 0){ // If the player is the first one joining the server
                            char * query = "A 10 18 C"; // Add at (10, 18) a Castle
                            ENetPacket* packet = enet_packet_create(
                            query,
                            str_len(query),
                            ENET_PACKET_FLAG_RELIABLE // or whatever flag the original used
                            );
                            enet_peer_send(clients[conncetedClients], 0, packet);
                        }
                        else{ // If the player is the second one

                        }
                        clients[connectedClients++] = event.peer;
                    }
                    else{
                        std::cout << "Trop de clients connecté.\n";
                        enet_peer_disconnect(event.peer, 0);
                    }

                    break;
                case ENET_EVENT_TYPE_RECEIVE:
                    //std::cout << "Received: " << event.packet->data << "\n";

                    // Send the packet data to the other client
                    for (int i = 0; i < 2; i++){
                        if (clients[i] != event.peer && clients[i] != nullptr){
                            ENetPacket* packet = enet_packet_create(
                            event.packet->data,
                            event.packet->dataLength,
                            ENET_PACKET_FLAG_RELIABLE // or whatever flag the original used
                        );
                        enet_peer_send(clients[i], 0, packet);

                        }
                    }

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

    return NULL;
}

