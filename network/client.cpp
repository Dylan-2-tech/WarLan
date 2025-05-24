#include <iostream>
#include <cstring>
#include <string>
#include "map.hpp" 

extern "C" {
    #include <enet/enet.h>
}

#include "network.hpp"

void startClient(int j){

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
    /* Wait up to 5 seconds for the connection attempt to succeed. */
    ENetEvent event = {};
    if (enet_host_service(client, &event, 5000) > 0 &&
        event.type == ENET_EVENT_TYPE_CONNECT)
    {
        std::cout << "Got a connection!\n";
        // Map du jouer/client
        Map * map = new Map;
         
        if(j == 0){ // If the player is the host of the game
            
            // Adding the Castle and the farmer
            map->AddPawn('C', 10, 19);
            map->AddPawn('F', 10, 17);
        }
        else{ // If the player has joined the game
     
            // Adding the Castle and the farmer
            map->AddPawn('C', 10, 3);
            map->AddPawn('F', 10, 5);       
        }


        while (true)
        {

            ENetEvent event;
            /* Wait up to 10 milliseconds for an event. */
            while (enet_host_service(client, &event, 10) > 0)
            {
                switch (event.type)
                {
                case ENET_EVENT_TYPE_CONNECT:
                break;

                case ENET_EVENT_TYPE_RECEIVE: // If the server has sent actions
                    // Determine the action to do
                        std::cout << event.packet->data;
                    
                break;

                case ENET_EVENT_TYPE_DISCONNECT:
                    std::cout << "Server Disconected\n";
                    break;
                }
            }
            
            //#### Actions that the player has to do ####
            
            for (auto &pawn : map->_pawns){ // For every pawn
                
                // Ask the position where to move the pawn
                int x,y;
                // Moves the pawn
                do{
                std::cout << "Entrez la position (xy):";
                std::cin >> x >> y;
                }while(!map->MovePawn(pawn, x, y));

                // Send to the server the action played by the player
                std::string str_action = "M "+to_string(pawn->getPosition().x)+" "+ to_string(pawn->getPosition().y)+" "+
                to_string(x)+" "+to_string(y);
                
                sendMessage(peer, str_action.c_str());
            }
        }
    }
    else
    {
        std::cout << "Wasn't able to connect\n";
    }

    enet_peer_reset(peer);
    enet_host_destroy(client);
    return;
}

