echo 'Enter a Number'
fact=1
read n
if test $n -lt 0
then
  echo "$n should be Whole number!!"
  exit 1
fi
for (( i=1; i<=$n; i++ ))
do
fact=$((fact*i))
done
echo "The factorial of $n is $fact"
