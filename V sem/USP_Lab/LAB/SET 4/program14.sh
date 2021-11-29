echo "Enter Range:"
read a
i=0
j=1
echo -e "Series is :\c"
while [ $a -ge 0 ]
do
	echo  -e "$i \c"
	t=$i
	i=$((i+j))
	j=$((t))
	a=$((a-1))
done
echo -e "\n"
