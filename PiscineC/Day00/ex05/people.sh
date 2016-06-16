ldapsearch -xLLL "uid=z*" | grep "^cn" | sort -rf | cut -c5-
