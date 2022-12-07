# nrf_802154_rxclient

Simple project to indicate issue with receiving 802.15.4 data on nrF5340DK. Initially based upon echo client sample project https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.2/zephyr/samples/net/sockets/echo_client/README.html

Built using VS Code, nrf Connect SDK versions 2.1.2 & 2.2.0rc show the issue 
"<err> ieee802154_nrf5: Packet dropped by NET stack" is shown whenever a packet is sent from another device on the same channel

Example project to send Hello world is here https://github.com/richardpike/nrf_802154_tx_HW
