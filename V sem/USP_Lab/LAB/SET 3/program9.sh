echo "Enter the range number"
read n
sum=0
for (( i=0;i<=n;i=i+2 ))
do
	sum=$((sum+i))
done
echo "The sum of even numbers up to $n is $sum"
