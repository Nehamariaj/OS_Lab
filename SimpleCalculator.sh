echo "Enter 2 numbers"
read num1
read num2
echo -e "Which Operation to perform \n1.Addition 2.Subtraction 3.Multiplication 4.Division \nEnter Choice:" 
read ch
case $ch in
1) echo "Sum=$(($num1+$num2))";;
2) echo "Difference=$(($num1-$num2))";;
3) echo "Product=$(($num1*$num2))";;
4) echo "Quotient=$(($num1/$num2))";;
*) echo "Wrong choice";;
esac
