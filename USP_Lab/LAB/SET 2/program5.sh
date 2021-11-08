echo 'Enter the Positive Number'
fact=1
read n
for (( i=1; i<=$n; i++ ))
do
fact=$((fact*i))
done
echo "The factorial of $n is $fact"
