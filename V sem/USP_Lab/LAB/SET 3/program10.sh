echo "Given Numbers: 123"
list=(1 2 3)
for i in ${list[*]}
do
	for j in ${list[*]}
	do
		for k in ${list[*]}
		do
			echo $i $j $k
		done
	done
done
