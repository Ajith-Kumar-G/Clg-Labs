echo "Enter the Basic Salary"
read bS
DA=`echo "scale=3;$bS * 10 / 100"|bc`
hra=`echo "scale=3;$bS * 20 / 100"|bc`
gross_salary=`echo "scale=3;$bS + $DA + $hra" |bc`
echo "The Gross salary is $gross_salary"
echo "Others: Da=$DA and HRA=$hra"
