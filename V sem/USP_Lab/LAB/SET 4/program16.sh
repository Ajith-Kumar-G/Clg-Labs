echo -e "Enter the name of file:\c"
read fname
echo -e " Lines = `wc -l < $fname` \n Words = `wc -w < $fname` \n Characters = `wc -m < $fname` "
