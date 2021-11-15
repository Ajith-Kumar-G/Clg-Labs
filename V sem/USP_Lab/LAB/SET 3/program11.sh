echo "Enter the Number and its power :"
read n p
ans=1
for ((i=p;i>0;i--))
do
	ans=`echo "scale=3;$ans * $n" |bc`
done
echo "$n to power $p is $ans"
