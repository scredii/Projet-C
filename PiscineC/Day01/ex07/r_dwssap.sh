cat /etc/passwd | grep -v "^#" | cut -d ":" -f1 | sed -n 'n;p' | rev | sort -r | awk "(NR >= $FT_LINE1 && NR <= $FT_LINE2)" | tr -d "\n" | sed "s/_/_, /g" | sed "s/, $/./" 
