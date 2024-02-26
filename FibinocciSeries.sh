echo "enter the limit:"
read n
echo -e "Fibinocci Series:"
a=0
b=1
echo -e "$a \n$b"
for((i=1;i<=$(($n-2));i++))
do
c=$(($a+$b))
echo -e "$c"
a=$b
b=$c
done
