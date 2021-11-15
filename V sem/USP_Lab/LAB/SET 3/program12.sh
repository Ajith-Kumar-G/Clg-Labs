echo "Enter the range number"
read n
sum=0
for (( i=0;i<=n;i++))
do
	sum=$((sum+i))
done
echo "The sum of natural numbers up to $n is $sum"
