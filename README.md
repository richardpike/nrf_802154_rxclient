# nrf_802154_rxclient

Simple project to indicate issue with receiving 802.15.4 data on nrF5340DK. Initially based upon echo client sample project

Built using VS Code, nrf Connect SDK versions 2.1.2 & 2.2.0rc show the issue 
"<err> ieee802154_nrf5: Packet dropped by NET stack" is shown whenever a packet is sent from another device on the same channel
