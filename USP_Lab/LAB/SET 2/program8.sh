echo "Enter the two numbers"
read x y
echo "ADD: $x + $y = ";echo $x + $y |bc
echo "SUB: $x - $y = ";echo $x - $y |bc
echo "MUL: $x * $y = ";echo $x \* $y |bc
echo "DIV: $x / $y = ";echo "scale=3;$x / $y" |bc
echo "MOD: $x % $y = ";echo $x % $y |bc
