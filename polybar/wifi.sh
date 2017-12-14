#!/bin/bash

#VPN="$(sudo service openvpn status)"
#    VPN="$VPN"
#if [ "$VPN" == " * status: started" ]; then
#    printf " " 
#fi
colorwifi=%{F#F5B0B1}
WIFI=$(iwgetid -r)
    WIFI="$WIFI"
if [ "$WIFI" == "" ]; then
    WIFI=" Not connected!"
else
    WIFI="$colorwifi %{F#D0D0D0}$WIFI"
fi
color=D0D0D0
#echo "%{F#e19bff} $WIFI"
echo "%{F$color}$WIFI"
