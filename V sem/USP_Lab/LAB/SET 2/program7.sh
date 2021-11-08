echo "Enter the Temperature in fahrenheit"
read f
c=`echo "scale=3;($f - 32)*(5/9)"|bc`
echo "The $f f in celsius is $c"
