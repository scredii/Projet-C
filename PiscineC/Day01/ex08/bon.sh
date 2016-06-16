ldapsearch -Q "sn=*BON*" | grep -i sn: | wc -l | sed "s/ //g"
