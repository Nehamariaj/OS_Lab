echo "Enter a number"
read num
a=1
for((i=1;i<=$num;i++))
do
a=$(($a*$i))
done
echo "Factorial of $num=$a"
