passed=0;failed=0
for (( i=1;i<=6;i++ ))
do
	echo -e "Enter the CIE(out of 50) and SEE(out of 100) marks for sub-$i : \c"
	read cie see
	total=`echo "$cie + ($see / 2)"|bc`
	echo "Total = $total" 
	case $total in
	100) echo  "S grade";passed=$((passed+1));;
	9[0-9]) echo "S grade";passed=$((passed+1));;
	8[0-9]) echo "A grade";passed=$((passed+1));;
	7[0-9]) echo "B grade";passed=$((passed+1));;
	6[0-9]) echo "C grade";passed=$((passed+1));;
	5[0-9]) echo "D grade";passed=$((passed+1));;
	4[0-9]) echo "E grade";passed=$((passed+1));;
	[0-3][0-9]) echo "F grade";failed=$((failed+1));;
	*) echo "Error inputs, check again!"
	esac
done
echo "Total passed = $passed and Total falied=$failed"
	
